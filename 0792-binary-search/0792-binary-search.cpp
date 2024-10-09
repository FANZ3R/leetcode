class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();

        int l=0;
        int r=n-1;

        while(l<=r)//binary search ka condition tera
        {
            int mid= l+(r-l)/2;

            if(nums[mid] == target)
            {
                return mid;
            }

            else if(nums[mid]>target)//mtlb target left mei hai
            {
                r=mid-1;

            }
            else
            {
                l=mid+1;
            }
        }

        return -1;
        
    }
};