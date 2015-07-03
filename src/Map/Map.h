#ifndef MAP_H
#define MAP_H

#include "../Lists/CharList.h"
#include "../Maybe/Maybe.h"


#define MAP_ELEM_TYPE   MAYBE_ELEM_TYPE

struct MapNodeSt;
typedef MapNodeSt* Map;


Map emptyM();

void assocM(Map &m, CharList k, MAP_ELEM_TYPE v);

void deleteM(Map &m, CharList k);

Maybe lookupM(Map m, CharList k);

#endif /* MAP_H */

