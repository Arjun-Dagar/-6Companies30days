class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int i=0, j=2;
        
        int a = 0, b = 0, c = 0, ans = 0;
        for(int z=0; z<3; z++)
        {
            if(s[z] == 'a') a++;
            if(s[z] == 'b') b++;
            if(s[z] == 'c') c++;
        }

        while(j<n && i<n)
        {
            if(a>0 && b>0 && c>0)
            {
                ans += (n-j);

                if(s[i] == 'a') a--;
                if(s[i] == 'b') b--;
                if(s[i] == 'c') c--;
                
                i++;
            }
            else
            {
                j++;

                if(s[j] == 'a') a++;
                if(s[j] == 'b') b++;
                if(s[j] == 'c') c++;
            }
        }

        return ans;
    }
};