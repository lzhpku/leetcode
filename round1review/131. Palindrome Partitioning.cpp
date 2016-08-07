public class Solution {
    public List<List<String>> partition(String s) {
        int len = s.length();
        List<List<String>> [] result = new List[len + 1];
        result[0] = new ArrayList<List<String>>();
        result[0].add(new ArrayList<String>());
        boolean [][] pair = new boolean [len][len];
        for(int end = 0; end < s.length(); end ++) {
            result[end + 1] = new ArrayList<List<String>>();
            for(int start = 0; start <= end; start ++) {
                if(s.charAt(start) == s.charAt(end) && (end - start <= 1 || pair[start + 1][end - 1])) {
                    pair[start][end] = true;
                    String str = s.substring(start, end + 1);
                    for(List<String> r : result[start]) {
                        List<String> ri = new ArrayList<String> (r);
                        ri.add(str);
                        result[end + 1].add(ri);
                    }
                }
            }
        }
        return result[len];
    }
}