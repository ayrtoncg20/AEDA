#pragma once
#include "DNI.hpp"

using namespace std;

template <class clave>

class ordenacion_t {
    
    public:
    
    ordenacion_t();
    ~ordenacion_t();
    
    void insercion(clave vector[], int size, int opcion);
    void intercambio_burbuja(clave vector[], int size, int opcion);
    void heapsort(clave vector[], int size, int opcion);
    void heapfy(clave vector[], int size, int i, int opcion);
    void quicksort(clave vector[], int inicio, int final, int opcion, int size);
    void incremento_shellsort(clave vector[], int size, int opcion);
    void deltasort(int delta, clave vector[], int size, int opcion);
    
};

template <class clave>
ordenacion_t<clave>::ordenacion_t(){
    
}

template <class clave>
ordenacion_t<clave>::~ordenacion_t(){
    
}

template <class clave>
void ordenacion_t<clave>::insercion(clave vector[], int size, int opcion){
    
    dni_t elemento_lista;
    int w;
    
    for (int i = 1; i < size; i++){
        elemento_lista = vector[i];
        int j = i - 1;
        if (opcion == 1){
            cout << "ELEMENTOS A COMPARAR -> [ " << vector[j] << ", " << vector[j+1] << " ]" << endl;
        }
        while ((vector[j] > elemento_lista) && (j >= 0)){
            vector[j+1] = vector[j];
            j--;
        }
        vector[j+1] = elemento_lista;
        if (opcion == 1){
            cout << "PASO -> " << i << " -> ";
            cout << "VECTOR -> [ ";
            for (int k = 0; k < size; k++){
                if (k != size -1){
                    cout << vector[k]  << ",";
                }
                else {
                    cout << vector[k] << "";
                }
            }
            cout << " ]" << endl;
        }
    }
    
    //Explicacion: Tenemos la siguiente lista -> 4-3-5-2-1, tomamos el valor del segundo elemento y lo comparamos con el primero, al ser menor,
    //desplazamos el 4 una posicion a la derecha y despues copiamos el 3 en la posicion donde estaba el 4.
    //Creamos un for que vaya desde ese segundo elemento hasta el ultimo, en la variable elemento lista guardamos el valor del segundo elemento, 
    //en la variable j guardamos el elemento anterior al elemento lista. mientras que el elemento del vector que esta en la posicion anterior
    //sea mayor que el elemento de la lista y que sea mayor que 0, entonces guardamos en la posicion  que estaba el elemento lista lo que habia
    //en la posicion anterior y decrementamos en un valor la j. Una vez no haya numeros mayores a la izquierda, salimos del bucle while y guardamos
    //en la siguiente posicion el elemento lista (elemento que estabamos comparando con los demas).
}

template <class clave>
void ordenacion_t<clave>::intercambio_burbuja(clave vector[], int size, int opcion){
    
    dni_t elemento_lista;
    int k;
    
    for (int i = 1; i < size; i++){
        for (int j = 0; j < size - 1; j++){
            if (opcion == 1){
                cout << "ELEMENTOS A COMPARAR -> [ " << vector[j] << ", " << vector[j+1] << " ]" << endl;
            }
            if (vector[j] > vector[j+1]){
                elemento_lista = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = elemento_lista;
            }
            if (opcion == 1){
                cout << "PASO -> " << i << " -> ";
                cout << "VECTOR -> [ ";
                for (int k = 0; k < size; k++){
                    if (k != size -1){
                        cout << vector[k]  << ",";
                    }
                    else {
                        cout << vector[k] << "";
                    }
                }
                cout << " ]" << endl;
            }
        }
    }
    
    //Explicacion: Tenemos la siguiente lista -> 4-3-5-2-1, comenzamos comparando el primer elemento con el segundo, si el primer elemento es 
    //mayor los intercambiamos, ahora el segundo con el tercero, luego el tercero con el cuarto... cuando comparemos el 4 con el quinto, comenzamos
    //de nuevo, la lista se ordenara
}

template <class clave>
void ordenacion_t<clave>::quicksort(clave vector[], int inicio, int final, int opcion, int size){
    
    dni_t elemento_lista;
    int i = inicio;
    int j = final;
    dni_t pivote = vector[(i+j)/2];
    if (opcion == 1){
        cout << "PIVOTE -> " << pivote << endl;
    }
    
    while (i <= j) {
        while (vector[i] < pivote){
            if (opcion == 1){
                cout << "ELEMENTO POR LA IZQUIERDA DEL PIVOTE -> " << vector[i] << endl;
            }
            i++;
        }
        while (vector[j] > pivote){
            if (opcion == 1){
                cout << "ELEMENTO POR LA DERECHA DEL PIVOTE -> " << vector[j] << endl;
            }
            j--;
        }
        if (i <= j){
            elemento_lista = vector[i];
            vector[i] = vector[j];
            vector[j] = elemento_lista;
            
            if (opcion == 1){
                cout << "VECTOR -> [ ";
                for (int k = 0; k < size; k++){
                    if (k != size-1){
                        cout << vector[k]  << ",";
                    }
                    else {
                        cout << vector[k] << "";
                    }
                }
                cout << " ]" << endl << endl;
            }
            i++;
            j--;
        }
    }
        
    if (inicio < j){
        quicksort(vector, inicio, j, opcion, size);
    }
    if (i < final){
        quicksort(vector, i, final, opcion, size);
    }
    
    
    
}

