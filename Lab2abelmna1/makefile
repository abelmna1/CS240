#
# Specifiy the target
all:  Voter
        

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
Voter:	BelmnahiaAdamVoterFunctions.o  Lab2.o 
	g++ BelmnahiaAdamVoterFunctions.o Lab2.o  -o Voter



# Specify how the object files should be created from source files
BelmnahiaAdamVoterFunctions.o:	BelmnahiaAdamVoterFunctions.cpp
	g++ -c BelmnahiaAdamVoterFunctions.cpp
Lab2.o: Lab2.cpp
	g++ -c Lab2.cpp 

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o Voter
