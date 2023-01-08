class Solution {

void solve(vector<int> alice, int i, int n, int score, int &maxscore, vector<int> temp, vector<int> &ans)
{
    if(i<0 || n <= 0)
    {
        if(score > maxscore)
        {
            maxscore = score;
            ans = temp;
        }
        return;
    }

    if(i == 0)
    {
        temp[i] = n;
        solve(alice, i-1, 0, score, maxscore, temp, ans);
    }
    else
    {
        if(n > alice[i])
        {
            temp[i] = alice[i]+1;
            solve(alice, i-1, n-(alice[i]+1), score+i, maxscore, temp, ans);
            temp[i] = 0;
            solve(alice, i-1, n, score, maxscore, temp, ans);
        }
        else
            solve(alice, i-1, n, score, maxscore, temp, ans);
    }
}

public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> ans(12, 0);
        vector<int> temp(12, 0);
        int maxscore = 0;

        solve(aliceArrows, 11, numArrows, 0, maxscore, temp, ans);
        return ans;
    }
};