////#include "Lists/CharList.h"
//#include "Map/Map.h"
//#include "Disc/Disc.h"
//#include "FSS/FSS.h"
//
//#include <iostream>
//
//using namespace std;
//
//int main (){
//
//
//    // caba
//    CharList cl1 = NilCL();
//    CharList cl2 = ConsCL('a',cl1);
//    CharList cl3 = ConsCL('b',cl2);
//    CharList cl4 = ConsCL('a',cl3);
//    CharList cl5 = ConsCL('c',cl4);
//
//    printCharList(cl5);
//
//
//// cab
//    CharList cl7 = NilCL();
//    CharList cl8 = ConsCL('b',cl7);
//    CharList cl9 = ConsCL('a',cl8);
//    CharList cl10 = ConsCL('c',cl9);
//
//    printCharList(cl10);
//
//
//    Map m = createNode();
//
//    assocM(m,cl5,(MAP_ELEM_TYPE)3);
//    assocM(m,cl10,(MAP_ELEM_TYPE)4);
//
//
//    Maybe val = lookupM(m, cl10);
//    if(! isNothing(val)) {
//     cout << ": " << fromJust(val) << endl;
//    } else {
//     cout << ": no existe" << endl;
//    }
//
//    deleteM(m,cl10);
//
//    val = lookupM(m, cl10);
//
//    if(! isNothing(val)) {
//     cout << ": " << fromJust(val) << endl;
//    } else {
//     cout << ": no existe" << endl;
//    }
//
//
//
//    val = lookupM(m, cl5);
//    if(! isNothing(val)) {
//     cout << ": " << fromJust(val) << endl;
//    } else {
//     cout << ": no existe" << endl;
//    }
//
//    deleteM(m,cl5);
//
//    val = lookupM(m, cl5);
//
//    if(! isNothing(val)) {
//     cout << ": " << fromJust(val) << endl;
//    } else {
//     cout << ": no existe" << endl;
//    }
//
//
//return 0;
//}
//
//
//
//
