#include <iostream>
#include "FileInfo.h"
//
//
//struct FileInfoSt {
//
//    //nombre, tama ̃no y los bloques lo componen.
//
//    CharList nombre;
//    int tamanio;
//    BListNodeSt* blocklist;
//
//};

FileInfo nuevoFI(CharList nombre, int tamanio, BlockList blocklist){
    FileInfoSt* fi = new FileInfoSt;
    fi->nombre = nombre;
    fi->tamanio = tamanio;
    fi->blocklist = blocklist;
    return fi;
}

ostream& operator<<(ostream &os, FileInfo fi) {
  CharList xs = fi->nombre;
  if (isNilCL(xs)) {
    os << "[]";
  } else {
    CharList current = xs;
    os << "[ ";
    os << headCL(current);
    current = tailCL(current);
    while (!isNilCL(current)) {
      os << ", ";
      os << headCL(current);
      current = tailCL(current);
    }

    os << " ]" << endl;
  }
  return os;
}
