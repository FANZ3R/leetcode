class NumArray {
public:
    //dekh yaha pe multiple queries hai
    //aur update bhi karna hai muje apne element s 
    //fir uske baad ki queries  mei sum nikaalne ko kaha hai
    //agr update nhi hota toh i could have done this iteratively
    //but update ke lie muje efficiently krne ko yaha pe segment tree use karna hi padega


    int n;

    vector<int> segTree;

    void buildSegTree(int i, int l, int r, vector<int> &nums)
    {
        if(l==r)
        {
            segTree[i]=nums[l];
            return;

        }

        int mid= l+(r-l)/2;

        buildSegTree(2*i+1,l,mid,nums);
        buildSegTree(2*i+2,mid+1,r,nums);

        segTree[i]=segTree[2*i+1] + segTree[2*i+2];
    }

    void Updatepoint(int index, int val, int i, int l, int r)
    {
        if(l==r)
        {
            segTree[i]=val;
            return ;
        }

        int mid=l+(r-l)/2;

        if(index<=mid)
        {
            Updatepoint(index,val,2*i+1,l,mid);
        }
        
        else
        {
            Updatepoint(index,val,2*i+2,mid+1,r);
        }
        

        //ab ek value update krne ke baad poore seg tree mei change propagate hoga
        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }

    int Query(int start,int end, int i, int l,int r)
    {
        //ab isme range ka khel hota hai
        if(l>end || r<start)
        return 0;

        if(l>=start && r<=end)
        {
            return segTree[i];
        }

        int mid=l+(r-l)/2;

        //ab isme partial overalp hai agr
        //toh dono side se return query call krke sum krdunga
        //kyuki aadha left mei aur aadha right mei hoga

        return Query(start,end,2*i+1,l,mid) + Query(start,end,2*i+2,mid+1,r);
    }

    NumArray(vector<int>& nums) {
        n=nums.size();
        segTree.resize(4*n);
        buildSegTree(0,0,n-1,nums);
    }

    
    void update(int index, int val) {
        //ab isme point update query waale ki baat ki hai
        //agr updaterange query waala hota toh update range waala function likhte

        Updatepoint(index,val,0,0,n-1);
        
    }
    
    int sumRange(int left, int right) {

        //muje start and end waale mei thoda familiar hai code toh usime convert krke krdeta hiu
        int start=left;
        int end=right;

        return Query(start,end,0,0,n-1);
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */