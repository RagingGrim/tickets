#ifndef FIXEDSIZEMATRIX_H
#define FIXEDSIZEMATRIX_H
#include "Object.h"
#include "Matrix.h"
#include "List.h"
#include "ListAsDynamicArray.h"
#include "ListAsVector.h"
class FixedSizeMatrix : public Matrix{
public:
      FixedSizeMatrix();
      FixedSizeMatrix(short);  //A variable which determines what kind of list to use.
      ~FixedSizeMatrix();
      void next();
      void previous();
      void add(Object *object);
private:
      List *list;
};
#endif