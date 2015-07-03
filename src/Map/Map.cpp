#include <iostream>
#include "Map.h"
#include "../Maybe/Maybe.h"

//la clave no es parte del árbol. Ningún nodo guarda la clave

//el primer nodo es vacío, la palabra vacío

struct MapNodeSt{

    MaybeSt* value;
    MapNodeSt* hijos[26];

};

typedef MapNodeSt* Map;


int hashC(char c){

    return (c-'a');
}


Map emptyM(){

    return NULL;

}

Map createNode(){

    Map m = new MapNodeSt;

    m->value = Nothing();

    for (int i=0; i<26; i++){

        m->hijos[i] = NULL;
    }

    return m;

}

void assocM(Map &m, CharList k, MAP_ELEM_TYPE v){

    Map mNext;

    if(m==NULL) {
        m = createNode();
    }
    mNext = m;
    while (not isNilCL(k)){
        int indiceHijo = hashC(headCL(k));
        // si no existe el hijo
        if(mNext->hijos[indiceHijo]==NULL) {
            mNext->hijos[indiceHijo] = createNode();
            mNext = mNext->hijos[indiceHijo];
        }
        k = tailCL(k);
    }
    mNext->value = Just(v);
}




//void deleteM(Map &m, CharList k){
//
//    // Si no tiene valor y no tiene hijos, borro. Esa sería la condición.
//
//    // Precond: La palabra k existe en mi mapa m
//
//    delete fromJust(lookupM(m,k)); //borrás el valor al que te lleva el charlist k
//
//    while (not isNilCL(k)){
//
//        if((m->value == NULL))/*&&(no tiene hijos))¿ Cómo compruebo que no tiene hijos?*/{
//
//            delete m;
//             k = tailCL(k);
//
//        }
//        else {
//
//            deleteM(m->hijos);
//        }
//    }
//
//}

Maybe lookupM(Map m, CharList k){

    while (not isNilCL(k)){

        if (m!=NULL){

            m = m->hijos[(hashC(headCL(k)))];
            k = tailCL(k);

            }
        else {
                return Nothing();}


    }

    if (m!= NULL){
            return m->value;
        }
        else
            {return Nothing();}


}



void printMap(Map &m)
/*
   PROPOSITO: imprime el mapa wey
   PRECOND: ninguna, es una operacion total
*/
{
  if (m== NULL) {
    cout << "Naditas";
  } else {
    cout << "Value:";
    cout << fromJust(m->value);
    for (int i=0; i<26; i++){
        printMap(m->hijos[i]);
    }


  }
}


