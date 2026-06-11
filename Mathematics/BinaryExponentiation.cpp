#include "bits/stdc++.h"

double myPow(double x, int n) 
    {
        /*
            Binary Exponentiation
            my Pow(x,n)
            -> For Even powers, such as 5^20, this can be written as (5^2)^20/2 => (25)^10
            -> For Odd powers, such as 5^21, we need additional multiplication as 5 * (5^2)^20/2

            TC = O (log(n))
        */
        double ans = 1.0;
        int original = n;
        
        long long absN = n;
        // If power is negative, make it positive
        if (absN < 0) {
            absN = -absN;
        }

        while (absN > 0) {

            // Odd Case: Reduce Power by one and multiply number with ans
            if (absN % 2 == 1) {
                absN--;
                ans = ans * x;
            } else {    // Even Case: Reduce power by half, and multiply number with itself
                absN /= 2;
                x = x * x;
            }
        }

        // Handle when power was originally negative
        if (original < 0)    ans = 1.0 / ans;

        return ans;
    }