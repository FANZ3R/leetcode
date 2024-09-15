class Solution {
public:
    int countTriplets(vector<int>& arr) {

        vector<int> prefixXor(arr.begin(),arr.end());

        prefixXor.insert(prefixXor.begin(),0);

        int n=prefixXor.size();

        //ab m,ai prefix xor calculate kardunga
        //maine 0 isilie daala kyuki agr wapis dekhunga toh compare karsakunga
        //kyuki starting mei to 0 hi rahega

        for(int i=1;i<n;i++)
        {
            prefixXor[i]^=prefixXor[i-1];
        }

        //ab traverse karunga aur check karunga firse dekha hai ki nahi

        int ans=0;

        for(int i=0;i<n;i++)
        {
            int val=prefixXor[i];
            for(int k=i+1;k<n;k++)
            {
                if(prefixXor[k]==val)
                {
                    ans+=k-i-1;
                    //yaha pe -1 kyu kyuki maine ek extra 0 append kiya hai wo window ko hamesa badadega 1 se
                    //aur tri[plet bhi ek se badh jayenge uske reason se
                }
            }
        }

        return ans;

        
    }
};