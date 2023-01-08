class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        unordered_map<int, int> mp;
        int ans = INT_MAX;

        int i=0, j=1;
        mp[cards[0]]++;

        while(j<n)
        {
            mp[cards[j]]++;

            while(mp[cards[j]] > 1)
            {
                ans = min(ans, j-i+1);
                mp[cards[i]]--;
                i++;
            }
            j++;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};