#include <iostream>
#include "Map.h"
#include "../Maybe/Maybe.h"

//la clave no es parte del �rbol. Ning�n nodo guarda la clave

//el primer nodo es vac�o, la palabra vac�o

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

bool noTieneHijos(Map m){

    bool noTiene = true;

    for (int i=0; i<26; i++){

        noTiene = m->hijos[i] == NULL;

    }
}


void deleteM(Map &m, CharList k){

    //Precondici�n: El Charlist k es v�lido, por lo tanto tiene un valor


    // Si tiene hijos, puedo borrar valor pero no nodo

    if (not isNilCL(k)){ //si no es vac�o el charlist

        deleteM((m->hijos[(hashC(headCL(k)))]), tailCL(k));

          if (noTieneHijos(m)&& isNothing(m->value)){ //si tiene hijos

            delete[] m->hijos;
            destroyMaybe(m->value);
            delete m;
            m = NULL;
        }
    }
    else { //si el charlist es nil

        destroyMaybe(m->value);
        m->value = Nothing();

          if (noTieneHijos(m)){ //si no tiene hijos

            delete[] m->hijos;
            destroyMaybe(m->value);
            delete m;
            m = NULL;
            }
        }
}


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



/*void printMap(Map &m)

   PROPOSITO: imprime el mapa wey
   PRECOND: ninguna, es una operacion total

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
}*/


