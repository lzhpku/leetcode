public class Solution {
    public boolean isIsomorphic(String s, String t) {
        if(s.length() != t.length())
            return false;
        HashMap <Character, Character> hm = new HashMap <Character, Character> ();
        HashMap <Character, Character> rhm = new HashMap <Character, Character> ();
        for(int i = 0; i < s.length(); i ++) {
            if(hm.containsKey(s.charAt(i)) && hm.get(s.charAt(i)) != t.charAt(i))
                return false;
            if(!hm.containsKey(s.charAt(i)))
                hm.put(s.charAt(i), t.charAt(i));
            if(rhm.containsKey(t.charAt(i)) && rhm.get(t.charAt(i)) != s.charAt(i))
                return false;
            if(!rhm.containsKey(t.charAt(i)))
                rhm.put(t.charAt(i), s.charAt(i));
        }
        return true;
    }
}