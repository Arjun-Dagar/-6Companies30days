class Solution {
public:
    int trailingZeroes(int n) {
        
        // just find no. of 5 in factors fot 1 to n numbers
        
        int x = 5, ans = 0;
        while(x<=n)
        {
            int temp = x;
            while(temp >0 && temp%5 == 0)
            {
                ans++;
                temp/=5;
            }

            x += 5;
        }
        
        return ans;
    }
};