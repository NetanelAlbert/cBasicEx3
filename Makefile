all: isort txtfind

isort: isort_f/main.o isort_f/insertionSort.o
	gcc isort_f/main.o isort_f/insertionSort.o -o isort

isort_f/main.o: isort_f/main.c isort_f/insertionSort.h
	gcc -Wall -c isort_f/main.c
	mv main.o isort_f/

isort_f/insertionSort.o: isort_f/insertionSort.c
	gcc -Wall -c isort_f/insertionSort.c
	mv insertionSort.o isort_f/

txtfind: txtfind_f/stringFunctions.o txtfind_f/main.o
	gcc txtfind_f/stringFunctions.o txtfind_f/main.o -o txtfind

txtfind_f/main.o: txtfind_f/main.c txtfind_f/stringFunctions.h
	gcc -Wall -c txtfind_f/main.c
	mv main.o txtfind_f/

txtfind_f/stringFunctions.o: txtfind_f/stringFunctions.c
	gcc -Wall -c txtfind_f/stringFunctions.c
	mv stringFunctions.o txtfind_f/

.PHONY: all clean

clean:
		rm -f isort_f/*.o txtfind_f/*.o isort txtfind
