#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    struct pair_hash
    {
        size_t operator()(const pair<int, int>& p) const
        {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };
    
    bool isPathCrossing(string path)
    {
        unordered_set<pair<int,int>,pair_hash> visited;
        int x=0,y=0;
        visited.insert({0,0});
        for(char c:path)
        {
            switch(c)
            {
                case 'N':
                    y++;
                    break;
                case 'S':
                    y--;
                    break;;
                case 'E':
                    x++;
                    break;;
                case 'W':
                    x--;
                    break;;
            }
            if(visited.count({x,y}))
            {
                return true;
            }
            visited.insert({x,y});
        }
        return false;
    }
};
