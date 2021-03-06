# Connor Armand du Plooy
# u16169532

FLAGS = -Wall -Werror -ggdb -pedantic-errors
COMPILER = clang++

.PHONY: documentation

default: compile_bind_main demo
	@clear
	@echo "Compilation done;"
	@echo "A demonstration of what my classes can do will run in 5 seconds . . . "
	@sleep 5
	src/demo.out
	@sleep 2
	@clear
	@echo "Demonstration done , the CLI interface example will launch in 5 seconds..."
	@sleep 5
	src/a.out
	@sleep 2
	@clear
	@echo "CLI interface example was closed , the GUI interface will launch in 5 seconds...."
	@sleep 5
	Qt/build-tickets-Desktop-Debug/tickets
	@sleep 2
	@clear
	@echo "All examples/interfaces were launched , I hope you enjoyed my practical!"

demo: compile_nullObject compile_integer compile_list compile_listAsVector compile_listAsDynamicArray compile_NullPerson compile_container compile_Seat compile_listAsSLL compile_Person compile_Adult compile_Minor compile_Pensioner compile_listAsDLL compile_dynamicAuditorium compile_dynamicSizeMatrix compile_matrix compile_AuditoriumModeller compile_Summary compile_AuditoriumList compile_fixedSizeMatrix compile_Group compile_fixedAuditorium compile_AuditoriumDeveloper compile_flexiAuditorium compile_ticketPrinter compile_Auditorium compile_Store compile_Booking compile_AuditoriumMemento
	${COMPILER} src/NullObject.o src/Container.o src/Matrix.o src/DynamicSizeMatrix.o src/FixedSizeMatrix.o src/Auditorium.o src/FixedAuditorium.o src/DynamicAuditorium.o src/AuditoriumModeller.o src/Seat.o src/Integer.o src/Person.o src/Minor.o src/Adult.o src/Pensioner.o src/NullPerson.o src/List.o src/ListAsDynamicArray.o src/ListAsVector.o src/ListAsSLL.o src/ListAsDLL.o  src/AuditoriumList.o src/Summary.o src/AuditoriumDeveloper.o src/Group.o src/AuditoriumMemento.o src/FlexiAuditorium.o src/Store.o src/TicketPrinter.o src/Booking.o src/demo.cpp -lpthread -ggdb  -o src/demo.out -Wall

compile_bind_main: compile_nullObject compile_integer compile_list compile_listAsVector compile_listAsDynamicArray compile_NullPerson compile_container compile_Seat compile_listAsSLL compile_Person compile_Adult compile_Minor compile_Pensioner compile_listAsDLL compile_dynamicAuditorium compile_dynamicSizeMatrix compile_matrix  compile_AuditoriumModeller compile_Summary  compile_AuditoriumList compile_fixedSizeMatrix compile_Group compile_fixedAuditorium compile_AuditoriumDeveloper compile_flexiAuditorium compile_ticketPrinter compile_Auditorium compile_Store compile_Booking compile_AuditoriumMemento
	@clear
	@echo "Binding and linking . . ."
	${COMPILER} src/NullObject.o src/Container.o src/Matrix.o src/DynamicSizeMatrix.o src/FixedSizeMatrix.o src/Auditorium.o src/FixedAuditorium.o src/DynamicAuditorium.o src/AuditoriumModeller.o src/Seat.o src/Integer.o src/Person.o src/Minor.o src/Adult.o src/Pensioner.o src/NullPerson.o src/List.o src/ListAsDynamicArray.o src/ListAsVector.o src/ListAsSLL.o src/ListAsDLL.o src/Summary.o  src/AuditoriumList.o src/AuditoriumDeveloper.o src/Group.o src/AuditoriumMemento.o src/FlexiAuditorium.o src/Store.o src/TicketPrinter.o src/Booking.o src/main.cpp -lpthread -ggdb -o src/a.out -Wall
	@echo "\n"
	@echo "Finished!"

compile_bind_all: compile_nullObject compile_integer compile_list compile_listAsVector compile_listAsDynamicArray compile_NullPerson compile_container compile_Seat compile_listAsSLL compile_Person compile_Adult compile_Minor compile_Pensioner compile_listAsDLL compile_dynamicAuditorium compile_dynamicSizeMatrix compile_matrix compile_Summary compile_AuditoriumModeller compile_AuditoriumList compile_fixedSizeMatrix compile_Group compile_fixedAuditorium compile_AuditoriumDeveloper compile_flexiAuditorium compile_ticketPrinter compile_Auditorium compile_Store compile_Booking compile_AuditoriumMemento
	@echo "Compiling QT Application."
	@$(MAKE) clean -C "Qt/build-tickets-Desktop-Debug"
	@$(MAKE) -C "Qt/build-tickets-Desktop-Debug"
	@echo "Compilation Of Qt Application Finished."

compile_container: src/Container.cpp src/Container.h
	${COMPILER} -c src/Container.cpp -o src/Container.o ${FLAGS}

compile_matrix: src/Matrix.cpp src/Matrix.h
	${COMPILER} -c src/Matrix.cpp -o src/Matrix.o ${FLAGS}

compile_fixedSizeMatrix: src/FixedSizeMatrix.cpp src/FixedSizeMatrix.h
	${COMPILER} -c src/FixedSizeMatrix.cpp -o src/FixedSizeMatrix.o ${FLAGS}

