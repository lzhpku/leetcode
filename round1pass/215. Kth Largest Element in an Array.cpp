class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        int l = 0, r = nums.size() - 1;
        while(true) {
            int temp = nums[r];
            while(l < r) {
                while(l < r && nums[l] <= temp)
                    l ++;
                nums[r] = nums[l];
                while(l < r && nums[r] >= temp)
                    r --;
                nums[l] = nums[r];
            }
            nums[r] = temp;
            if(r == k)
                return nums[r];
            if(r > k) {
                l = 0;
                r = r - 1;
            }
            else {
                l = r + 1;
                r = nums.size() - 1;
            }
        }
        return 0;
    }
};