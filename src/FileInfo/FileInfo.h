#ifndef FILEINFO_H
#define FILEINFO_H

#include <iostream>
#include "../Lists/BlockList.h"
#include "../Lists/CharList.h"

using namespace std;

// PREGUNTAR A FEDE POR QUÉ NO ANDA SI MANDO ESTE STRUCT AL CPP
struct FileInfoSt {

    //nombre, tamaño y los bloques lo componen.

    CharList nombre;
    int tamanio;
    BlockList blocklist;

};

typedef FileInfoSt* FileInfo;

FileInfo nuevoFI(CharList nombre, int tamanio, BlockList blocklist);

ostream& operator<<(ostream &os, FileInfo fi);

#endif /* FILEINFO_H */
