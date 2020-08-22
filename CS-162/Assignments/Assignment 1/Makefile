#CC represents the compiler (we're using g++)
CC = g++

#EXE_FILE represents the executable file name
EXE_FILE = runWizard

#Will compile all three files
all: $(EXE_FILE)

#Compling all three files together
$(EXE_FILE): catalog.h catalog.cpp runWizard.cpp
	$(CC) catalog.h catalog.cpp runWizard.cpp -o $(EXE_FILE)

#Compiles just the header file and functions file
catalog.o: catalog.h
	$(CC) -c catalog.h catalog.cpp

#compiles the driver file
runWizard.o: catalog.h
	$(CC) -c runWizard.cpp
	
#Deletes the executable file
clean:
	rm -f *.p $(EXE_FILE)
