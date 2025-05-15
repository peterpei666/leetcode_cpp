#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB)
    {
        int n=(int)energyDrinkA.size();
        long long A[3];
        long long B[3];
        A[0]=energyDrinkA[0];
        B[0]=energyDrinkB[0];
        A[1]=A[0]+energyDrinkA[1];
        B[1]=B[0]+energyDrinkB[1];
        for(int i=2;i<n;i++)
        {
            A[i%3]=max(A[(i-1)%3],B[(i-2)%3])+energyDrinkA[i];
            B[i%3]=max(A[(i-2)%3],B[(i-1)%3])+energyDrinkB[i];
        }
        return max(A[(n-1)%3],B[(n-1)%3]);
    }
};
