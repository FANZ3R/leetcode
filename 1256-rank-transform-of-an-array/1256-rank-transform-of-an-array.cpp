class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        vector<int> arr2;
        arr2=arr;
        sort(arr2.begin(),arr2.end());

        unordered_map<int,int> mp;

        int count=1;

        for( int x: arr2)
        {
            if(mp.find(x)==mp.end())
            {
                mp[x]=count;
                count++;
            }
            
        }
        vector<int> ans;

        for(int i=0;i<arr.size();i++)
        {
            ans.push_back(mp[arr[i]]);
        }

        return ans;
        
    }
};