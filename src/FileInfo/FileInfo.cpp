#include <iostream>

using namespace std;

struct FileInfo {

    //nombre, tama ̃no y los bloques lo componen.

    string nombre;
    int tamanio;
    BlockList* block;

};

typedef int block;
