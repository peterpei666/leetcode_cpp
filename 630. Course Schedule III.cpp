#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int scheduleCourse(vector<vector<int>>& courses)
    {
        sort(courses.begin(), courses.end(), [&](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
        priority_queue<int> pq;
        int total = 0;
        int n = (int)courses.size();
        for (int i = 0; i < n; i++)
        {
            if (total + courses[i][0] <= courses[i][1])
            {
                pq.push(courses[i][0]);
                total += courses[i][0];
            }
            else
            {
                if (!pq.empty() && pq.top() > courses[i][0])
                {
                    total -= pq.top();
                    pq.pop();
                    pq.push(courses[i][0]);
                    total += courses[i][0];
                }
            }
        }
        return (int)pq.size();
    }
};
