class Solution {
public:
    long long dividePlayers(vector<int>& skill) {

        if(skill.size()==2)
        return skill[0]*skill[1];

        long long sum=0;

        unordered_map<int,int> mp;

        for(int x:skill)
        {
            sum+=x;
            mp[x]++;
        }

        int n=skill.size();
        int teams=n/2;

        if(sum%teams!=0)
        return -1;

        long long target=sum/teams;

        long long ans=0;

        for(int j=0;j<n;j++ )
        {

            long long remaining =target-skill[j];

            if(mp[skill[j]]==0 && mp[remaining]==0)
            {
                continue;
            }

            mp[skill[j]]--;

            if(mp.find(remaining)!=mp.end())
            {
                mp[remaining]--;
                ans+=(skill[j]*remaining);
                teams--;
            }
        }

        if(teams==0)
        return ans;

        return -1;

        


        
    }
};