#include <list>
#include <string>
#include <stack>
#include <iostream>
#include <queue>
#include <map>

using namespace std;

/* FUNCION AUXILIAR PARA PRUEBAS DE EJERCICIOS*/
void imprimirPila(stack<int> pil){
  cout << "Contenido de la pila: ";
  
  while (!pil.empty()) {
    cout << pil.top() << " ";
    pil.pop();
  }
  cout << endl;
}

/* FUNCION AUXILIAR PARA PRUEBAS DE EJERCICIOS*/
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
        if (*it != INT_MIN) /*Intenté realizarlo de otra manera pero me fallaba, por lo que tuve que utilizar esta variable para identificar los que
        no debia guardar en la pila de nuevo, creo que hay una manera mas eficiente para este procedimiento*/
            pil.push(*it);
    }
}

void obtenerMenorCosto(list<int>& l) {
    /* Esta implementacion tiene una complejidad de O(n) debido a que solo es necesario recorrerlo 1 sola vez
    la lista, al realizar el sort al inicio del ejercicio que tiene una complejidad de LogN*/
    l.sort();
    int costo = 0;
    int suma = 0;
    list<int>::iterator it;
    for (it = l.begin(); it != l.end(); ++it) {
        costo += suma;
        suma += *it;
    }

    cout << costo;
}

string verificarOrdenadoCola(queue<int> cola){
    /*La complejidad de esta implementacion es O(n) donde n es el numero de elementos que posee la cola, ya que por medio del
    ciclo la recorremos 1 sola vez completamente verificando la posicion y la siguiente para identificar el tipo de ordenamiento*/
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
	map<int,bool>::iterator valoresmap;
    bool flag = false;
	while (!cola.empty() && !flag){
		valoresmap = cantidades.find(cola.front());
		if (valoresmap != cantidades.end() ){
			flag = true;
		} else{
			cantidades.insert({cola.front(), false});
		}
		cola.pop();
	}
	return flag;
}


stack<int> filtrarNParesCola(queue<int> col,int n){
    /* La complejidad de esta implementacion es O(n) donde n es el numero de elementos de la cola
    debido a que creo una linkedlist auxiliar para que almacene los elementos de la cola y solo agregue a la pila los deseados*/
    list<int> aux;
    stack<int> ans;
    while(!col.empty()){
        aux.push_back(col.front());
        col.pop();
    }
    imprimirLinkedList(aux);
    list<int>::iterator it = aux.begin();
    int count = 0;
    while (count < n*2){
        cout << *it << endl;
        if (*it % 2 == 0) 
            ans.push(*it);
            count++;
        it++;
    }
    return ans;
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
    /*=============== MAin Ejercicio 10 ===================*/
    // queue<int> pares;
    // int n = 2;
    // pares.push(1);
    // pares.push(2);
    // pares.push(3);
    // pares.push(4);
    // pares.push(5);
    // pares.push(6);
    // pares.push(7);
    // pares.push(8);
    // pares.push(9);
    // pares.push(10);
    // imprimirPila(filtrarNParesCola(pares,));
    return 0;

}