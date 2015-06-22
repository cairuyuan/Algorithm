package n205;
import java.util.HashMap;

public class Solution { 
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		boolean b = new Solution().isIsomorphic("", "");
		System.out.println(b);
	}

	public boolean isIsomorphic(String s, String t) {
		return this.test(s, t) && this.test(t, s);
    }
	
	private boolean test(String s, String t){
        HashMap<Character, Character> hm = new HashMap<Character,Character>();
        for(int i = 0; i < s.length() ; i += 1 ){
        	Character c = hm.get(s.charAt(i));
        	if(c == null){
        		hm.put(s.charAt(i), t.charAt(i));
        	}
        	else if(c != t.charAt(i)){
        			return false;
        	}
        }
        return true;
	}
}
