class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(numsDivide.begin(), numsDivide.end());

        int val = numsDivide[0];
        for(int i=1; i<numsDivide.size(); i++){
            val = gcd(val,numsDivide[i]);
        }

        sort(nums.begin(), nums.end());

        int c = 0;
        if(nums[0] > val) return -1;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]>val) break;

            if((val%nums[i]) != 0)
                c++;
            else
                break;
        }

        if(c == nums.size())
            return -1;
        
        return c;
    }

    static int gcd(int a, int b)
    {
        if (a == 0)
            return b;
        
        return gcd(b % a, a);
    }
};