package n217;

import java.util.HashSet;
public class Solution {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	/*
	 * Given an array of integers, 
	 * find if the array contains any duplicates. 
	 * Your function should return true 
	 * if any value appears at least twice in the array, 
	 * and it should return false 
	 * if every element is distinct.
	 * */
	public boolean containsDuplicate(int[] nums) {
		HashSet<Integer> hs = new HashSet<Integer>();
		for(int i = 0; i <nums.length ; i += 1){
			if(hs.contains(nums[i])){
				return true;
			}else{
				hs.add(nums[i]);
			}
		}
		return false;
    }
}
