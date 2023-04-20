#include "lista.h"
#include <iostream>

int main(){
  Lista lista;
  lista.insListaOrdenada(2);
  lista.insListaOrdenada(1);
  lista.insListaOrdenada(5);
  lista.insListaOrdenada(7);
  lista.insListaOrdenada(3);
  cout << "Ejemplo ListaOrd." << endl << endl;
  for(int i = 1; i <= lista.longLista(); i++){
		cout << lista.infoLista(i) << endl;
	}
  return 0;
}