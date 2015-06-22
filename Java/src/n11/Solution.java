package n11;

public class Solution {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] height = {0,1,0,2,1,0,1,3,2,2,2,1};
		
		System.out.println("sum: "+ new Solution().maxArea(height));
	}
	public int maxArea(int[] height) {
        
		int[] m = new int[height.length];
		int t = -1, sum = 0;;
		for(int i = 0; i< height.length; i += 1){
			m[i] = t = (t > height[i] ) ? t : height[i];
		}
		t = -1;
		for(int i = height.length - 1; i >= 0; i -= 1){
			t = (t > height[i] ) ? t : height[i];
			m[i] = m[i] > t ? t : m[i];
			sum += m[i] - height[i];
		}
		return sum;
    }
}
