all: main

main: test.o caesar.o
    g++ -o main test.o caesar.o

test.o: test.cpp lib/caesar.hpp
    g++ -c test.cpp -o test.o

caesar.o: src/caesar.cpp lib/caesar.hpp
    g++ -c src/caesar.cpp -o caesar.o

clean:
    rm -f *.o main