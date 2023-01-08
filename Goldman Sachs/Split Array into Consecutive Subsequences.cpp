class Compare{
    public:
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        if(a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    }
};

class Solution {

public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        // pq.push({nums[0], 1});

        int i=0;
        while(i<n)
        {
            if(pq.empty())
            {
                pq.push({nums[i], 1});
                i++;
            }
            else
            {
                int curr = pq.top().first;
                int siz = pq.top().second;
                if(curr == nums[i] - 1)
                {
                    pq.pop();
                    pq.push({nums[i], siz+1});
                    i++;
                }
                else if(curr == nums[i])
                {
                    pq.push({nums[i], 1});
                    i++;
                }
                else
                {
                    if(siz < 3)
                        return false;
                    else
                        pq.pop();
                }
            }
            
        }

        while(!pq.empty())
        {
            if(pq.top().second < 3)
                return false;
            pq.pop();
        }

        return true;
    }
};