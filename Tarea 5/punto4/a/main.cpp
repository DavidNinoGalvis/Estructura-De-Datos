#include "lista.h"
#include <iostream>

void concatenarListas(Lista &lista, Lista &listaSecond){
    int lenList = listaSecond.longLista();
    int i = 1;
    for(i = 1; i <= lenList; i++){
        lista.anxLista(listaSecond.infoLista(i));
    }
}

int main(){
  Lista lista;
  lista.anxLista(1);
  lista.anxLista(2);
  lista.anxLista(3);
  lista.anxLista(4);
  lista.anxLista(5);
  lista.anxLista(6);
  lista.anxLista(7);
  lista.anxLista(8);

  Lista listaSecond;
  listaSecond.anxLista(9);
  listaSecond.anxLista(10);
  listaSecond.anxLista(11);
  listaSecond.anxLista(12);
  listaSecond.anxLista(13);
  listaSecond.anxLista(14);
  listaSecond.anxLista(15);
  listaSecond.anxLista(16);


  concatenarListas(lista, listaSecond);
  /// No se si se considere un error que al concatenar se quede en la lista1, por lo que perderiamos informacion
  for(int i = 1; i <= lista.longLista(); i++)
    cout << lista.infoLista(i) << endl;
}