make: 
	nvc++ -mp classic_eratosthenes_openmp.cpp -o classic_eratosthenes_openmp_nvc
	g++ classic_eratosthenes_openmp.cpp -fopenmp -o classic_eratosthenes_openmp_gnu
	nvc++ -mp segmented_eratosthenes_openmp.cpp -o segmented_eratosthenes_openmp_nvc
	g++ segmented_eratosthenes_openmp.cpp -fopenmp -o segmented_eratosthenes_openmp_gnu
	nvc++ -acc -ta=tesla -Minfo=accel segmented_eratosthenes_openacc.cpp -o segmented_eratosthenes_openacc

