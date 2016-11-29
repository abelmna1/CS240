all: test

test: Sentence.o Word.o Story.o Paragraph.o testing.o
	g++ Sentence.o Word.o Story.o Paragraph.o testing.o -o test

Sentence.o: Sentence.cpp
	g++ -c -g Sentence.cpp
Word.o: Word.cpp
	g++ -c -g Word.cpp
Story.o: Story.cpp
	g++ -c -g Story.cpp
Paragraph.o: Paragraph.cpp
	g++ -c -g Paragraph.cpp
testing.o: testing.cpp
	g++ -c -g testing.cpp

clean:
	rm -f *.o test
