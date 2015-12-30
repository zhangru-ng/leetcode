// Given an array of numbers nums, in which exactly two elements appear only once
// and all the other elements appear exactly twice. Find the two elements that appear
// only once.

// For example:

// Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

// Note:
// The order of the result is not important. So in the above example, [5, 3] is also correct.
// Your algorithm should run in linear runtime complexity. Could you implement it using only
// constant space complexity?

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int acc = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        int mask = acc & ~(acc - 1);
        vector<int> output{
            accumulate(nums.begin(), nums.end(), 0,
                [mask](int acc, int elem) {return elem & mask ? acc ^ elem : acc;}),
            accumulate(nums.begin(), nums.end(), 0,
                [mask](int acc, int elem) {return elem & mask ? acc : acc ^ elem;})
        };
        return output;
    }
};
