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
   return suma;
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
   int* elemento = first(L);
   while(elemento != NULL){
      if(*elemento == elem){
         popCurrent(L);
         elemento = first(L);
      }
      else elemento = next(L);
   }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
   Stack* aux = create_stack();
   
   while(top(P1) != NULL){
      push(aux, top(P1));
      pop(P1);
   }
   
   while(top(aux) != NULL){
      push(P2, top(aux));
      push(P1, top(aux));
      pop(aux);
   }
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
   Stack* pila = create_stack();// creamos la pila.
   for(int k = 0; cadena[k] != '\0'; k++)// recorremos la cadena.
      if(cadena[k] == '[' || cadena[k] == '{' || cadena[k] == '('){// si la cadena contiene alguno de estos parentesis.
         char* dato = (char*) malloc(sizeof(char));// reservamos memoria.
         *dato = cadena[k];// asignamos el caracter a nuestra variable dato.
         push(pila, dato);// ingresamos el dato a la pila.
      }
      else if(cadena[k] == ']' || cadena[k] == '}' || cadena[k] == ')'){// si la cadena contiene alguno de estos parentesis.
         char* elemento = top(pila);// guardamos el elemento de la pila mas alto para comprobar si el siguiente es el mismo pero cerrado. [{()}]
         if(elemento == NULL) return 0;// significa que no ingreso ningun parentesis.
         if(cadena[k] == ']' && *elemento != '[' ||cadena[k] == '}' && *elemento != '{' ||cadena[k] == '(' && *elemento != ')')return 0; // si el elemento de la pila es distinto al parentesis del caracter que se esta evaluando no es balanceado.
         pop(pila);// eliminamos el primer elemento para comparar con el siguiente. [{( --> [{ ]} X
         }
      }
if(top(pila) == NULL)return 1;// significa que verifico todos los datos guardados en la pila y no queda ninguno por revisar, y que por lo tanto es balanceado.   
return 0;// no es balanceado.
}

