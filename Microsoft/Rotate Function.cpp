class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int tsum = 0;
        int n = nums.size();
        for(auto i:nums)
            tsum += i;
        
        int currsum = 0;
        for(int i=1; i<n; i++)
            currsum += (nums[i]*i);
        
        int ans = currsum;
        for(int i=n-1; i>0; i--)
        {
            int newsum = currsum + tsum - (n*nums[i]);
            currsum = newsum;

            ans = max(ans, newsum);
        }

        return ans;
    }
};