class Solution {
public:
    int singleNumber(vector<int>& nums) {

        unordered_map<int,int> mp;

        for(int x:nums)
        {
            mp[x]++;
        }

        //int ans=0;
        for(auto t:mp)
        {
            if(t.second==1)
            return t.first;
        }

        return 0;
        
    }
};