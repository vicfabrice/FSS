#ifndef FSS_H
#define FSS_H


#define MAP_ELEM_TYPE FileInfo  // Definir FileInfo?????

//Como usuario, tengo que usar todas las funciones de Map

struct FssSt;
typedef FssSt* FSS;



FSS montar(int n);

int tamano(Disc d);

bool existe(CharList fn, FSS fs);

void crear(CharList fn, int n, FSS &fs);

BlockList abrir(CharList fn, FSS fs);

void borrar(CharList fn, FSS &fs);

int espacioDisponible(FSS &fs);

#endif /* FSS_H */
