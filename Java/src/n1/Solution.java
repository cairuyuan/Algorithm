package n1;

import java.util.HashMap;
/*
 * 和hashTable类似，不同步版本
 * */
public class Solution {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] a ={0,4,3,0};
		
		int[] ret = new Solution().twoSum(a, 0);
		System.out.print(ret[0]+ "  " + ret[1]);
	}
	
	public int[] twoSum(int[] nums, int target) {
        
		int[] ret = new int[2];
		HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
		for(int i = 0 ; i < nums.length; i += 1){
			map.put(nums[i],i);
		}
		
		for(int i = 0 ; i < nums.length; i += 1){
			Integer j = map.get(target - nums[i]);
			if(j != null){
				if(j == i) continue;
				
				ret[0] =1+( j > i ? i : j) ;
				ret[1] =1+( j > i ? j : i) ;
				break;
			}
		}
		
		return ret;
    }
}
