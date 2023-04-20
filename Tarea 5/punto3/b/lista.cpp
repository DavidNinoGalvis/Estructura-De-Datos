#include "lista.h"

Lista::Lista(){
  act = NULL;
}

void Lista::insListaOrdenada(Elemento elem){
   Nodo* tmp;
   Nodo* nuevo;
   int flag1 = 0;
  if(vaciaLista()){
    Nodo* nuevo = new Nodo;
    nuevo->dato = elem;
    nuevo->sig = NULL;
    act = nuevo;
  }
  else if(elem < act->dato){
    Nodo* nuevo = new Nodo;
    nuevo->dato = elem;
    nuevo->sig = act;
    act = nuevo; // Se agrega esta línea para actualizar act al nuevo nodo
  }
  else{
    tmp = act;
    nuevo = tmp;
    while(tmp != NULL && flag1 == 0){
      if(tmp->dato >= elem){
        Nodo* actual = new Nodo;
        actual->dato = elem;
        nuevo-> sig = actual;
        actual->sig = tmp;
        flag1 = 1;
      }
      nuevo = tmp;
      tmp = tmp->sig;
    }
    if(tmp == NULL){
        Nodo* actual = new Nodo;
        actual->dato = elem;
        nuevo->sig = actual;
        actual->sig = NULL;
    }    
  }
}


void Lista::elimLista(int pos){
  Nodo *tmp, *elim;
  if(pos >= 1 && pos <= longLista()){
    if(pos == 1){
      act = act->sig;
    } else {
      tmp = act;
      int i = 0;
      while(i < pos-2){
        tmp = tmp->sig;
        i++;
      }
      elim = tmp->sig;
      tmp->sig = tmp->sig->sig;
      delete elim;
    }
  }
}

Elemento Lista::infoLista(int pos){
  Nodo* tmp = act;

  for(int i = 1; i < pos; i++)
    tmp = tmp->sig;

  return tmp->dato;
}

int Lista::longLista(){
  Nodo* tmp = act;
  int cont = 0;

  while(tmp != NULL){
    tmp = tmp->sig;
    cont++;
  }

  return cont;
}

bool Lista::vaciaLista(){
  return act == NULL;
}