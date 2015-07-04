#ifndef FSS_H
#define FSS_H

#include "../Lists/CharList.h"
#include "../Lists/BlockList.h"
#include "../Map/Map.h"
#include "../Disc/Disc.h"



// #define MAP_ELEM_TYPE FileInfo

//Como usuario, tengo que usar todas las funciones de Map

struct FssSt;
typedef FssSt* FSS;



FSS montar(int n);

int tamanoDisco(FSS fs);

bool existe(CharList fn, FSS fs);

void crear(CharList fn, int n, FSS &fs);

BlockList abrir(CharList fn, FSS fs);

void borrar(CharList fn, FSS &fs);

int espacioDisponible(FSS &fs);

#endif /* FSS_H */
