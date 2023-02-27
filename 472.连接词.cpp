/*
 * @Author: jklash
 * @Description: 连接词
 * @Date: 2021-12-28 16:10:32
 * @LastEditors: jklash
 * @LastEditTime: 2021-12-28 17:14:40
 */
/*
 * @lc app=leetcode.cn id=472 lang=cpp
 *
 * [472] 连接词
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
// 定义字典树
struct Trie {
    bool isEnd;
    vector<Trie *> children;
    Trie() {
        this->children = vector<Trie *>(26, nullptr);
        this->isEnd = false;
    }
};

class Solution {
public:
    Trie* trie = new Trie();

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        sort(words.begin(), words.end(), [&](const string& a, const string& b) {
            return a.size() < b.size();
        });
        for (int i = 0; i < words.size(); ++i) {
            string w = words[i];
            if (w.size() == 0) {
                continue;
            }
            if (dfs(w, 0)) {
                ans.emplace_back(w);
            } else {
                insert(w);
            }
        }
        return ans;
    }

    bool dfs(const string& w, int start) {
        if (w.size() == start) return true;
        Trie* node = trie;
        for (int i = start; i < w.size(); ++i) {
            char c = w[i];
            int idx = c - 'a';
            node = node->children[idx];
            if (node == nullptr) {
                return false;
            }
            if (node->isEnd) {
                if (dfs (w, i + 1))
                    return true;
            }
        }
        return false;
    }

    // 字典树插入
    void insert(const string& w) {
        Trie* node = trie;
        for (int i = 0; i < w.size(); ++i) {
            char c = w[i];
            int idx = c - 'a';
            // 判断为空，新建节点
            if (node->children[idx] == nullptr) {
                node->children[idx] = new Trie();
            }
            // 判断不为空，指向下一个节点
            node = node->children[idx];
        }
        // 全部插入完成，进行标记
        node->isEnd = true;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> words {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
    vector<string> ans;
    ans = s.findAllConcatenatedWordsInADict(words);
    cout << "[";
    for (auto& a : ans) {
        cout << a << ",";
    }
    cout << "\b \b]" << endl;
    return 0;
}
