#ifndef LISTASVECTOR_H
#define LISTASVECTOR_H
#include "List.h"
#include <vector>
class ListAsVector : public List{
protected:
      int compareTo(Object const &) const;
public:
      //Constructors
      ~ListAsVector();
      ListAsVector();
      //Overloaded Functions
      bool isNull(void) const;
      int compare(Object const &) const;
      void print(std::ostream & = std::cout) const;
      std::string getId() const;
      //Unique Functions
      void push_back(Object *object);
      void pop_back();
      Object *at(size_t i);

      //Unique Variables
private:
      //Unique Variables
      std::vector<Object *> *objectVector;
};
#endif