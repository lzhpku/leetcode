This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “makes”, word2 = “coding”, return 1.
Given word1 = "makes", word2 = "makes", return 3.

public class Solution {
    public int shortestWordDistance(String[] words, String word1, String word2) {
        long ret = 0x7ffffffe, p1 = ret, p2 = -ret;
        boolean same = word1.equals(word2);
        for(int i = 0; i < words.length; i ++) {
            if(words[i].equals(word1)) {
                if(same) {
                    p1 = p2;
                    p2 = i;
                }
                else
                    p1 = i;
            }
            if(words[i].equals(word2))
                p2 = i;
            if(p1 != -1 && p2 != -1)
                ret = Math.min(ret, Math.abs(p1 - p2));
        }
        return (int)ret;
    }
}