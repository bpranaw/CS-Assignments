CC = g++

EXE_FILE = wumpus_game

all: $(EXE_FILE)

$(EXE_FILE): main.o event.h wumpus.o pit.o bat.o gold.o room.o gameplay.o
	$(CC) main.o event.h wumpus.o pit.o bat.o gold.o room.o gameplay.o -o $(EXE_FILE)

main: 
	$(CC) -c main.cpp	

event:
	$(CC) -c event.h

wumpus:
	$(CC) -c wumpus.h wumpus.cpp

pit:
	$(CC) -c pit.h pit.cpp

bat: 
	$(CC) -c bat.h bat.cpp

gold: 
	$(CC) -c gold.h gold.cpp

room:
	$(CC) -c room.h room.cpp

gameplay:
	$(CC) -c gameplay.h gameplay.cpp

clean:
	rm -f *.o *.gch $(EXE_FILE)

