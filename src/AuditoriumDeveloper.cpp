#include <fstream>
#include <vector>
#include "AuditoriumDeveloper.h"
#include "DynamicAuditorium.h"
#include "Auditorium.h"
#include "FixedAuditorium.h"
#include "FlexiAuditorium.h"
#include "Seat.h"

AuditoriumDeveloper::AuditoriumDeveloper(){
	auditorium = NULL;
}

AuditoriumDeveloper::~AuditoriumDeveloper(){
	auditorium = NULL;
}

//Overloaded Functions
bool AuditoriumDeveloper::isNull(void) const{
	return false;
}

int AuditoriumDeveloper::compare(Object const &) const{
	return false; //Marker:Unsure
}

void AuditoriumDeveloper::print(std::ostream &out) const{
	out << "Auditorium Modeller";
}

std::string AuditoriumDeveloper::getId() const{
	return "AuditoriumDeveloper";
}

bool AuditoriumDeveloper::loadFromFile(std::string filename){
	std::fstream fs(filename.c_str());
	std::string buffer;
	size_t rows = 0  , columns = 0 ;
	size_t row = 0 , column = 0;
	if(!getRowSize(filename, rows , columns))
		return false;
	auditorium = new FixedAuditorium(rows,columns);

	if(!fs.is_open())
		return false;

	while( !fs.eof() ){
		getline(fs,buffer);
		for(size_t i = 0 ; i < buffer.size() ; i++){
			if(buffer.at(i) == 'X'){
				auditorium->setState(row, column, SEAT_TAKEN);
			}
			else if(buffer.at(i) == '0'){
				auditorium->setState(row, column, SEAT_EMPTY);
				column++;
			}
			else if(buffer.at(i) == 'V'){
				auditorium->setState(row, column, SEAT_VOID);
				column++;
			}
		}
		row++;
		column = 0;
	}
	fs.close();
	return true;
}

bool AuditoriumDeveloper::getRowSize(std::string filename , size_t &rows , size_t &columns ){
	std::fstream fs(filename.c_str());
	std::string buffer;
	std::vector <size_t>temp;
	columns = 0;

	if(!fs.is_open())
		return false;

	while( !fs.eof() ){
		getline(fs,buffer);
		rows = 0;
		for(size_t j = 0 ; j < buffer.size() ; j++)
			if(buffer.at(j) == '[')
				rows++;
		temp.push_back(rows);
		columns++;
	}
	fs.close();

	size_t largest = temp.at(0);
	for(size_t i = 0 ; i < temp.size() ; i++){
		if(largest < temp.at(i))
			largest = temp.at(i);
	}
	rows = largest;
	if(columns > 0)
		columns = columns - 1;
	return true;
}

void AuditoriumDeveloper::unbind(){
	auditorium = NULL;
}

Auditorium *AuditoriumDeveloper::getAuditorium(){
	return auditorium;
}


int AuditoriumDeveloper::compareTo(Object const &) const{
	return 1; //Marker:Unsure
}


Auditorium *AuditoriumDeveloper::construct(short type,size_t x , size_t y){
	if( type == AUD_FIXED )
	 	return new FixedAuditorium(x,y);
	else if( type == AUD_DYNAMIC )
	 	return new DynamicAuditorium(x,y);
	else
		return new FlexiAuditorium(x,y);
}
