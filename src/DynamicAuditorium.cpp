#include <fstream>
#include <sstream>
#include "DynamicAuditorium.h"
#include "cColours.h"
#include "Seat.h"

int DynamicAuditorium::compareTo(Object const &) const{
	return 1; //Marker:Unsure
}
//Constructors
DynamicAuditorium::DynamicAuditorium(size_t _rows , size_t _columns){
	seats = 0;
	fa = new FixedSizeMatrix( _rows , _columns );
}

DynamicAuditorium::~DynamicAuditorium(){
	delete fa;
}

//Overloaded Functions
bool DynamicAuditorium::isNull(void) const{
	return false;
}
int DynamicAuditorium::compare(Object const &) const{
	return 1; //Marker:Unsure
}

void DynamicAuditorium::print(std::ostream &out) const{
	for(size_t i = 0 ; i < fa->getRows() ; i++){		//Marker:SpecialCase ---> Coloured output might not work for a text box
		for(size_t j = 0 ; j < fa->getColumns() ; j++){
			if( fa->getValue(i,j)->getState()  == SEAT_EMPTY )
				out << RESET "[" BLUE "0" RESET "] ";
			else if ( fa->getValue(i,j)->getState() == SEAT_TAKEN )
				out << RESET "[" RED "X"  RESET "] ";
			else if ( fa->getValue(i,j)->getState()  == SEAT_VOID )
				out << "    ";
		}
	out << std::endl;
	}
}

std::string DynamicAuditorium::getId() const{
	return "DynamicAuditorium";
}
//Unique Functions
bool DynamicAuditorium::book(Person *person ,  size_t r , size_t c ){
	if(!checkBoundry(r, c))
		return false;

	if( fa->getValue(r,c)->getState() == SEAT_TAKEN )
		return false;
	else{
		fa->getValue(r, c)->setState(SEAT_TAKEN);
		fa->getValue(r, c)->bind(person);
		seats++;
		if(mementoLinked()){
			std::string buffer("book ");
			std::stringstream ss;
			buffer.append(person->toString());
			buffer.append(fa->getValue(r , c)->toString());
			buffer.append("Matrix{");
			ss << "row:" << r << " column:" << c << " Matrix}";
			buffer.append(ss.str());
			add_command(buffer);
		}
	}
	return true;
}


bool DynamicAuditorium::findFree(size_t &r, size_t &c){
	for(size_t i = 0 ; i < fa->getRows() ; i++)
		for(size_t j = 0 ; j < fa->getColumns() ; j++)
			if(fa->getValue(i,j)->getState() == SEAT_EMPTY){
				r = i;
				c =j;
				return true;
			}
		return false;
}

void DynamicAuditorium::cancelBooking(size_t r , size_t c ){
	if(!checkBoundry(r, c))
		return;
	fa->getValue(r , c )->setState(SEAT_EMPTY);

	if(mementoLinked()){
		std::string buffer;
		std::stringstream ss;
		buffer.append("cancel ");
		buffer.append(fa->getValue(r , c )->getPerson()->toString());
		buffer.append(fa->getValue(r , c)->toString());
		buffer.append("Matrix{");
		ss << "row:" << r << " column:" << c << " Matrix}";
		buffer.append(ss.str());
		add_command(buffer);
	}
	fa->getValue(r , c )->bind(NULL);
}

bool DynamicAuditorium::checkBoundry( size_t r, size_t c){
	if( r > fa->getRows() )
		return false;
	if( c > fa->getColumns() )
		return false;
	if( fa->getValue(r,c)->getState() == SEAT_VOID )
		return false;
	return true;
}

bool DynamicAuditorium::setVoid(size_t r, size_t c, size_t s , bool vertical){		//Modify this function so it can set void in rows too.
	if(vertical){
		for( size_t i = 0 ; i < s ; i++ ){									    //Maybe use a template pattern for this or tag it as one.
			if(checkBoundry(r , c + i))
				fa->getValue(r,c+i)->setState(SEAT_VOID);
			else
				return false;
		}
		return true;
	}
	else{
		for( size_t i = 0 ; i < s ; i++ ){									    //Maybe use a template pattern for this or tag it as one.
			if(checkBoundry(c + i , r))
				fa->getValue(c+i,r)->setState(SEAT_VOID);
			else
				return false;
		}
		return true;
	}
}

void DynamicAuditorium::setState( size_t r, size_t c, short s){
	fa->getValue(r, c)->setState(s);
}

bool DynamicAuditorium::bookAdv(Group &group){
	size_t spaces = 0;
	size_t counter = 0;

	bool spaceFound = false;
	size_t j;
	size_t i;

	for( i = 0 ; i < fa->getRows() ; i++){
		for(j = 0 ; j < fa->getColumns() ; j++){
			if( fa->getValue(i, j) == SEAT_EMPTY ){
				spaces++;
			}
			else{
				spaces = 0;
				continue;
			}

			if(spaces == group.getSize()){
				spaceFound = true;
				break;
			}
		}
		if(spaceFound)
			break;
		spaces = 0;
	}

	if(spaceFound)
		for(size_t c = 0  ; c  < group.getSize() ; c++){
			book(group.at(counter++),i,j-c);
		}
	return spaceFound;
}
short DynamicAuditorium::getState( size_t row, size_t column){
	if(!checkBoundry(row, column))
		return SEAT_VOID;
	else
		return fa->getValue(row,column)->getState();
}


std::string DynamicAuditorium::dumpRaw(){
	std::string buffer;
	for(size_t i = 0 ; i < fa->getRows() ; i++){
		for(size_t j = 0 ; j < fa->getColumns() ; j++){ //Marker:SpecialCase ---> Coloured output might not work for a text box
			if(fa->getValue(i,j)->getState() == SEAT_EMPTY )
				buffer.append("[0] ");
			else if (fa->getValue(i,j)->getState() == SEAT_TAKEN )
				buffer.append("[X] ");
			else if (fa->getValue(i,j)->getState() == SEAT_VOID )
				buffer.append("[V] ");	//TEMP
		}
		buffer.push_back('\n');
	}
	return buffer;
}

void DynamicAuditorium::dumpFile(std::string filename){
	std::ofstream fs(filename.c_str());
	fs << dumpRaw();
	fs.close();
}

Seat *DynamicAuditorium::getSeat( size_t row, size_t column){
		if(!checkBoundry(row, column))
			return NULL;
		else
			return fa->getValue(row, column);
}
