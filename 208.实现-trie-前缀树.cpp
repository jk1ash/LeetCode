/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */
#include <iostream>
#include <cstring>
using namespace std;
// @lc code=start
class Trie {
public:
    bool isEnd;
    Trie* next[26];

    Trie() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }
    
    void insert(string word) {
        Trie* node = this;
        for (char w : word) {
            if (node->next[w - 'a'] == nullptr) {
                node->next[w - 'a'] = new Trie();
            }
            node = node->next[w - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie *node = this;
        for (char w : word) {
            node = node->next[w - 'a'];
            if (node == nullptr)
                return false;
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char p : prefix) {
            node = node->next[p - 'a'];
            if (node == nullptr)
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

int main(int argc, char const *argv[])
{
    Trie* obj = new Trie();
    obj->insert("apple");
    obj->insert("banana");
    bool param_1 = obj->search("apple");
    bool param_2 = obj->search("banana");
    bool param_3 = obj->startsWith("app");
    bool param_4 = obj->startsWith("ban");
    cout  << param_1 << endl;
    cout  << param_2 << endl;
    cout  << param_3 << endl;
    cout  << param_4 << endl;
    return 0;
}
