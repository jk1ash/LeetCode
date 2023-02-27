/*
 * @lc app=leetcode.cn id=211 lang=java
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start
class WordDictionary {

    class TrieNode {
        boolean end;
        TrieNode[] tn = new TrieNode[26];
    }

    TrieNode root;

    public WordDictionary() {
        root = new TrieNode();
    }
    
    public void addWord(String word) {
        TrieNode p = root;
        for(int i = 0; i < word.length(); i++) {
            int n = word.charAt(i) - 'a';
            if (p.tn[n] == null)
                p.tn[n] = new TrieNode();
            p = p.tn[n];
        }
        p.end = true;
    }
    
    public boolean search(String word) {
        return dfs(word, root, 0);
    }

    public boolean dfs(String word,  TrieNode p, int index) {
        int len = word.length();
        if (len == index)
            return p.end;
        char c = word.charAt(index);
        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (p.tn[i] != null && dfs(word, p.tn[i], index + 1))
                    return true;
            }
            return false;
        } else {
            int n = c - 'a';
            if (p.tn[n] == null)
                return false;
            return dfs(word, p.tn[n], index + 1);
        }
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */
// @lc code=end

