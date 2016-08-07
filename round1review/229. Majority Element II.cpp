public class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int num1 = 0, num2 = 0, count1 = 0, count2 = 0;
        for(int i = 0; i < nums.length; i ++) {
            if(count1 != 0 && nums[i] == num1) {
                count1 ++;
                continue;
            }
            if(count2 != 0 && nums[i] == num2) {
                count2 ++;
                continue;
            }
            if(count1 == 0) {
                num1 = nums[i];
                count1 ++;
                continue;
            }
            if(count2 == 0) {
                num2 = nums[i];
                count2 ++;
                continue;
            }
            count1 --;
            count2 --;
        }
        int n1 = 0, n2 = 0;
        for(int i = 0; i < nums.length; i ++) {
            if(count1 > 0 && nums[i] == num1)
                n1 ++;
            if(count2 > 0 && nums[i] == num2)
                n2 ++;
        }
        ArrayList<Integer> ret = new ArrayList<Integer>();
        if(n1 > (nums.length / 3))
            ret.add(num1);
        if(n2 > (nums.length / 3))
            ret.add(num2);
        return ret;
    }
}