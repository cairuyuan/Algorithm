package n202;

import java.util.HashSet;

public class Solution {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.print(new Solution().isHappy(10));
	}
	public boolean isHappy(int n) {
		HashSet<Integer> hs = new HashSet<Integer>();
		int sum, d;
		while(true){
			hs.add(n);
			sum = 0;
			System.out.println(n);
			while(n != 0){
				d = n%10;
				sum += d * d;
				n /= 10;
			}
			if( sum == 1 )  return true; 
			if( hs.contains(sum) ) return false;
			n = sum;
		}
	}
}
