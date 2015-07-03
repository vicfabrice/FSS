#ifndef BLOCK_LIST_H
#define BLOCK_LIST_H

typedef int Block;

/* Declaraciones de tipos -- NO USAR! Deben abstraerse! */
struct BListNodeSt;
typedef BListNodeSt* BlockList;


// La lista vacia
BlockList NilBL();

// Agregar un elemento adelante o atras
BlockList ConsBL(Block x, BlockList xs);

// Ver si es la lista vacia
bool isNilBL(BlockList xs);

// Primer elemento y resto de una lista no vacia
Block headBL(BlockList xs);     // Parcial en la lista vacia
BlockList tailBL(BlockList xs); // Parcial en la lista vacia

// Para destruir una lista
void destroyBlockList(BlockList &xs);

// Para imprimir listas de manera piola
void printBlockList(BlockList xs);

#endif /* LIST_H */

