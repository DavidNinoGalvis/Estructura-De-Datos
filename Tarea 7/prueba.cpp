#include <list>
#include <string>
#include <stack>
#include <iostream>
#include <queue>
#include <map>

using namespace std;

void imprimirPila(stack<int> pil){
  cout << "Contenido de la pila: ";
  
  while (!pil.empty()) {
    cout << pil.top() << " ";
    pil.pop();
  }
  cout << endl;
}

void imprimirLinkedList(const list<int>& linkedList) {
    cout << "Contenido De La Lista Auxiliar" << endl;
    for (const auto& elemento : linkedList) {
        cout << elemento << " ";
    }
    cout << endl;
}

void eliminarPosicionesPila(stack<int> &pil, list<int> &l) {
    /* La Complejidad de realizar esta implementación es de N, ya que debemos recorrer toda la lista auxiliar 1 vez
    Mientras vamos eliminando los elementos deseados*/
    list<int> aux;
    while(!pil.empty()){
        aux.push_front(pil.top());
        pil.pop();
    }
    list<int>::iterator it = aux.begin();
    list<int>::iterator l_position = l.begin();
    int contador = 0;
    while(it != aux.end()){
        if (contador == *l_position){
            *it = INT_MIN;
            l_position++;
        }
        else {
            contador++;
            it++;
        }
    }
    for(it = aux.begin();it != aux.end();it++){
        if (*it != INT_MIN)
            pil.push(*it);
    }
}

string verificarOrdenadoCola(queue<int> cola){
    string ans;
    bool flag = true;
    int primeritem = cola.front();
    cola.pop();
    if(primeritem > cola.front()){
        primeritem = cola.front();
        cola.pop();
        while(!cola.empty() && flag){
            if(primeritem <= cola.front())
                flag = false;
            else{
                primeritem = cola.front();
                cola.pop();
            }
        }
        if(cola.empty())
            ans = "Menor a mayor";
        else
            ans = "Los numeros no tiene orden";
    }
    else if(primeritem > cola.front()){
        primeritem = cola.front();
        cola.pop();
        while(!cola.empty() && flag){
            if(primeritem >= cola.front())
                flag = false;
            else{
                primeritem = cola.front();
                cola.pop();
            }
        }
        if(cola.empty())
            ans = "Mayor a menor";
        else
            ans = "Los numeros no tiene orden";
    }
    else
        ans = "Los numeros no tiene orden";
    return ans;
}

bool verificarRepetidosCola(queue<int> cola){
    /* La complejidad de realizar esta implementación, consiste en el peor de los casos nLogN que es lo que consume al realizar busquedas
    decidí implementar un mapa debido a que podria realizar busquedas en tiempo constante para saber si algun elemento esta repetido*/
	map<int, bool> cantidades;
	map<int,bool>::iterator mapValue;
    bool flag = false;
	while (!flag && !cola.empty() ){
		mapValue = cantidades.find( cola.front() );
		if (mapValue != cantidades.end() ){
			flag = true;
		} else{
			cantidades.insert(pair< int, bool > ( cola.front(), false ) );
		}
		cola.pop();
	}
	return flag;
}


int main(){
    /* MAIN EJERCICIO 1
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
    */
    /*queue<int> cola;
    cola.push(1);
    cola.push(2);
    cola.push(3);
    cola.push(4);
    cout << verificarOrdenadoCola(cola) << endl;*/
   return 0;
}