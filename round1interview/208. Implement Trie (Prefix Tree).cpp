class TrieNode {
public:
    // // Initialize your data structure here.
    // vector<TrieNode *> children;
    // bool isleaf;
    
    // TrieNode() {
    //     for(int i = 0; i < 26; i ++)
    //         children.push_back(NULL);
    //     isleaf = false;
    // }
    TrieNode ** children;
    bool isleaf;
    // Initialize your data structure here.
    TrieNode() {
    	children = new TrieNode * [26];
    	isleaf = false;
    	for(int i = 0; i < 26; i ++)
    		children[i] = NULL;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        int level = 0;
        TrieNode * node = root;
        while(level < word.size()) {
            int index = word[level] - 'a';
            if(node -> children[index] == NULL)
                node -> children[index] = new TrieNode();
            node = node -> children[index];
            level ++;
        }
        node -> isleaf = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        int level = 0;
        TrieNode * node = root;
        while(level < word.size()) {
            int index = word[level] - 'a';
            if(node -> children[index] == NULL)
                return false;
            node = node -> children[index];
            level ++;
        }
        return node -> isleaf;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int level = 0;
        TrieNode * node = root;
        while(level < prefix.size()) {
            int index = prefix[level] - 'a';
            if(node -> children[index] == NULL)
                return false;
            node = node -> children[index];
            level ++;
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