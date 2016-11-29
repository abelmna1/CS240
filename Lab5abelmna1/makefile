# Here's the flag for C++11 support and a flag asking to be warned about
# everything. 
FLAGS = -Wall -std=c++11

#all: Lab5

#Lab5: Lab5.o Sorter.o
#	g++ $(FLAGS) Lab5.o Sorter.o -o Lab5

#Sorter.o: Sorter.cpp Sorter.h
#	g++ $(FLAGS) -c Sorter.cpp -o Sorter.o

#Lab5.o: Lab5.cpp Sorter.h
#	g++ $(FLAGS) -c Lab5.cpp -o Lab5.o 



#clean:
#	rm -f *.o Lab5

all: Lab5T Lab5

Lab5T: Lab5T.o templateInst.o
	g++ $(FLAGS) Lab5T.o templateInst.o -o Lab5T -g

templateInst.o: TSorter.cpp Dog.cpp
	g++ $(FLAGS) -c templateInst.cpp -o templateInst.o -g

Lab5T.o: Lab5T.cpp 
	g++ $(FLAGS) -c Lab5T.cpp -o Lab5T.o -g

Lab5: Lab5.o Sorter.o
	g++ $(FLAGS) Lab5.o Sorter.o -o Lab5

Sorter.o: Sorter.cpp Sorter.h
	g++ $(FLAGS) -c Sorter.cpp -o Sorter.o

Lab5.o: Lab5.cpp Sorter.h
	g++ $(FLAGS) -c Lab5.cpp -o Lab5.o 


clean:
	rm -f *.o Lab5T Lab5

#all: Dog

#Dog: Dog.o DogMain.o
#	g++ Dog.o DogMain.o -o Dog

#Dog.o: Dog.cpp Dog.h
#	g++ -c Dog.cpp -o Dog.o

#DogMain.o: DogMain.cpp
#	g++ -c DogMain.cpp -o DogMain.o
