#ifndef DISC_H
#define DISC_H

#include "Segment.h"


struct DiscSt;
typedef DiscSt* Disc;


Disc nuevo(int n);

int tamano(Disc d);

bool libre(Block b, Disc d);

bool ocupado(Block b, Disc d);

void liberar(BlockList bs, Disc &d);

BlockList ocupar(int n, Disc &d);

int espacioLibre(Disc d);

#endif /* DISC_H */

