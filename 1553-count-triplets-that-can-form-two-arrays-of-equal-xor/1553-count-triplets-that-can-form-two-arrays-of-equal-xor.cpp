class Solution {
public:
    int countTriplets(vector<int>& arr) {

        int n=arr.size();

        int ans=0;

        for(int i=0;i<n;i++)
        {
            int t=arr[i];

            for(int k=i+1;k<n;k++)
            {
                t^=arr[k];
                if(t==0)
                    ans+=k-i;//dekh beech mei mai j daalskta hu jitne valid honge toh triplet banane ke lie aayenge merpe k-i 
            }
        }
        
        return ans;
    }
};