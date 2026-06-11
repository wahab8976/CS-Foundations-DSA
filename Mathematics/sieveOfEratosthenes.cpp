#include "bits/stdc++.h"

vector<int> sieveOfEratosthenes(int n) {
        /*
            Sieve of Eratosthenes
            Finds all prime numbers up to n.
            -> Create a boolean array where index represents the number.
            -> Assume all numbers are prime initially (set to true).
            -> Start from 2 (first prime), and mark all of its multiples as false (not prime).
            -> Move to the next unmarked number and repeat.

            TC = O(n * log(log(n)))
        */
        
        // Edge Case: There are no prime numbers less than 2
        if (n < 2) return {};

        // Vector to track prime status. Index 0 to n (size n + 1).
        // Initially, we assume every number is prime (true).
        vector<bool> isPrime(n + 1, true);
        
        // 0 and 1 are explicitly not prime numbers
        isPrime[0] = false;
        isPrime[1] = false;

        // Optimize: We only need to loop up to the square root of n.
        // If a number has a factor greater than its square root, 
        // it must also have a matching factor smaller than its square root.
        for (int i = 2; i * i <= n; i++) {
            
            // Prime Case: If 'i' is still true, it's a prime number!
            if (isPrime[i] == true) {
                
                // Mark all multiples of 'i' as false (not prime)
                // Optimize: Start marking from i * i because smaller multiples
                // (like 2*i, 3*i) have already been marked by smaller primes.
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Collect all numbers that managed to stay 'true'
        vector<int> primes;
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }

        return primes;
    }