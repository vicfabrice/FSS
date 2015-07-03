#include "Disc.h"

#include <stdlib.h>
#include <vector>


using namespace std;


struct DiscSt {
  int size;
  vector<Segment> segs;
};


Disc nuevo(int n)
{
  DiscSt* disc = new DiscSt;
  disc->size = n;
  disc->segs.push_back(newS(0, n));
  return disc;
}


int tamano(Disc d)
{
  return d->size;
}


bool inSegment(Block b, Segment s)
{
  return baseS(s) <= b && b < baseS(s) + sizeS(s);
}


bool libre(Block b, Disc d)
{
  bool res = false;

  vector<Segment>::iterator it;
  for (it = d->segs.begin(); it != d->segs.end(); it++) {
    if (inSegment(b, *it)) {
      res = true;
      break;
    }
  }

  return res;
}


bool ocupado(Block b, Disc d)
{
  return !libre(b, d);
}


vector<Segment> toSegments(BlockList bs) {
  vector<Segment> res;

  while (!isNilBL(bs)) {
    Block base = headBL(bs);
    int size = 1;
    bs = tailBL(bs);

    while (!isNilBL(bs) && headBL(bs) == base + size) {
      size++;
      bs = tailBL(bs);
    }

    res.push_back(newS(base, size));
  }

  return res;
}


void liberar(BlockList bs, Disc &d)
{
  vector<Segment> segs = toSegments(bs);

  vector<Segment>::iterator it;
  for (it = segs.begin(); it != segs.end(); it++) {
    d->segs.push_back(*it);
  }
}


BlockList ocupar(int n, Disc &d)
{
  BlockList res = NilBL();

  while (n != 0) {
    Segment seg = d->segs.back();
    d->segs.pop_back();

    if (n < sizeS(seg)) {
      // Se completa n y sobran bloques en el segmento
      Segment used = newS(baseS(seg), n);
      useS(n, seg);
      d->segs.push_back(seg);
      seg = used;
      n = 0;
    } else {
      // Se usa el segmento completo
      n -= sizeS(seg);
    }

    BlockList bs = toBlocks(seg);
    BlockList bs2 = bs;
    while (!isNilBL(bs2)) {
      res = ConsBL(headBL(bs2), res);
      bs2 = tailBL(bs2);
    }
    destroyBlockList(bs);
    destroySegment(seg);
  }

  return res;
}


int espacioLibre(Disc d)
{
  int res = 0;

  vector<Segment>::iterator it;
  for (it = d->segs.begin(); it != d->segs.end(); it++) {
    res += sizeS(*it);
  }

  return res;
}

