#include<bits/stdc++.h>

using namespace std;
static long long myPow(long long x, int n)
{
    /*
        Binary Exponentiation
        my Pow(x,n)
        -> For Even powers, such as 5^20, this can be written as (5^2)^20/2 => (25)^10
        -> For Odd powers, such as 5^21, we need additional multiplication as 5 * (5^2)^20/2

        TC = O (log(n))
    */
    long long mod = 1e9 + 7;
    long long ans = 1;
    long long original = n;

    long long absN = n;

    while (absN > 0) {

        // Odd Case: Reduce Power by one and multiply number with ans
        if (absN % 2 == 1) {
            absN--;
            ans = (ans * x) % mod;
        }
        else {    // Even Case: Reduce power by half, and multiply number with itself
            absN /= 2;
            x = (x * x) % mod;
        }
    }

    return ans;
}

int main() {
    // OPTIMIZE STANDARD I/O OPERATIONS (Prevents TLE)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    cout<< myPow(2,n);

    return 0;
}