all: clean compile
compile:
	mkdir bin
	nvc++ -mp src/classic_eratosthenes_openmp.cpp -o bin/classic_eratosthenes_openmp_nvc
	g++ src/classic_eratosthenes_openmp.cpp -fopenmp -o bin/classic_eratosthenes_openmp_gcc
	nvc++ -mp src/segmented_eratosthenes_openmp.cpp -o bin/segmented_eratosthenes_openmp_nvc
	g++ src/segmented_eratosthenes_openmp.cpp -fopenmp -o bin/segmented_eratosthenes_openmp_gcc
	nvc++ -acc -ta=tesla -Minfo=accel src/segmented_eratosthenes_openacc.cpp -o bin/segmented_eratosthenes_openacc
clean: 
	rm -r bin
