#include "CharList.h"

#include <stdlib.h>
#include <iostream>

using namespace std;


struct CListNodeSt {
  char value;
  CListNodeSt* next;
};


/*************************************/
/* Implementacion de las operaciones */
/*************************************/

CharList NilCL()
/*
   PROPOSITO: construye la lista vacia
   PRECOND: ninguna, es una operacion total
*/
{ return NULL; }


CharList ConsCL(char x, CharList xs)
/*
   PROPOSITO: agrega el elemento x adelante de la lista xs
   PRECOND: ninguna, es una operacion total
   OBSERVACIONES: no modifica xs, pero la comparte
*/
{
  // Se pide memoria
  CListNodeSt* newNode = new CListNodeSt;
  // Se asignan los elementos
  newNode->value = x;
  newNode->next  = xs; // CharList es (struct lNode*)
  // Se retorna la lista recien construida
  return newNode;
}


CharList snocCL(CharList xs, char x)
/*
   PROPOSITO: agrega el elemento x atras de la lista xs
   PRECOND: ninguna, es una operacion total
   OBSERVACIONES: MODIFICA xs como efecto lateral y
                  todas las sublistas compartidas!
*/
{
  CharList current;
  CharList retorno;

  // Se pide memoria
  CListNodeSt* newNode = new CListNodeSt;
  // Se asignan los elementos
  newNode->value = x;
  newNode->next  = NULL;

  // Se calcula el ultimo elemento
  if (isNilCL(xs)) {
    retorno = newNode;
  } else {
    current = xs;
    while (!(current->next == NULL))
      current = current->next;

    current->next = newNode;
    retorno = xs;
  }

  // Se retorna la lista recien construida
  return (retorno);
}


bool isNilCL(CharList xs)
/*
   PROPOSITO: pregunta si es la lista vacia
   PRECOND: ninguna, es una operacion total
*/
{ return (xs == NULL); }


char headCL(CharList xs)
/*
   PROPOSITO: devuelve el primer elemento de la lista
   PRECOND: xs no es vacia
*/
{ return (xs->value); }


CharList tailCL(CharList xs)
/*
   PROPOSITO: devuelve la lista sin el primer elemento
   PRECOND: xs no es vacia
*/
{ return (xs->next); }


void destroyCharList(CharList &xs)
/*
   PROPOSITO: liberar la memoria de los nodos de la lista
*/
{
  while (!isNilCL(xs)) {
    CharList next = tailCL(xs);
    delete xs;
    xs = next;
  }
}


void printCharList(CharList xs)
/*
   PROPOSITO: imprime la lista
   PRECOND: ninguna, es una operacion total
*/
{
  if (isNilCL(xs)) {
    cout << "[]";
  } else {
    CharList current = xs;
    cout << "[ ";
    cout << headCL(current);
    current = tailCL(current);
    while (!isNilCL(current)) {
      cout << ", ";
      cout << headCL(current);
      current = tailCL(current);
    }
    cout << " ]";
  }
}

