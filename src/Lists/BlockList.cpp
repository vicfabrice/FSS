#include "BlockList.h"

#include <stdlib.h>
#include <iostream>

using namespace std;


struct BListNodeSt {
  Block value;
  BListNodeSt* next;
};


/*************************************/
/* Implementacion de las operaciones */
/*************************************/

BlockList NilBL()
/*
   PROPOSITO: construye la lista vacia
   PRECOND: ninguna, es una operacion total
*/
{ return NULL; }


BlockList ConsBL(Block x, BlockList xs)
/*
   PROPOSITO: agrega el elemento x adelante de la lista xs
   PRECOND: ninguna, es una operacion total
   OBSERVACIONES: no modifica xs, pero la comparte
*/
{
  // Se pide memoria
  BListNodeSt* newNode = new BListNodeSt;
  // Se asignan los elementos
  newNode->value = x;
  newNode->next  = xs; // BlockList es (struct lNode*)
  // Se retorna la lista recien construida
  return newNode;
}


BlockList snocBL(BlockList xs, Block x)
/*
   PROPOSITO: agrega el elemento x atras de la lista xs
   PRECOND: ninguna, es una operacion total
   OBSERVACIONES: MODIFICA xs como efecto lateral y
                  todas las sublistas compartidas!
*/
{
  BlockList current;
  BlockList retorno;

  // Se pide memoria
  BListNodeSt* newNode = new BListNodeSt;
  // Se asignan los elementos
  newNode->value = x;
  newNode->next  = NULL;

  // Se calcula el ultimo elemento
  if (isNilBL(xs)) {
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


bool isNilBL(BlockList xs)
/*
   PROPOSITO: pregunta si es la lista vacia
   PRECOND: ninguna, es una operacion total
*/
{ return (xs == NULL); }


Block headBL(BlockList xs)
/*
   PROPOSITO: devuelve el primer elemento de la lista
   PRECOND: xs no es vacia
*/
{ return (xs->value); }


BlockList tailBL(BlockList xs)
/*
   PROPOSITO: devuelve la lista sin el primer elemento
   PRECOND: xs no es vacia
*/
{ return (xs->next); }


void destroyBlockList(BlockList &xs)
/*
   PROPOSITO: liberar la memoria de los nodos de la lista
*/
{
  while (!isNilBL(xs)) {
    BlockList next = tailBL(xs);
    delete xs;
    xs = next;
  }
}


void printBlockList(BlockList xs)
/*
   PROPOSITO: imprime la lista
   PRECOND: ninguna, es una operacion total
*/
{
  if (isNilBL(xs)) {
    cout << "[]";
  } else {
    BlockList current = xs;
    cout << "[ ";
    cout << headBL(current);
    current = tailBL(current);
    while (!isNilBL(current)) {
      cout << ", ";
      cout << headBL(current);
      current = tailBL(current);
    }
    cout << " ]";
  }
}

