//!  An auditorium which can be of variable length and width.
/*!
  Really is just a clone of fixed auditorium.
*/
#ifndef DynamicAuditorium_H
#define DynamicAuditorium_H
#include "Object.h"
#include "Auditorium.h"
#include "FixedSizeMatrix.h"
class DynamicAuditorium : public Auditorium{
protected:
      int compareTo(Object const &) const;
public:
      //Constructors
      ~DynamicAuditorium();
      DynamicAuditorium(size_t , size_t);
      //Overloaded Functions
      bool isNull(void) const;
      int compare(Object const &) const;
      void print(std::ostream & = std::cout) const;
      std::string getId() const;
      //Unique Functions
      bool book(size_t , size_t);/**<Books a seat in the current auditorium. */
      void cancelBooking(size_t , size_t ); /**< Cancels a booking in the current auditorium. */
      bool findFree(size_t &, size_t &); /**< Finds the next free space in the auditorium.*/
      bool checkBoundry( size_t , size_t ); /**< Checks the boundry of rows and columns to given values.*/
      bool setVoid(size_t , size_t , size_t , bool );/**< Sets seats from one point to another to empty , can work horizontally or vertically.*/ 
      bool  bookAdv(size_t size);/**< Books the first n open spaces.*/
      void setState( size_t , size_t , short );/**< Sets the state of a particular seat.*/
      std::string dumpRaw();
      void dumpFile(std::string filename);

private:
      FixedSizeMatrix *fa;
      size_t seats;
};
#endif
