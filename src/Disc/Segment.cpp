#include "Segment.h"

#include <stdlib.h>
#include <iostream>


using namespace std;


struct SegmentSt {
  Block base;
  int size;
};


Segment newS(Block b, int s)
{
  SegmentSt* newSeg = new SegmentSt;
  newSeg->base = b;
  newSeg->size = s;
  return newSeg;
}


void useS(int n, Segment &s)
{
  s->base += n;
  s->size -= n;
}


Block baseS(Segment s)
{
  return s->base;
}


int sizeS(Segment s)
{
  return s->size;
}


bool higherS(Segment s1, Segment s2)
{
  return (s1->base > s2->base);
}


bool biggerS(Segment s1, Segment s2)
{
  return (s1->size > s2->size || (s1->size == s2->size && higherS(s1, s2)));
}


BlockList toBlocks(Segment s)
{
  BlockList res = NilBL();
  for (Block b = s->base; b < s->base + s->size; b++)
    res = ConsBL(b, res);
  return res;
}


void destroySegment(Segment &s)
{
  delete s;
  s = NULL;
}


void printSegment(Segment s)
{
  cout << "[" << s->base << "-" << (s->base + s->size) << "]";
}

