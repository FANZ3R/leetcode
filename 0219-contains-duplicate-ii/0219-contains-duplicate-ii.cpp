class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        //abs(i-j)<=k ka mtlb window size tera k hai
        //muje isme sliding window toh uske karung ahi but i will need to 
        //keep a set to keep track of already seen elements


        int n = nums.size();

        int i=0;
        int j=0;

        unordered_set<int> st;

        while(j<n)
        {
            if(abs(j-i)>k)
            {
                //toh shrink karunga window ko
                st.erase(nums[i]);
                i++;
            }

            if(st.find(nums[j])!=st.end())
            {
                return true;
            }

            st.insert(nums[j]);
            j++;

        }


        return false;


    }
};