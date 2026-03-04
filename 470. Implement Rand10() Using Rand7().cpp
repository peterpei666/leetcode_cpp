#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int rand10(void)
    {
        while (1)
        {
            int num = (rand7() - 1) * 7 + rand7();
            if (num <= 40)
            {
                return num % 10 + 1;
            }
        }
    }
};
