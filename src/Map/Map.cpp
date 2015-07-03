#include <iostream>
#include "Map.h""

//la clave no es parte del �rbol. Ning�n nodo guarda la clave

//el primer nodo es vac�o, la palabra vac�o

struct MapNodeSt{

    Maybe value;
    MapNodeSt* ramas[26];

};

int hashC(char c){

    return (c-'a')



Map emptyM(){

    return NULL;

}

Map createNode{

    Map m = new MapNodeSt;

    m->value = Nothing;

    for (i=0; i<26; i++){

        m->hijos[i] = NULL;
    }

}

void assocM(Map &m, CharList k, MAP_ELEM_TYPE v){


   while (not isNilCL(k)){

        if (m!=NULL){

            m = m->hijos[(hashC(headCL(k)));
            k = tailCL(k);

            }
        else {
                m = createNode;
               }
    }

    m->value = Just(v);

}




void deleteM(Map &m, CharList k){

    // Si no tiene valor y no tiene hijos, borro. Esa ser�a la condici�n.

    // Precond: La palabra k existe en mi mapa m

    delete fromJust(lookupM(m,k)); //borr�s el valor al que te lleva el charlist k

    while (not isNilCL(k)){

        if((m->value == NULL)/*&&(no tiene hijos))� C�mo compruebo que no tiene hijos?*/{

            delete m;
             k = tailCL(k);

        }
        else {

            deleteM(m->hijos);
        }
    }

}

Maybe lookupM(Map m, CharList k){


    while (not isNilCL(k)){

        if (m!=NULL){

            m = m->hijos[(hashC(headCL(k)));
            k = tailCL(k);

            }
        else {
                return Nothing();}


    }

    if (m!= NULL;){
            return m->value;
        }
        else
            {return Nothing();}


}


}

