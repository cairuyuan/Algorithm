package n198;

public class Solution {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int[] a = {226,174,214,16,218,48,153,131,128,
				17,157,142,88,43,37,157,43,221,191,68,
				206,23,225,82,54,118,111,46,80,49,245,
				63,25,194,72,80,143,55,209,18,55,122,
				65,66,177,101,63,201,172,130,103,225,
				142,46,86,185,62,138,212,192,125,77,
				223,188,99,228,90,25,193,211,84,239,
				119,234,85,83,123,120,131,203,219,10,
				82,35,120,180,249,106,37,169,225,54,
				103,55,166,124};
		
		int sum = new Solution().rob(a);
		System.out.println("sum = " + sum);
	}
	
	public int rob(int[] nums) {
		return this.robin(nums, 0);
    }
	
	private int robin(int[] a, int l){
		
		if(l >= a.length)     return 0;
		if(l == a.length - 1) return a[l];
		
		int s1 = a[l]   + robin(a, l+2);
		int s2 = a[l+1] + robin(a, l+3);
		
		return s1 > s2 ? s1:s2;
	}
}