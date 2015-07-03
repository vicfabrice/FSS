#include <iostream>
#include "FileInfo.h"

using namespace std;

struct FileInfoSt {

    //nombre, tama ̃no y los bloques lo componen.

    string nombre;
    int tamanio;
    BlockList* blocklist;

};
