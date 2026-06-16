class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
          int n = nums.size();
        vector<long long> prefixSum(n + 1);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        int minLength = n + 1;
      
       
        for (int i = 0; i <= n; ++i) {
            int j = lower_bound(prefixSum.begin(), prefixSum.end(), 
                               prefixSum[i] + target) - prefixSum.begin();
            if (j <= n) {
                minLength = min(minLength, j - i);
            }
        }
        return minLength <= n ? minLength : 0;
    }
};