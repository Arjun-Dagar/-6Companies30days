class Solution {
public:
int findUnsortedSubarray(vector<int>& nums) {
    int n = nums.size();

    int mini = INT_MAX;
    bool flag = false;

    for(int i=1; i<n; i++)
    {
        if(nums[i] < nums[i-1])
            flag = true;
        if(flag)
            mini = min(mini, nums[i]);
    }

    int maxi = INT_MIN;
    flag = false;

    for(int i=n-2; i>=0; i--)
    {
        if(nums[i] > nums[i+1])
            flag = true;
        if(flag)
            maxi = max(maxi, nums[i]);
    }

    int l = 0, r = n-1;
    while(l<n)
    {
        if(nums[l] > mini)
            break;
        l++;
    }
    while(r>=0)
    {
        if(nums[r] < maxi)
            break;
        r--;
    }

    if(r>l)
        return r-l+1;
    return 0;
}

};