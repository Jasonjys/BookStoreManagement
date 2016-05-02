OBJ = main.o BMScontrol.o UImanager.o BookArray.o Course.o Book.o Product.o Eraser.o Laptop.o Pencil.o User.o BuyBehaviour.o

all: clean bms

a4:	$(OBJ)
	g++ -o bms $(OBJ)

main.o:	main.cc
	g++ -c main.cc

BMScontrol.o:	BMScontrol.cc BMScontrol.h defs.h
	g++ -c BMScontrol.cc

UImanager.o:	UImanager.cc UImanager.h 
	g++ -c UImanager.cc

BookArray.o:	BookArray.cc BookArray.h Book.h
	g++ -c BookArray.cc

Course.o:	Course.cc Course.h defs.h
	g++ -c Course.cc

Book.o:	Book.cc Book.h defs.h
	g++ -c Book.cc

Product.o: Product.cc Product.h defs.h
	g++ -c Product.cc

Eraser.o: Eraser.cc Eraser.h defs.h
	g++ -c Eraser.cc

Laptop.o: Laptop.cc Laptop.h defs.h
	g++ -c Laptop.cc

Pencil.o: Pencil.cc Pencil.h defs.h
	g++ -c Pencil.cc

User.o: User.cc User.h
	g++ -c User.cc

BuyBehaviour.o: BuyBehaviour.cc BuyBehaviour.cc
	g++ -c BuyBehaviour.cc

clean:
	rm -f *.o bms