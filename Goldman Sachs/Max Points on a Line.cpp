class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1) return 1;
        
        int ans = INT_MIN;
        
        for(int i=0; i<n; i++)
        {
            unordered_map<double, int> mp;
            int maxi = INT_MIN;
            for(int j=i+1; j<n; j++)
            {
                int x1 = points[i][0];
                int y1 = points[i][1];
                
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                double slope, c;
                if((x2-x1) == 0) slope = INT_MAX;
                else slope = (double) (y2-y1)/(x2-x1);
                
                mp[slope]++;
                maxi = max(maxi, mp[slope]);
            }
            
            ans = max(ans, maxi+1);
        }
        
        return ans;
    }
};