compile_dynamicSizeMatrix: src/DynamicSizeMatrix.cpp src/DynamicSizeMatrix.h
	${COMPILER} -c src/DynamicSizeMatrix.cpp -o src/DynamicSizeMatrix.o ${FLAGS}


compile_list:src/List.cpp src/List.h
	${COMPILER} -c src/List.cpp -o src/List.o ${FLAGS}``

compile_listAsVector:src/ListAsVector.cpp src/ListAsVector.h
	${COMPILER} -c src/ListAsVector.cpp -o src/ListAsVector.o ${FLAGS}

compile_listAsSLL:src/ListAsSLL.cpp src/ListAsSLL.h
	${COMPILER} -c src/ListAsSLL.cpp -o src/ListAsSLL.o ${FLAGS}

compile_listAsDLL:src/ListAsDLL.cpp src/ListAsDLL.h
	${COMPILER} -c src/ListAsDLL.cpp -o src/ListAsDLL.o ${FLAGS}

compile_listAsDynamicArray: src/ListAsDynamicArray.cpp src/ListAsDynamicArray.h
	${COMPILER} -c src/ListAsDynamicArray.cpp -o src/ListAsDynamicArray.o ${FLAGS}

compile_Summary: src/Summary.cpp src/Summary.h
	${COMPILER} -c src/Summary.cpp -o src/Summary.o ${FLAGS}

compile_fixedAuditorium: src/FixedAuditorium.cpp src/FixedAuditorium.h
	${COMPILER} -c src/FixedAuditorium.cpp -o src/FixedAuditorium.o ${FLAGS}

compile_dynamicAuditorium:src/DynamicAuditorium.cpp src/DynamicAuditorium.h
	${COMPILER} -c src/DynamicAuditorium.cpp -o src/DynamicAuditorium.o ${FLAGS}

compile_flexiAuditorium:src/FlexiAuditorium.cpp src/FlexiAuditorium.h
	${COMPILER} -c src/FlexiAuditorium.cpp -o src/FlexiAuditorium.o ${FLAGS}

compile_Auditorium:src/Auditorium.cpp src/Auditorium.h
	${COMPILER} -c src/Auditorium.cpp -o src/Auditorium.o ${FLAGS}

compile_AuditoriumList: src/AuditoriumList.cpp src/AuditoriumList.h
	${COMPILER} -c src/AuditoriumList.cpp -o src/AuditoriumList.o ${FLAGS}

compile_AuditoriumModeller:src/AuditoriumModeller.cpp src/AuditoriumModeller.h
	${COMPILER} -c src/AuditoriumModeller.cpp -o src/AuditoriumModeller.o ${FLAGS}

compile_Person:src/Person.cpp src/Person.h
	${COMPILER} -c src/Person.cpp -o src/Person.o ${FLAGS}

compile_Adult:src/Adult.cpp src/Adult.h
	${COMPILER} -c src/Adult.cpp -o src/Adult.o ${FLAGS}

compile_Pensioner:src/Pensioner.cpp src/Pensioner.h
	${COMPILER} -c src/Pensioner.cpp -o src/Pensioner.o ${FLAGS}

compile_Minor:src/Minor.cpp src/Minor.h
	${COMPILER} -c src/Minor.cpp -o src/Minor.o ${FLAGS}

compile_AuditoriumDeveloper:src/AuditoriumDeveloper.cpp src/AuditoriumDeveloper.h
	${COMPILER} -c src/AuditoriumDeveloper.cpp -o src/AuditoriumDeveloper.o ${FLAGS}

compile_NullPerson:src/NullPerson.cpp src/NullPerson.h
	${COMPILER} -c src/NullPerson.cpp -o src/NullPerson.o ${FLAGS}

compile_Seat:src/Seat.cpp src/Seat.h
	${COMPILER} -c src/Seat.cpp -o src/Seat.o ${FLAGS}

compile_integer:src/Integer.cpp src/Integer.h
	${COMPILER} -c src/Integer.cpp -o src/Integer.o ${FLAGS}

compile_nullObject:src/NullObject.cpp src/NullObject.h
	${COMPILER} -c src/NullObject.cpp -o src/NullObject.o ${FLAGS}

compile_Store:src/Store.cpp src/Store.h
	${COMPILER} -c src/Store.cpp -o src/Store.o ${FLAGS}

compile_ticketPrinter:src/TicketPrinter.cpp src/TicketPrinter.h
	${COMPILER} -c src/TicketPrinter.cpp -o src/TicketPrinter.o ${FLAGS}

compile_Group:src/Group.cpp src/Group.h
	${COMPILER} -c src/Group.cpp -o src/Group.o ${FLAGS}

compile_AuditoriumMemento:src/AuditoriumMemento.cpp src/AuditoriumMemento.h
	${COMPILER} -c src/AuditoriumMemento.cpp -o src/AuditoriumMemento.o ${FLAGS}

compile_Booking:src/Booking.cpp src/Booking.h
	${COMPILER} -c src/Booking.cpp -o src/Booking.o ${FLAGS}


clean:
	@rm src/*.o
	@rm -r documentation/html
	@rm -r documentation/latex
	@clear
	@echo "Cleaned all object files!"

documentation:
	@echo "Compiling documentation..."
	@$(MAKE) -C documentation	#Executes make in a directory
	@echo "Finished compiling documentation!"

valgrind:
	valgrind src/a.out

gdb:
	gdb src/a.out

run:
	src/a.out
