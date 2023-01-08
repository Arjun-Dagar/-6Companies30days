class Solution {
    
    bool solve(vector<vector<int>> &v)
    {
        int a = (v[1][1]-v[0][1])*(v[1][1]-v[0][1]) + (v[1][0]-v[0][0])*(v[1][0]-v[0][0]);
        int b = (v[2][1]-v[1][1])*(v[2][1]-v[1][1]) + (v[2][0]-v[1][0])*(v[2][0]-v[1][0]);
        int c = (v[3][1]-v[2][1])*(v[3][1]-v[2][1]) + (v[3][0]-v[2][0])*(v[3][0]-v[2][0]);
        int d = (v[3][1]-v[0][1])*(v[3][1]-v[0][1]) + (v[3][0]-v[0][0])*(v[3][0]-v[0][0]);

        int x = (v[2][1]-v[0][1])*(v[2][1]-v[0][1]) + (v[2][0]-v[0][0])*(v[2][0]-v[0][0]);
        int y = (v[3][1]-v[1][1])*(v[3][1]-v[1][1]) + (v[3][0]-v[1][0])*(v[3][0]-v[1][0]);
        
        if(a!=0 && a == b && b == c && c == d && x == y && x == 2*a)
            return true;
        return false;
    }
    
    static bool cmp(vector<int> &a, vector<int>&b)
    {
        if(a[0]<b[0])
            return true;
        if(a[0] == b[0])
            return a[1] < b[1];
        return false;
    }
    
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> v = {p1, p2, p3, p4};
        
        //brute force
        
//         for(int i=0; i<4; i++)
//         {
//             for(int j=i; j<4; j++)
//             {
//                 swap(v[i], v[j]);
//                 if(solve(v))
//                     return true;
//                 swap(v[i], v[j]);
//             }
//         }
        
//         return false;
        
        
        //optimal
        sort(v.begin(), v.end(), cmp);
        swap(v[2], v[3]);
        // vector<vector<int>> temp = {v[0], v[1], v[3], v[2]};
        return solve(v);
    }
};