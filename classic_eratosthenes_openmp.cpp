// C++ program for implementation of Sieve of Atkin
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <iomanip>

using namespace std;
// #define uns64 unsigned long long
// Prints all prime numbers smaller

int SieveOfErastothenes(int n)

{
    clock_t start, end;
    start = clock();
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    #pragma omp parallel for schedule(dynamic) shared(is_prime)
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i] && (long long)i * i <= n)
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    int count = 0;
    #pragma omp parallel for shared(is_prime) reduction(+:count)
    for (int i = 0; i < n; i++)
    {
        if (is_prime[i])
            count++;
    }
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(5) << endl;
    return count;
}

int main(int argc, char **argv)
{

    int n = atoll(argv[1]); // n is the number of primes to be printed
    int primes = SieveOfErastothenes(n);
    cout << "Number of primes less than " << n << " is " << primes << endl;
    return 0;
}