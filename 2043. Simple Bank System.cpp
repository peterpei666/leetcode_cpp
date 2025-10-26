#include <iostream>
#include <algorithm>
using namespace std;

class Bank
{
private:
    vector<long long> temp;
    int n;
    
public:
    Bank(vector<long long>& balance)
    {
        temp = balance;
        n = (int)balance.size();
    }
    
    bool transfer(int account1, int account2, long long money)
    {
        if (account1 > n || account2 > n || temp[account1 - 1] < money)
        {
            return false;
        }
        temp[account1 - 1] -= money;
        temp[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money)
    {
        if (account > n)
        {
            return false;
        }
        temp[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money)
    {
        if (account > n || temp[account - 1] < money)
        {
            return false;
        }
        temp[account - 1] -= money;
        return true;
    }
};
