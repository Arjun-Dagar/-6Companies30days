#define mod 1000000007

class Solution {

int rev(int x)
{
    string s = to_string(x);
    reverse(s.begin(), s.end());
    int ans = stoi(s);

    return ans;
}

public:
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int ans = 0;

        for(int i=0; i<n; i++)
        {
            int x = rev(nums[i]);
            int diff = nums[i] - x;
            
            ans = (ans + mp[diff])%mod;

            mp[diff]++;
        }

        return ans;
    }
};