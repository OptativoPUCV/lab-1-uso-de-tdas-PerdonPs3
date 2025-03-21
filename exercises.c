#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
   List* L = create_list();// crea la lista.
   for(int k = 1; k <= 10; k++){ //sabemos que son 10 elementos asique creamos un for.
      int* dato = (int*) malloc(sizeof(int));// se hace reserva de memoria.
      *dato = k; // le asignamos el valor de k.
      pushFront(L, dato);// ingresamos el dato a la lista.
   }
   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
   int suma = 0;// se crea variable que guardara la suma de los elementos.
   int* elemento = first(L);// asignamos variable centinela que guarda el primer elemento de la lista.
   while(elemento != NULL){// inicializamos el ciclo infinito controlado.
      suma += *elemento;// sumamos los elementos.
      elemento = next(L);// cambiamos el valor del elemento al siguiente de la lista.
   }
   return suma;// retornamos la suma.
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem){
   int* elemento = first(L);// guardamos una variable centinela.
   while(elemento != NULL){
      if(*elemento == elem){// si el elemento de la lista es igual al dato a eliminar.
         popCurrent(L);// se elimina de la lista.
         elemento = first(L);// actualizamos el elemento.
      }
      else elemento = next(L);// sigue con el siguiente de la lista.
   }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
   Stack* aux = create_stack();// se crea pila auxiliar.
   
   while(top(P1) != NULL){// mientras la pila no este vacia.
      push(aux, top(P1));// guardamos los datos en el auxiliar.
      pop(P1);// eliminamos el dato de la pila.
   }
   
   while(top(aux) != NULL){// mientras el auxiliar no este vacio.
      push(P2, top(aux));// guardamos los datos de auxiliar en la pila 2.
      push(P1, top(aux));// guardamos los datos de auxiliar en la pila 1.
      pop(aux);// borramos los datos de auxiliar.
   }
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
   Stack* pila = create_stack();// se crea pila.
   for(int k = 0; cadena[k] != '\0'; k++)// recorremos la cadena.
      if((cadena[k] == '[') || (cadena[k] == '{') || (cadena[k] == '(')){ // si la cadena tiene un abre parentesis.
         char* dato = (char*) malloc(sizeof(char));// se almacena memoria.
         *dato = cadena[k];// se guarda el caracter en dato.
         push(pila, dato);// agregamos el caracter a la pila.
      }
      else if((cadena[k] == ']' )|| (cadena[k] == '}') || (cadena[k] == ')')){// si el caracter es un cierre parentesis.
         char* elemento = top(pila);// se guarda el elemento top de la pila para comparar.
         if(elemento == NULL) return 0; // si no ingreso ningun parentesis se detiene el proceso.
         if((cadena[k] == ']' && *elemento != '[') ||(cadena[k] == '}' && *elemento != '{') ||(cadena[k] == '(' && *elemento != ')'))return 0;// verifica si el parentesis es incorrecto retornando 0; 
         pop(pila);// en todo otro caso se elimina el primer caracter de la pila, para continuar con el siguiente, y asi saber si es balanceado.
         }
if(top(pila) == NULL)return 1;// si la pila quedo vacia indica que el procedimiento fue correcto y es balanceado.
return 0;// no es balanceado.
}

