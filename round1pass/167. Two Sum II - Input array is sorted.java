Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int ret [] = new int [2];
        ret[0] = 0;
        ret[1] = numbers.length - 1;
        while(ret[0] < ret[1]) {
            int temp = numbers[ret[0]] + numbers[ret[1]];
            if(temp == target) {
                ret[0] ++;
                ret[1] ++;
                return ret;
            }
            else if(temp < target)
                ret[0] ++;
            else
                ret[1] --;
        }
        return new int[2];
    }
}