template <class clave>
void ordenacion_t<clave>::heapfy(clave vector[], int size, int i, int opcion){
 
    //largest = 4,3,2,1,0
    int largest = i;  // Initialize largest as root
    //l = 2*4 +1 = 9, 2*3+1 = 7, 5, 3, 1
    //r = 2*4+2 = 10, 8, 6, 4, 2
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    //si 9 es menor que 10 y vector[9] > vector[4]
    if (l < size && vector[l] > vector[largest]){
        largest = l;   
        //largest = 9
    }
    if (r < size && vector[r] > vector[largest]){
        largest = r;
    }
 
    if (largest != i){
        swap(vector[i], vector[largest]);
        heapfy(vector, size, largest, opcion);
    }
    if(opcion == 1) {
        cout << "Banco ACTUALIZADO: [";
		for (int i = 0; i < size; i++) {
			if (i != size-1) 
				cout << vector[i] << ", ";
			else 
				cout << vector[i] << "";
		}
		cout << "]" << endl;
	}
 
}

template <class clave>
void ordenacion_t<clave>::heapsort(clave vector[], int size, int opcion){
 
    //i = 4 a 0
    for (int i = size / 2 - 1; i >= 0; i--){
        //heapfy(vector,10,4,1)
        //heapfy(vector,10,3,1)
        //heapfy(vector,10,2,1)
        //heapfy(vector,10,1,1)
        //heapfy(vector,10,0,1)
        heapfy(vector, size, i, opcion);
    }
 
    for (int i = size-1; i >= 0; i--) {
        swap(vector[0], vector[i]);
        heapfy(vector, i, 0, opcion);
    }
    
    if (opcion == 1){
        cout << "VECTOR -> [ ";
        for (int k = 0; k < size; k++){
            if (k != size-1){
                cout << vector[k]  << ",";
            }
            else {
                cout << vector[k] << "";
            }
        }
        cout << " ]" << endl << endl;
    }
}

template <class clave>
void ordenacion_t<clave>::incremento_shellsort(clave vector[], int size, int opcion){
    
    int delta = size;
    double alfa;
    cout << "INTRODUZCA ALFA: ";
    cin >> alfa;
    while (delta > 1) {
    	delta = delta/2;
    	if (opcion == 1)
    		cout << "Descomposición DELTA: " << delta << endl;
    		//deltasort(5,vector,10,1)
    	deltasort(delta, vector, size, opcion);
    }
	if (opcion == 1){
        cout << "VECTOR -> [ ";
        for (int k = 0; k < size; k++){
            if (k != size-1){
                cout << vector[k]  << ",";
            }
            else {
                cout << vector[k] << "";
            }
        }
        cout << " ]" << endl << endl;
    }
    
}

template <class clave>
void ordenacion_t<clave>::deltasort(int delta, clave vector[], int size, int opcion){
    
    //delta = 5, vector, size = 10, opcion = 1
    dni_t elemento_lista;
	for (int i = delta; i < size; i++) {
		elemento_lista = vector[i];
		//elemento lista = vector[5]
	    //j = 5
		int j = i;
		if (opcion == 1) {
			//Comparamos el elemento 0 con el elemento 5 debido a que dividimos el vector en grupos de 5 para ordernarlo
			cout << "ELEMENTOS A COMPARAR -> [ " << vector[j-delta] << ", " << vector[i] << " ]" << endl;
			cout << endl << endl;
		}
		//j = 6, delta = 5, si el elemento que esta en el elemento lista es menor que el valor que esta en el segundo grupo
		//guardamos en la posicion 
		//j = 4 > 2 elemento lista = 33, < vector[j-delta] = 46
		while ((j >= delta) && (elemento_lista < vector[j-delta])) {
			vector[j] = vector[j-delta];
			//vector[4] = 46
			j = j-delta;
			//j = 4-2 = 2
			//segunda vuelta
			//elemento lista = 33 < vector[2-2] = 34
		}
		vector[j] = elemento_lista;
		
		if(opcion == 1) {
            cout << "VECTOR -> [ ";
		    for (int i = 0; i < size; i++) {
			    if (i != size-1){
				    cout << vector[i] << ",";
			    }
			    else { 
				    cout << vector[i] << "";
			    }
		    }
		    cout << " ]" << endl;
	    }
	}
    
}