class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        wordList.insert(endWord);
        queue<string> toVisit;
        addWords(beginWord, wordList, toVisit);
        int dist = 2;
        while(!toVisit.empty()) {
            int num = toVisit.size();
            for(int i = 0; i < num; i ++) {
                string word = toVisit.front();
                toVisit.pop();
                if (word == endWord)
                    return dist;
                addWords(word, wordList, toVisit);
            }
            dist ++;
        }
    }

    void addWords(string word, unordered_set<string>& wordDict, queue<string>& toVisit) {
        wordDict.erase(word);
        for(int p = 0; p < word.size(); p ++) {
            char letter = word[p];
            for(int k = 0; k < 26; k ++) { 
                word[p] = 'a' + k;
                if(wordDict.find(word) != wordDict.end()) {
                    toVisit.push(word);
                    wordDict.erase(word);
                }
            }
            word[p] = letter;
        } 
    } 
};