#define mod 1000000007

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> v(n+1, 0);    // ye bta rha h ki nth day pr kitne logo secret pata chala na ki kitne logo ko pta h
        v[1] = 1;

        for(int i=1; i<=n; i++)
        {
            int x = v[i];
            for(int z=i+delay; z<=n && z<i+forget; z++)
            {
                v[z] = (v[z] + x)%mod;
            }
        }

        int ans = 0;
        for(int z=n; z>n-forget; z--)
        {
            // cout<<v[z]<<endl;
            ans = (ans + v[z])%mod;
        }
        
        return ans;
    }
};