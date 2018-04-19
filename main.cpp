#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "DNI.hpp"
#include "ordenacion.hpp"

using namespace std;


int main (void){
    
    int size;
    
    cout << "INTRODUZCA EL TAMAÑO DE LA SECUENCIA A ORDENAR -> ";
    cin >> size;
    cout << endl;
    
    int numero_de_pruebas;
    cout << "INTRODUZCA EL NUMERO DE PRUEBAS QUE DESEA REALIZAR -> ";
    cin >> numero_de_pruebas;
    cout << endl;
    
    int opcion;
    int opcion1;
    int cont_max = 0;
	int cont_min = 999;
	int suma = 0;
	int media;
    
    
    dni_t numero_dni;
    dni_t* vector_dni = new dni_t[25];
    int banco_dni[size];
    char letra_aleatoria;
    int dni_aleatorio;
    ordenacion_t<dni_t> algoritmos_ordenacion;
    int semilla = time(NULL);
    for (int i = 0; i < size; i++){
        banco_dni[i] = rand() % 50000000 + 30000000;
        
        //modificacion
        /*
        banco_dni[0] = 11111;
        banco_dni[1] = 11111;
        banco_dni[2] = 11111;
        banco_dni[3] = 11111;
        banco_dni[4] = 11111;
        banco_dni[5] = 11111;
        banco_dni[6] = 11111;
        banco_dni[7] = 11111;
        banco_dni[8] = 11111;
        banco_dni[9] = 11111;
        */
        
        dni_aleatorio = rand() % 23 + 1;
        letra_aleatoria = "TRWAGMYFPDXBNJZSQVHLCKE"[dni_aleatorio % 23];
        vector_dni[i].set_dni(banco_dni[i]);
        vector_dni[i].set_letra(letra_aleatoria);
        srand(semilla--);
    }
    
     do {
        cout << endl;
        cout << "-------------------MENU-----------------" << endl;
        cout << "- INTRODUCE UN 1 PARA EL MODO DEMOSTRACION" << endl;
        cout << "- INTRODUCE UN 2 PARA EL MODO ESTADISTICA" << endl;
        cout << "- INTRODUCE UN 0 PARA SALIR" << endl;
        cout << "- OPCION -> ";
        cin >> opcion;
        cout << endl;
        
        switch(opcion){
            
            case 1:  do {
				        cout << endl;
				        cout << "-------------------MENU-----------------" << endl;
				        cout << "- INTRODUCE UN 1 PARA EL METODO DE ORDENACION INSERCION" << endl;
				        cout << "- INTRODUCE UN 2 PARA EL METODO DE LA BURBUJA" << endl;
				        cout << "- INTRODUCE UN 3 PARA EL METODO DE ORDENACION HEAPSORT" << endl;
				        cout << "- INTRODUCE UN 4 PARA EL METODO DE ORDENACION QUICKSORT" << endl;
				        cout << "- INTRODUCE UN 5 PARA EL METODO DE ORDENACION SHELLSORT" << endl;
				        cout << "- INTRODUCE UN 6 PARA SALIR" << endl;
				        cout << "- OPCION -> ";
				        cin >> opcion1;
				        cout << endl;
        
				        switch(opcion1){
				            
				            case 1: cout << "**************METODO INSERCION***************" << endl << endl;
				            		cout << "VECTOR DNI -> [ ";
				            		for (int i = 0; i < size; i++){
				            			if (i != size-1){
				            				cout << banco_dni[i] << ", ";
				            			}
				            			else {
				            				cout << banco_dni[i] << "";
				            			}
				            		}
				            		cout << "]" << endl;
				            		algoritmos_ordenacion.insercion(vector_dni,size, opcion);
				            		cout << "**************VECTOR ORDENADO***************" << endl << endl;
				                    break;
				            case 2:	cout << "**************METODO DE LA BURBUJA***************" << endl << endl;
				            		cout << "VECTOR DNI -> [ ";
				            		for (int i = 0; i < size; i++){
				            			if (i != size -1){
				            				cout << banco_dni[i] << ", ";
				            			} else {
				            				cout << banco_dni[i] << "";
				            			}
				            		}
				            		cout << " ]" << endl;
				            		algoritmos_ordenacion.intercambio_burbuja(vector_dni,size, opcion);
				            		cout << "**************VECTOR ORDENADO***************" << endl << endl;
				                    break;
				            case 3:	cout << "**************METODO HEAPSORT**************" << endl << endl;
				        			cout << "VECTOR DNI -> [ ";
				        			for (int i = 0; i < size; i++){
				        				if (i != size - 1){
				        					cout << banco_dni[i] << ", ";
				        				} 
				        				else {
				        					cout << banco_dni[i] << "";
				        				}
				        			}
				        			cout << " ]" << endl;
				            		algoritmos_ordenacion.heapsort(vector_dni, size, opcion);
				        			break;
				        	case 4:	cout << "**************METODO QUICKSORT**************" << endl << endl;
				        			cout << "VECTOR DNI -> [ ";
				        			for (int i = 0; i < size; i++){
				        				if (i != size - 1){
				        					cout << banco_dni[i] << ", ";
				        				} 
				        				else {
				        					cout << banco_dni[i] << "";
				        				}
				        			}
				        			cout << " ]" << endl;
				        			algoritmos_ordenacion.quicksort(vector_dni, 0, size - 1, opcion, size);
				        			break;
				        	case 5:	cout << "**************METODO SHELLSORT**************" << endl << endl;
				        			cout << "VECTOR DNI -> [ ";
				        			for (int i = 0; i < size; i++){
				        				if (i != size - 1){
				        					cout << banco_dni[i] << ", ";
				        				} 
				        				else {
				        					cout << banco_dni[i] << "";
				        				}
				        			}
				        			cout << " ]" << endl;
				        			algoritmos_ordenacion.incremento_shellsort(vector_dni, size, opcion);
				        			break;
				        }
				    }while(opcion1 != 6);
                    break;
            case 2: cont_max = 0;
				    cont_min = 999;
					suma = 0;
					media;
					cout<< setw(46) << "MINIMO" << setw(10) << "MEDIA" << setw(12) << "MAXIMO" << endl;
					for (int j = 0; j < numero_de_pruebas; j++) {
						if(numero_dni.get_contador() > cont_max) cont_max = numero_dni.get_contador();
						if(numero_dni.get_contador() < cont_min) cont_min = numero_dni.get_contador();
							suma = suma + numero_dni.get_contador();
							algoritmos_ordenacion.insercion(vector_dni,size, opcion);
					}
					media = suma/numero_de_pruebas;
					cout << "1 -> ALGORITMO INSERCION"  << setw(19) << cont_min << setw(11) << media << setw(12) << cont_max << endl;
					cont_max = 0;
				    cont_min = 999;
					suma = 0;
					media;
					for (int j = 0; j < numero_de_pruebas; j++) {
						if(numero_dni.get_contador() > cont_max) cont_max = numero_dni.get_contador();
						if(numero_dni.get_contador() < cont_min) cont_min = numero_dni.get_contador();
							suma = suma + numero_dni.get_contador();
							algoritmos_ordenacion.intercambio_burbuja(vector_dni,size, opcion);
					}
					media = suma/numero_de_pruebas;
					cout << "2 -> ALGORITMO DE LA BURBUJA"  << setw(16) << cont_min << setw(10) << media << setw(12) << cont_max << endl;
					cont_max = 0;
				    cont_min = 999;
					suma = 0;
					media;
					for (int j = 0; j < numero_de_pruebas; j++) {
						if(numero_dni.get_contador() > cont_max) cont_max = numero_dni.get_contador();
						if(numero_dni.get_contador() < cont_min) cont_min = numero_dni.get_contador();
							suma = suma + numero_dni.get_contador();
							algoritmos_ordenacion.heapsort(vector_dni,size, opcion);
					}
					media = suma/numero_de_pruebas;
					cout << "3 -> ALGORITMO HEAPSORT"  << setw(21) << cont_min << setw(11) << media << setw(12) << cont_max << endl;
					cont_max = 0;
				    cont_min = 999;
					suma = 0;
					media;
					for (int j = 0; j < numero_de_pruebas; j++) {
						if(numero_dni.get_contador() > cont_max) cont_max = numero_dni.get_contador();
						if(numero_dni.get_contador() < cont_min) cont_min = numero_dni.get_contador();
							suma = suma + numero_dni.get_contador();
							algoritmos_ordenacion.quicksort(vector_dni, 0, size, opcion, size);
					}
					media = suma/numero_de_pruebas;
					cout << "4 -> ALGORITMO QUICKSORT"  << setw(20) << cont_min << setw(11) << media << setw(12) << cont_max << endl;
					cont_max = 0;
				    cont_min = 999;
					suma = 0;
					media;
					for (int j = 0; j < numero_de_pruebas; j++) {
						if(numero_dni.get_contador() > cont_max) cont_max = numero_dni.get_contador();
						if(numero_dni.get_contador() < cont_min) cont_min = numero_dni.get_contador();
							suma = suma + numero_dni.get_contador();
							algoritmos_ordenacion.incremento_shellsort(vector_dni, size, opcion);
					}
					media = suma/numero_de_pruebas;
					cout << "5 -> ALGORITMO SHELLSORT"  << setw(20) << cont_min << setw(11) << media << setw(12) << cont_max << endl;
				    break;
			}
    }while(opcion != 0);
}