#ifndef SEGMENT_H
#define SEGMENT_H

#include "../Lists/BlockList.h"


struct SegmentSt;
typedef SegmentSt* Segment;


Segment newS(Block b, int s);

void useS(int n, Segment &s);

Block baseS(Segment s);

int sizeS(Segment s);

bool higherS(Segment s1, Segment s2);

bool biggerS(Segment s1, Segment s2);

BlockList toBlocks(Segment s);

void destroySegment(Segment &s);

void printSegment(Segment s);

#endif /* SEGMENT_H */

