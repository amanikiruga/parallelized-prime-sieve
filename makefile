all: clean 
	nvc++ -mp src/classic_eratosthenes_openmp.cpp -o bin/classic_eratosthenes_openmp_nvc
	g++ src/classic_eratosthenes_openmp.cpp -fopenmp -o bin/classic_eratosthenes_openmp_gcc
	nvc++ -mp src/segmented_eratosthenes_openmp.cpp -o bin/segmented_eratosthenes_openmp_nvc
	g++ src/segmented_eratosthenes_openmp.cpp -fopenmp -o bin/segmented_eratosthenes_openmp_gcc
	nvc++ -acc -ta=tesla -Minfo=accel src/segmented_eratosthenes_openacc.cpp src/timer.h -o bin/segmented_eratosthenes_openacc
clean: 
	rm src/classic_eratosthenes_openmp_nvc src/classic_eratosthenes_openmp_gcc
	rm src/segmented_eratosthenes_openmp_nvc src/segmented_eratosthenes_openmp_gcc src/segmented_eratosthenes_openacc
