class Solution {
public:
    vector<int> lexicalOrder(int n) {

        //string ka comparator character ke basis pe karta hai

        auto lambda = [](int &a,int &b)
        {
            string x = to_string(a);
            string y = to_string(b);

            if(x<y)
            return true;

            return false;
        };

        vector<int> ans(n,0);

        for(int i=1;i<=n;i++)
        {
            ans[i-1]=i;
        }

        sort(ans.begin(),ans.end(),lambda);

        return ans;
        
    }
};