
build: main.cpp skiplist.cpp
	g++ -I./ -o skiplist main.cpp skiplist.cpp

clean:
	rm skiplist

run:
	./skiplist