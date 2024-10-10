class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {

        //isme ya to mai indeice s ko sort kar skta on the basis of 
       // nums ki value using comparator aur fir min index find karlunga from the 
       //ya toh stack mei push kardunga elements jo chote honge
       //aur push tbtk karunga jab tk sbse chota element milta aur uska 
       //index push karte jaunga
       //fir peeche ke index se traverse karunga j=n-1 se agr nums[j]>nums[st.top()]
       //jabtak aisa hai mtlb while loop laga ta rhunga max width=max(maxwidth,j-st.top())

       stack<int> st;

       for(int i=0;i<nums.size();i++)
       {
        if(st.empty() || nums[i]<nums[st.top()])
        {
            st.push(i);
        }
       }


       //ab mai peeche se traverse karunga
       int maxwidth=0;

       for(int j=nums.size()-1;j>=0;j--)
       {
            while(!st.empty() && nums[j]>=nums[st.top()]) //jab bhi stack ke elements ko access karraha !st.empty jaroor chk kiya akr
            {
                maxwidth=max(maxwidth,j-st.top());
                st.pop();
            }
       }

       return maxwidth;
        
    }
};