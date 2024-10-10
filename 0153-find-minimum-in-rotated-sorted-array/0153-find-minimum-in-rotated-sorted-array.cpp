class Solution {
public:
    int findMin(vector<int>& nums) {
        
        //dekh sorted array ke lie binary search toh mind mei aana hi chaiye
        //ab dekh mai  mid nikaalunga
        //aur compare karunga right ya r wale element se
        //if arr[mid] > arr [r] toh mid ko discard toh krenge hi
        //kyuki minimum chaiye toh minimum mtlb right side pe hai theeke
        //toh l=mid+1;
        // but agr mera arr[mid]<=arr[r] hia toh mid ko discard nhi krenge kyuki
        //ye possible answer hoskta
        //toh thn r=mid and not mid-1
        //theeke ab aise case mei na jab bhi minimum ya maximum nikaalte instead of
        //specific element toh l aur r mai upr jaise condition hoskte
        //and while waale ko ham likhte while(l<r) instead of while(l<=r)
        //kyuki fir wo terminate hi nhi hota

        int l=0;
        int r=nums.size()-1;

        while(l<r)//kyuki min ya max find karre hai
        {
            int mid= l+(r-l)/2;

            if(nums[mid]> nums[r])
            {
                //toh aise mei mid ko to discard karna hi hai
                l=mid+1;
            }
            else if(nums[mid]<=nums[r])//iski jagah tu else bhi laga skta hai isme
            {
                r=mid;
            }
        } 

        return nums[r];
    }
};