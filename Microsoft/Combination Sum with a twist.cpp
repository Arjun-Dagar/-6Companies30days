class Solution {

void solve(int k, int n, int i, vector<int> temp, vector<vector<int>> &ans)
{   
    if(n<0 || k<0)
        return;
    if(i > 9)
    {
        if(n == 0 && k == 0)
            ans.push_back(temp);
        return;
    }

    solve(k, n, i+1, temp, ans);
    temp.push_back(i);
    solve(k-1, n-i, i+1, temp, ans);
}

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        solve(k, n, 1, {}, ans);
        return ans;
    }
};