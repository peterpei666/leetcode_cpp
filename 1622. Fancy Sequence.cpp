#include <iostream>
#include <algorithm>
using namespace std;

class Fancy
{
private:
    vector<int> v;
    vector<int> a;
    vector<int> b;
    const int mod = 1e9 + 7;
    
    int qmul(int x, int y)
    {
        int ans = 1, cur = x;
        while (y)
        {
            if (y & 1)
            {
                ans = 1LL * ans * cur % mod;
            }
            cur = 1LL * cur * cur % mod;
            y >>= 1;
        }
        return ans;
    }
    
public:
    Fancy()
    {
        a.push_back(1);
        b.push_back(0);
    }
    
    void append(int val)
    {
        v.push_back(val);
        a.push_back(a.back());
        b.push_back(b.back());
    }
    
    void addAll(int inc)
    {
        b.back() = (b.back() + inc) % mod;
    }
    
    void multAll(int m)
    {
        a.back() = 1LL * a.back() * m % mod;
        b.back() = 1LL * b.back() * m % mod;
    }
    
    int getIndex(int idx)
    {
        if (idx < 0 || idx >= v.size())
        {
            return -1;
        }
        int ta = 1LL * qmul(a[idx], mod - 2) * a.back() % mod;
        int tb = (b.back() - 1LL * b[idx] * ta % mod + mod) % mod;
        return (1LL * ta * v[idx] % mod + tb) % mod;
    }
};
