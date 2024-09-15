class Solution {
public:
    int countTriplets(vector<int>& arr) {

        int n=arr.size();

        int ans=0;

        for(int i=0;i<n;i++)
        {
            int t=arr[i];

            for(int j=i+1;j<n;j++)
            {
                t^=arr[j];
                if(t==0)
                ans+=j-i;
            }
        }
        
        return ans;
    }
};