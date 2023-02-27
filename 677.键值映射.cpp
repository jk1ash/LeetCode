/*
 * @lc app=leetcode.cn id=677 lang=cpp
 *
 * [677] 键值映射
 */
#include <iostream>
#include <unordered_map>
using namespace std;
// @lc code=start
class MapSum {
public:
    unordered_map<string, int> map;
    unordered_map<string, int> prefixmap;
    MapSum() {

    }
    
    void insert(string key, int val) {
        int delta = val;
        if (map.count(key)) {
            delta -= map[key];
        }
        map[key] = val;
        for (int i = 1; i <= key.size(); ++i) {
            prefixmap[key.substr(0, i)] += delta;
        }
    }
    
    int sum(string prefix) {
        return prefixmap[prefix];
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// @lc code=end

