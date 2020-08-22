CC = g++

EXE_FILE = zoo_game

all: $(EXE_FILE)


#$(EXE_FILE):
#	$(CC) main.cpp zoo.h zoo.cpp animal.h animal.cpp monkey.h monkey.cpp otter.h otter.h sloth.h sloth.cpp -o $(EXE_FILE)

$(EXE_FILE): main.o zoo.o animal.o monkey.o otter.o sloth.o polar_bear.o
	$(CC) main.o zoo.o animal.o monkey.o otter.o sloth.o polar_bear.o -o $(EXE_FILE)

main: 
	$(CC) -c main.cpp	

zoo: 
	$(CC) -c zoo.h zoo.cpp

animal:
	$(CC) -c animal.h animal.cpp

monkey:
	$(CC) -c monkey.h monkey.cpp

otter: 
	$(CC) -c otter.h otter.cpp

sloth: 
	$(CC) -c sloth.h sloth.cpp

polar_bear:
	$(CC) -c polar_bear.h polar_bear.cpp

clean:
	rm -f *.o $(EXE_FILE)

