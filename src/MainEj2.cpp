//#include "Lists/CharList.h"
#include "Map/Map.h"
#include "Disc/Disc.h"
#include "FSS/FSS.h"

#include <iostream>

using namespace std;

int main ()
{

    FSS fss = montar(50);

    cout<< "Disco montado ocupando " << tamanoDisco(fss) << " bytes" << endl;

    const int filenameSize = 7;
    const int fileCount = 6;
    const char* filenames[fileCount] =
    {
        "filetxt",
        "fileobj",
        "filecpp",
        "filehpp",
        "filetex",
        "otroexe"
    };

    for (int file = 0; file < fileCount; file++)
    {
        cout << "Creando CharList " << filenames[file] << endl;
        CharList filename = NilCL();

        for (int i = filenameSize-1; i >= 0; i--)
        {
            filename = ConsCL(filenames[file][i], filename);
        }

        if(!existe(filename,fss))
        {
            cout << "Creando archivo " << filenames[file] << " de " << 7 + file << " bytes" << endl;
            crear(filename,7 + file,fss);
            cout << "Bloques" << endl;
            BlockList bl = abrir(filename,fss);
            printBlockList(bl);

        }

        cout << endl << "Espacio disponible en disco " << espacioDisponible(fss) << endl;

        cout << "Borrando archivo " << filenames[file] << endl;

        borrar(filename,fss);

        cout << "Espacio disponible en disco " << espacioDisponible(fss) << endl << endl ;

    }

    return 0;
}




