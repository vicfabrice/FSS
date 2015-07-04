#include "FSS.h"


struct FssSt{

    Disc d;
    Map m;
    int tamanio;

};

FSS montar(int n);

int tamanoDisco(FSS fs){

    return tamano(fs->d);
}

bool existe(CharList fn, FSS fs);

void crear(CharList fn, int n, FSS &fs);

BlockList abrir(CharList fn, FSS fs);

void borrar(CharList fn, FSS &fs);


int espacioDisponible(FSS &fs){

    return (fs->tamanio);

}
