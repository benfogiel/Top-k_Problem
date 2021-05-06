main: main.o hashTable.o minHeap.o
	g++ -g -Wall -std=c++11 main.o minHeap.o hashTable.o -o main -lssl -lcrypto

testMinHeap: testMinHeap.o minHeap.o
	g++ -g -Wall -std=c++11  minHeap.o testMinHeap.o

testHashTable: hashTable.o
	g++ -g -Wall -std=c++11 hashTable.o testHashTable -lssl -lcrypto

main.o: main.cpp
	g++ -c main.cpp

hashTable.o: hashTable.cpp 
	g++ -c hashTable.cpp 

minHeap.o: minHeap.cpp
	g++ -c minHeap.cpp

testMinHeap.o: testMinHeap.cpp
	g++ -c testMinHeap.cpp

clean:
	rm -f main main.o minHeap.o hashTable.o testMinHeap.o

