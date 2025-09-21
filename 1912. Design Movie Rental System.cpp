#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

class MovieRentingSystem
{
private:
    set<pair<int, pair<int, int>>> rented;
    map<int, set<pair<int, int>>> movie_price;
    map<pair<int, int>, int> mp;
    
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries)
    {
        for (auto& m : entries)
        {
            mp[{m[0], m[1]}] = m[2];
            movie_price[m[1]].insert({m[2], m[0]});
        }
    }
    
    vector<int> search(int movie)
    {
        auto& s = movie_price[movie];
        if (s.empty())
        {
            return {};
        }
        vector<int> ans;
        for (auto it = s.begin(); it != s.end() && ans.size() < 5; it++)
        {
            ans.push_back(it->second);
        }
        return ans;
    }
    
    void rent(int shop, int movie)
    {
        int price = mp[{shop, movie}];
        movie_price[movie].erase({price, shop});
        rented.insert({price, {shop, movie}});
    }
    
    void drop(int shop, int movie)
    {
        int price = mp[{shop, movie}];
        movie_price[movie].insert({price, shop});
        rented.erase({price, {shop, movie}});
    }
    
    vector<vector<int>> report()
    {
        vector<vector<int>> ans;
        for (auto it = rented.begin(); it != rented.end() && ans.size() < 5; it++)
        {
            ans.push_back({it->second.first,it->second.second});
        }
        return ans;
    }
};
