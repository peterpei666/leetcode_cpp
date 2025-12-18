#include <iostream>
#include <algorithm>
using namespace std;

int prime[50000];
int i = 0;

class Solution
{
public:
    int largestPrime(int n)
    {
        function<bool(int)> isPrime = [&](int x) -> int
        {
            for (int p = 0; p < i; p++)
            {
                if (prime[p] > sqrt(x))
                {
                    break;
                }
                if (x % prime[p] == 0)
                {
                    return false;
                }
            }
            return true;
        };
        
        if (i == 0)
        {
            prime[0] = 2;
            i++;
            for (int p = 3; p <= 500000; p += 2)
            {
                if (isPrime(p))
                {
                    prime[i] = p;
                    i++;
                }
            }
        }
        int total = 0;
        int ans = 0;
        for (int p = 0; p < i; p++)
        {
            total += prime[p];
            if (total > n)
            {
                break;
            }
            if (isPrime(total))
            {
                ans = total;
            }
        }
        return ans;
    }
};
