CC=g++
EXE_FILE = multdivRun

all:$(EXE_FILE)

$(EXE_FILE): multdiv.o multdiv.h program.cpp
	$(CC) multdiv.o program.cpp -o $(EXE_FILE)

multdiv.o: multdiv.h multdiv.cpp
	$(CC) -c multdiv.cpp

clean:
	rm -f *.o $(EXE_FILE)

