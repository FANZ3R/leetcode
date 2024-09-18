class Solution {
public:
    string largestNumber(vector<int>& nums) {

        auto lambda = [] (int &x ,int &y)
        {
            string s1=to_string(x);
            string s2=to_string(y);


            if(s1+s2>s2+s1)
            return true;

            return false;
        };

        sort(nums.begin(),nums.end(),lambda);

        if(nums[0]==0)
        return "0";

        string ans;

        for(int x:nums)
        {
            ans+=to_string(x);
        }
        return ans;
        
    }
};