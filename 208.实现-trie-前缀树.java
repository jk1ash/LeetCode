/*
 * @lc app=leetcode.cn id=208 lang=java
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {

    class TrieNode {
        boolean end;
        TrieNode[] tn = new TrieNode[26];
    }

    TrieNode root;

    public Trie() {
        root = new TrieNode();
    }
    
    public void insert(String word) {
        TrieNode p = root;
        for (int i = 0; i < word.length(); i++) {
            int n = word.charAt(i) - 'a';
            if (p.tn[n] == null)
                p.tn[n] = new TrieNode();
            p = p.tn[n];
        }
        p.end = true;
    }
    
    public boolean search(String word) {
        TrieNode p = root;
        for (int i = 0; i < word.length(); i++) {
            int n = word.charAt(i) - 'a';
            if (p.tn[n] == null)
                return false;
            p = p.tn[n];
        }
        return p.end == true;
    }
    
    public boolean startsWith(String prefix) {
        TrieNode p = root;
        for (int i = 0; i < prefix.length(); i++) {
            int n = prefix.charAt(i) - 'a';
            if (p.tn[n] == null)
                return false;
            p = p.tn[n];
        }
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
// @lc code=end

