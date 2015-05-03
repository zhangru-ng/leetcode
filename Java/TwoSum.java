// Given an array of integers, find two numbers such that they add up to a specific target number.

// The function twoSum should return indices of the two numbers such that they add up to the target,
// where index1 must be less than index2. Please note that your returned answers (both index1 and index2) 
// are not zero-based.

// You may assume that each input would have exactly one solution.

// Input: numbers={2, 7, 11, 15}, target=9
// Output: index1=1, index2=2 

public class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> table = new HashMap<Integer,Integer>();
		int[] result = new int[2];
		int size = nums.length;
		for (int i = 0; i < size; i++) {
			int difference = target - nums[i];
			if(table.containsKey(difference)) {
				result[0] = 1 + table.get(difference);
				result[1] = 1 + i;
				break;
			} else {
				table.put(nums[i], i);
			}
		}		 
		return result;	    
    }
}