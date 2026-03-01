#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students)
    {
        int n = (int)seats.size();
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += abs(seats[i] - students[i]);
        }
        return ans;
    }
};
