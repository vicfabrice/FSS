#include "Maybe.h"

#include <stdlib.h>
#include <iostream>

using namespace std;


struct MaybeSt {
  MAYBE_ELEM_TYPE value;
};


Maybe Nothing()
{
  return NULL;
}


Maybe Just(MAYBE_ELEM_TYPE e)
{
  MaybeSt* m = new MaybeSt;
  m->value = e;
  return m;
}


// parcial en Nothing
MAYBE_ELEM_TYPE fromJust(Maybe m)
{
  return m->value;
}


bool isNothing(Maybe m)
{
  return m == NULL;
}


void destroyMaybe(Maybe &m)
{
  if (!isNothing(m)) {
    delete m;
    m = NULL;
  }
}


void printMaybe(Maybe m)
{
  if (isNothing(m)) {
    cout << "Nothing";
  } else {
    cout << "Just " << m->value;
  }
}

