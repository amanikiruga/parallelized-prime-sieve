#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <cmath>
#include <iomanip>
#include <openacc.h>
#include "timer.h"

using namespace std;
//prints all prime numbers less than n
int SegmentedSieveOfErastothenes(int n, int S)

{

    StartTimer();

    vector<int> primes;
    int nsqrt = sqrt(n);

    vector<char> is_prime(nsqrt + 2, true);

    for (int i = 2; i <= nsqrt; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
            for (int j = i * i; j <= nsqrt; j += i)
                is_prime[j] = false;
        }
    }
    int primes_size = primes.size();

    int primes_c_array[primes_size];
    for (int i = 0; i < primes_size; i++)
        primes_c_array[i] = primes[i];
    char block[S];
    int result = 0;

#pragma acc data copyin(primes_c_array, primes_size) create(block)
    {

#pragma acc parallel loop
        for (int k = 0; k <= n / S; k++)
        {

#pragma acc loop
            for (int i = 0; i < S; i++)
                block[i] = true;
            int start = k * S;

#pragma acc loop
            for (int m = 0; m < primes_size; m++)
            {
                int p = primes_c_array[m];
                int start_idx = (start + p - 1) / p;

                // #pragma acc loop vector
                for (int j = max(start_idx, p) * p - start; j < S; j += p)
                    block[j] = false;
            }

            if (k == 0)
                block[0] = block[1] = false;
            /* 
            #pragma acc loop reduction(+:result) 
            for (int i = 0; i < S && start + i <= n; i++)
            {
                if (block[i])
                    result++;
            }
	    */
        }
    }

    double runtime = GetTimer();

    cout << "Time taken by program is : " << fixed << runtime / 1000 << setprecision(5) << endl;
    return result;
}

int main(int argc, char **argv)
{
    const int S = 10000;    // 131072;
    int n = atoll(argv[1]); // n is the number of primes to be printed
    int primes = SegmentedSieveOfErastothenes(n, S);
    cout << "Number of primes less than " << n << " is " << primes << endl;
    return 0;
}