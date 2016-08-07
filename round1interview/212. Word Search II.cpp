public class Solution {
    public List<String> findWords(char[][] board, String[] words) {
        ArrayList<String> ret = new ArrayList<String>();
        TrieNode trie = buildTree(words);
        for(int i = 0; i < board.length; i ++)
            for(int j = 0; j < board[0].length; j ++)
                dfs(board, trie, i, j, ret);
        return ret;
    }
    
    public void dfs(char [][] b, TrieNode root, int x, int y, ArrayList<String> ret) {
        if(b[x][y] == '*' || root.next[b[x][y] - 'a'] == null)
            return;
        char c = b[x][y];
        root = root.next[c - 'a'];
        if(root.word != null && !ret.contains(root.word))
            ret.add(root.word);
        
        b[x][y] = '*';
        if(x > 0)
            dfs(b, root, x - 1, y, ret);
        if(y > 0)
            dfs(b, root, x, y - 1, ret);
        if(x < b.length - 1)
            dfs(b, root, x + 1, y, ret);
        if(y < b[0].length - 1)
            dfs(b, root, x, y + 1, ret);
        b[x][y] = c;
    }
    
    public TrieNode buildTree(String [] words) {
        TrieNode root = new TrieNode();
        for(String word : words) {
            TrieNode p = root;
            for(char c : word.toCharArray()) {
                int i = c - 'a';
                if(p.next[i] == null)
                    p.next[i] = new TrieNode ();
                p = p.next[i];
            }
            p.word = word;
        }
        return root;
    }
}

    class TrieNode {
        TrieNode [] next = new TrieNode [26];
        String word;
    }