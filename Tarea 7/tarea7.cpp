#include <list>
#include <stack>
#include <iostream>

using namespace std;

void imprimirPila(stack<int> pil){
  cout << "Contenido de la pila: ";
  
  while (!pil.empty()) {
    cout << pil.top() << " ";
    pil.pop();
  }
  cout << endl;
}

void imprimirLinkedList(const std::list<int>& linkedList) {
    std::cout << "Contenido De La Lista Auxiliar" << endl;
    for (const auto& elemento : linkedList) {
        std::cout << elemento << " ";
    }
    std::cout << std::endl;
}

void eliminarPosicionesPila(stack<int> &pil, list<int> &l) {
    /* La Complejidad de realizar esta implementación es de N, ya que debemos recorrer toda la lista auxiliar 1 vez
    Mientras vamos eliminando los elementos deseados*/
    list<int> aux;
    while(!pil.empty()){
        aux.push_front(pil.top());
        pil.pop();
    }
    imprimirLinkedList(aux);
    imprimirLinkedList(l);
    list<int>::iterator it = aux.begin();
    list<int>::iterator l_position = l.begin();
    int contador = 0;
    while(it != aux.end()){
        if (contador == *l_position){
            aux.remove(*it);
            l_position++;

        }
        else{
            contador++;
            it++;
        }
    }
    for(it = aux.begin();it != aux.end();it++){
        pil.push(*it);
    }
}



int main(){
    stack<int> miPila;
    list<int> posiciones;
    miPila.push(1);
    miPila.push(2);
    miPila.push(3);
    miPila.push(4);
    miPila.push(5);
    miPila.push(6);
    miPila.push(7);
    miPila.push(8);
    miPila.push(9);
    posiciones.push_back(1);
    posiciones.push_back(2);
    posiciones.push_back(3);

    imprimirPila(miPila);
    eliminarPosicionesPila(miPila,posiciones);
    cout << "Pila Transformada" << endl;
    imprimirPila(miPila);
    
   return 0;
}