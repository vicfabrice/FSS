#include "FSS.h"
#include "../FileInfo/FileInfo.h"

struct FssSt{

    Disc d;
    Map m;
    int tamanio;

};

FSS montar(int n){
    FssSt* fss = new FssSt;
    fss->d = nuevo(n);
    fss->m = emptyM();
    fss->tamanio = tamanoDisco(fss);
    return fss;
}

int tamanoDisco(FSS fs){

    return tamano(fs->d);

}

bool existe(CharList fn, FSS fs) {

    return !isNothing(lookupM(fs->m, fn));

}

void crear(CharList fn, int n, FSS &fs) {
    FileInfoSt* fi = nuevoFI(fn,n,ocupar(n, fs->d));
    assocM(fs->m,fn,fi);
}

BlockList abrir(CharList fn, FSS fs){
    Maybe mb = lookupM(fs->m,fn);

    if(!isNothing(mb)) {
        FileInfo fi = (FileInfo) fromJust(mb);
        return fi->blocklist;
    }
    return NilBL();

}

void borrar(CharList fn, FSS &fs) {

    Maybe mb = lookupM(fs->m,fn);

    if(!isNothing(mb)) {

        FileInfo fi = (FileInfo) fromJust(mb);

        liberar(fi->blocklist, fs->d);

        deleteM(fs->m,fn);

    }

}


int espacioDisponible(FSS &fs){

    return espacioLibre(fs->d);

}
