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


class WordDictionary {
private:
    TrieNode* root;
    
public:

    WordDictionary() {
        root = new TrieNode();
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
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

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return dfs(root, word, 0);
    }
    
    bool dfs(TrieNode * p, string word, int index) {
        if(index == word.size())
            return p -> isleaf;
        if(word[index] == '.') {
            for(int i = 0; i < 26; i ++)
                if(p -> children[i] != NULL)
                    if(dfs(p -> children[i], word, index + 1))
                        return true;
            return false;
        }
        else {
            int i = word[index] - 'a';
            if(p -> children[i] == NULL)
                return false;
            return dfs(p -> children[i], word, index + 1);
        }
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");