#ifndef CHAR_LIST_H
#define CHAR_LIST_H


/* Declaraciones de tipos -- NO USAR! Deben abstraerse! */
struct CListNodeSt;
typedef CListNodeSt* CharList;


/****************************/
/* Operaciones sobre listas */
/****************************/
/* OBSERVACIONES:
   * no se hacen suposiciones sobre el gasto o
     el nivel de reuso de memoria. Debe observarse
     la implementacion.
   * la operacion de Snoc es destructiva!!!!
     Si su argumento no es singleThreaded, da problemas
*/

// La lista vacia
CharList NilCL();

// Agregar un elemento adelante o atras
CharList ConsCL(char x, CharList xs);

// Ver si es la lista vacia
bool isNilCL(CharList xs);

// Primer elemento y resto de una lista no vacia
char headCL(CharList xs);       // Parcial en la lista vacia
CharList tailCL(CharList xs);   // Parcial en la lista vacia

// Para destruir una lista
void destroyCharList(CharList &xs);

// Para imprimir listas de manera piola
void printCharList(CharList xs);

#endif /* CHAR_LIST_H */

