class Solution {
public:
    string getHint(string secret, string guess) {
        int n = guess.size();
        unordered_map<char, int> mp;
        for(auto i:secret)
            mp[i]++;
        
        int cow = 0, bull =0;
        for(auto i:guess)
        {
            if(mp.find(i) != mp.end() && mp[i] > 0)
                cow++, mp[i]--;
        }

        for(int i=0; i<n; i++)
        {
            if(secret[i] == guess[i])
                bull++;
        }

        string ans;
        ans += to_string(bull);
        ans += 'A';
        cow -= bull;
        ans += to_string(cow);
        ans += 'B';

        return ans;
    }
};