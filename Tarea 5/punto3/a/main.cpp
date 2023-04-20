
#include "lista.h"

void insertarEnListaOrdenada(Lista &l, int v){
	if (l.vaciaLista()){
		l.anxLista( v );
	} else {
		int i = 1;
        int ans = l.longLista();
		while ( i <= ans && v > l.infoLista(i) ){
			++i;
		}
		if ( i <= ans ){
			l.insLista(v, i);
		} else {
			l.anxLista( v );
		}
	}
}


int main(){
  Lista lista;
  lista.anxLista(6);
  lista.anxLista(2);
  lista.anxLista(4);
  lista.anxLista(5);
  lista.anxLista(62);
  lista.anxLista(24);
  insertarEnListaOrdenada(lista, 10);
  return 0;
}

