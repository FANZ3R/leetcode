class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {

        int n=queries.size();

        vector<int> ans(n,0);

        for(int i=0;i<n;i++)
        {
            int val=0;
            for(int k=queries[i][0];k<=queries[i][1];k++)
            {
                val^=arr[k];

            }
            ans[i]=val;
        }

        return ans;


        
    }
};