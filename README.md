# Sieve of Eratosthenes Parallelized
This project parallelizes the sieve of eratosthenes in aims of getting speedups on both multicore and GPU systems. 

## How to run 
You can compile the code by running ``make`` to use the provided makefile. 

### Multicore OpenMP
* Set the number of threads using the environment variable ``OMP_NUM_THREADS`` 
  * eg.  ``export OMP_NUM_THREADS=x`` where x is the number of threads. 

### GPU OpenACC
* You will need access to a GPU and specifically Nvidia, there is limited support for other manufacturers. 
* Optionally set the environment variable ``PGI_ACC_TIME`` to ``1`` to get more detailed analysis on how the code was parallelized
  * ``export PGI_ACC_TIME=1``



