CC = g++

EXE_FILE = pizzapizza

all: $(EXE_FILE)

$(EXE_FILE):
	$(CC) menu.h menu.cpp pizza.h pizza.cpp restaurant.h restaurant.cpp program.cpp -o $(EXE_FILE)

pizza: 
	$(CC) -c pizza.h pizza.cpp 

restaurant:
	$(CC) -c restaurant.h restaurant.cpp

menu:
	$(CC) -c menu.h menu.cpp

program:
	$(CC) -c program.cpp
clean:
	rm -f *.o $(EXE_FILE)
