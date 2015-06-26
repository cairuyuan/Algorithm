package n209;
public class Solution {
	
	public static void main(String[] args) {
		int[] nums = {2,3,1,2,4,3};
		System.out.println(new Solution().minSubArrayLen(7, nums));
	}
	
    public int minSubArrayLen(int s, int[] nums) {
    	
        if(nums == null || nums.length <= 0||s <= 0) return 0;
    	if(nums.length == 1) return 1;
    	
    	int l = 0, r = 0, sum = nums[0],m = nums.length + 1;
    	while(r < nums.length){
    		if(sum < s ){
    			if( ++r != nums.length) sum += nums[r];
    		}else{
    			m = Math.min(m, r-l+1);
    			sum -= nums[l++];
    		}
    	}
    	if(m == nums.length + 1) m = 0;
    	
    	return m;
    }

}
