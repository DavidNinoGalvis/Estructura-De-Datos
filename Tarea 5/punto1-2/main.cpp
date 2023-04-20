#include "lista.h"


int contarOcurrencias(Lista l, int v){
    int count = 0;
    int longitud = l.longLista();
    for(int i = 1; i <= longitud;i++){
        if(l.infoLista(i) == v){
            count++;
        }
    }
    return count;
}

Lista obtenerMenores(Lista l, int v){
    Lista ans;
    int ln;
    int len = l.longLista();
    for(int i = 1; i <= len;i++){
        ln = l.infoLista(i);
        if(ln < v){
            ans.anxLista(ln);
        }
    }
    return ans;
}


int main(){
	Lista l = Lista();
	l.anxLista(20);
	l.anxLista(4);
	l.anxLista(5);
	l.anxLista(6);
	l.anxLista(1);
	l.anxLista(24);
	int j = contarOcurrencias(l, 6);
	printf("\nLas ocurrencias del 10 han sido %d\n\n", j );
	Lista menoresA11 = obtenerMenores(l, 7);
	printf("\nLos menores a 7:\n");
	return 0;
}
