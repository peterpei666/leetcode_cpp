#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class ExamRoom
{
public:
    set<int> seats;
    int N;
    
    ExamRoom(int n)
    {
        N=n;
    }
    
    int seat()
    {
        if(seats.empty())
        {
            seats.insert(0);
            return 0;
        }
        int prev=-1;
        int md=0;
        int p=0;
        if(*seats.begin()!=0)
        {
            md=*seats.begin();
        }
        for(auto i=seats.begin();i!=seats.end();i++)
        {
            if(prev!=-1)
            {
                int dist=(*i-prev)/2;
                if(dist>md)
                {
                    md=dist;
                    p=prev+dist;
                }
            }
            prev=*i;
        }
        if(*seats.rbegin()!=N-1)
        {
            int dist=N-1-*seats.rbegin();
            if(dist>md)
            {
                md=dist;
                p=N-1;
            }
        }
        seats.insert(p);
        return p;
    }
    
    void leave(int p)
    {
        seats.erase(p);
    }
};
