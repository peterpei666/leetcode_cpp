#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

class FoodRatings
{
private:
    struct cmp
    {
        bool operator()(const pair<int,string>& a,const pair<int,string>& b)
        {
            if(a.first!=b.first)
            {
                return a.first<b.first;
            }
            return a.second>b.second;
        }
    };
    
public:
    unordered_map<string,priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>> list;
    unordered_map<string,pair<int,string>> rate;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings)
    {
        for(int i=0;i<foods.size();i++)
        {
            rate[foods[i]]={ratings[i],cuisines[i]};
            list[cuisines[i]].push({ratings[i],foods[i]});
        }
    }
    
    void changeRating(const string& food, int newRating)
    {
        rate[food].first=newRating;
        list[rate[food].second].push({newRating,food});
    }
    
    string highestRated(const string& cuisine)
    {
        while(list[cuisine].top().first!=rate[list[cuisine].top().second].first)
        {
            list[cuisine].pop();
        }
        return list[cuisine].top().second;
    }
};
