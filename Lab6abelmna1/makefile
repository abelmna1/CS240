# Brian Burke and Adam Belmnahia 
#Binghamton University - Fall 2016
all: Tree

Tree: TreeInst.o main.o ThreeAryTreeInst.o
	g++ -Wall -std=c++11 TreeInst.o ThreeAryTreeInst.o main.o -o Tree -g

TreeInst.o: TreeInst.cpp Tree.cpp
	g++ -Wall -std=c++11 -c TreeInst.cpp -g

ThreeAryTreeInst.o: ThreeAryTreeInst.cpp ThreeAryTree.cpp
	g++ -Wall -std=c++11 -c ThreeAryTreeInst.cpp -g

main.o: main.cpp
	g++ -Wall -std=c++11 -c main.cpp -g

clean:
	rm -f *.o *~
	rm -f Tree
