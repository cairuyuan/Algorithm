package n11;
public class Solution {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	public int maxArea(int[] height) {
		int size = height.length;  
        int left = 0, right = size-1;  
        int max = 0; 
		while(left < right)  
        {  
            int minheight = height[left] > height[right]?height[right]:height[left];  
            int tmp = minheight*(right-left);  
            max = max > tmp ? max : tmp;  
            if(height[left]<height[right])left++;  
            else right--;  
        }  
        return max;  
    }
}
