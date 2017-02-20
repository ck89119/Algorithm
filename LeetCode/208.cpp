class TrieNode {
 public:
  // Initialize your data structure here.
  TrieNode() {
    for (int i = 0; i < 26; ++i)
      next[i] = NULL;
    end = false;
  }
  TrieNode *next[26];
  bool end;
};

class Trie {
 public:
  Trie() {
    root = new TrieNode();
  }

  // Inserts a word into the trie.
  void insert(string word) {
    TrieNode *cur = root;
    for (auto ch: word) {
      int i = ch - 'a';
      if (cur->next[i] == NULL) {
        TrieNode *node = new TrieNode();
        cur->next[i] = node;
      }
      cur = cur->next[i];
    }
    cur->end = true;
  }

  // Returns if the word is in the trie.
  bool search(string word) {
    TrieNode *cur = root;
    for (auto ch: word) {
      int i = ch - 'a';
      if (cur->next[i] == NULL) return false;
      cur = cur->next[i];
    }
    return cur->end;
  }

  // Returns if there is any word in the trie
  // that starts with the given prefix.
  bool startsWith(string prefix) {
    TrieNode *cur = root;
    for (auto ch: prefix) {
      int i = ch - 'a';
      if (cur->next[i] == NULL) return false;
      cur = cur->next[i];
    }
    return true;
  }

 private:
  TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
