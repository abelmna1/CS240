#
# Specifiy the target
all:    Belmnahia_Adam_Hello


# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
Belmnahia_Adam_Hello:   Hello_Class.o  Belmnahia_Adam_Hello.o
        g++  Hello_Class.o Belmnahia_Adam_Hello.o  -o Belmnahia_Adam_Hello.exe

#Belmnahia_Adam_Hello.o
        #g++  Belmnahia_Adam_Hello.o  -o Belmnahia_Adam_Hello.exe 

# Specify how the object files should be created from source files
Belmnahia_Adam_Hello.o: Belmnahia_Adam_Hello.cpp
        g++ -c Belmnahia_Adam_Hello.cpp
Hello_Class.o: Hello_Class.cpp
        g++ -c Hello_Class.cpp 

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
        rm -f *.o Belmnahia_Adam_Hello.exe
