class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k < 1 || t < 0)
            return false;
        map<long, long> m;
        for(int i = 0; i < nums.size(); i ++) {
            long num = (long)nums[i] - INT_MIN;
            long bucket = num / ((long) t + 1);
            if(m.find(bucket) != m.end()
                || (m.find(bucket - 1) != m.end() && num - m[bucket - 1] <= t)
                || (m.find(bucket + 1) != m.end() && m[bucket + 1] - num <= t))
                return true;
            if(m.size() >= k) {
                long bucket = ((long) nums[i - k] - INT_MIN) / ((long) t + 1);
                m.erase(bucket);
            }
            m[bucket] = num;
        }
        return false;
    }
};