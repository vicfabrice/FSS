//#include "Lists/CharList.h"
#include "Map/Map.h"
#include "Disc/Disc.h"
#include "FSS/FSS.h"

#include <iostream>

using namespace std;

int main (){


    // caba
    CharList cl1 = NilCL();
    CharList cl2 = ConsCL('a',cl1);
    CharList cl3 = ConsCL('b',cl2);
    CharList cl4 = ConsCL('a',cl3);
    CharList cl5 = ConsCL('c',cl4);

    printCharList(cl5);

    Map m = createNode();

    assocM(m,cl5,(MAP_ELEM_TYPE)3);

    Maybe val = lookupM(m, cl5);
    if(! isNothing(val)) {
     cout << ": " << fromJust(val) << endl;
    } else {
     cout << ": no existe" << endl;
    }

    deleteM(m,cl5);

    val = lookupM(m, cl5);

    if(! isNothing(val)) {
     cout << ": " << fromJust(val) << endl;
    } else {
     cout << ": no existe" << endl;
    }



    // cout << ": " << fromJust(lookupM(m, cl5)) << endl;

//// cab
//    cl1 = NilCL();
//    cl2 = ConsCL('b',cl1);
//    cl3 = ConsCL('a',cl2);
//    cl4 = ConsCL('c',cl3);
//
//     printCharList(cl4);
//
//    assocM(m,cl4,(MAP_ELEM_TYPE)5);
//
//    cout << ": " << fromJust(lookupM(m, cl4)) << endl;

return 0;
}




//int main(int argc, char* argv[]) {
//
//  const int size = 1000;
//  Disc disco = nuevo(size);
//
//  cout << "Bloques usados en disco: ";
//  for (Block bloque = 0; bloque < size; bloque++)
//    if (ocupado(bloque, disco))
//      cout << " " << bloque;
//  cout << endl;
//  cout << "Espacio libre: " << espacioLibre(disco) << endl;
//
//  BlockList bloques = ocupar(100, disco);
//
//  cout << "Bloques asignados: ";
//  printBlockList(bloques);
//  cout << endl;
//
//  cout << "Bloques usados en disco: ";
//  for (Block bloque = 0; bloque < size; bloque++)
//    if (ocupado(bloque, disco))
//      cout << " " << bloque;
//  cout << endl;
//  cout << "Espacio libre: " << espacioLibre(disco) << endl;
//
//  liberar(tailBL(bloques), disco);
//
//  cout << "Bloques usados en disco: ";
//  for (Block bloque = 0; bloque < size; bloque++)
//    if (ocupado(bloque, disco))
//      cout << " " << bloque;
//  cout << endl;
//  cout << "Espacio libre: " << espacioLibre(disco) << endl;
//
///*
//  Map fat = emptyM();
//
//  const int filenameSize = 7;
//  const int fileCount = 6;
//  const char* filenames[fileCount] = {
//    "filetxt",
//    "fileobj",
//    "filecpp",
//    "filehpp",
//    "filetex",
//    "otroexe"
//  };
//
//  for (int file = 0; file < fileCount; file++) {
//    CharList filename = NilCL();
//
//    for (int i = filenameSize-1; i >= 0; i--) {
//      filename = ConsCL(filenames[file][i], filename);
//    }
//
//    assocM(fat, filename, file);
//
//    printCharList(filename);
//    cout << ": " << fromJust(lookupM(fat, filename)) << endl;
//
//    destroyCharList(filename);
//  }
//*/
//  return 0;
//}
//
