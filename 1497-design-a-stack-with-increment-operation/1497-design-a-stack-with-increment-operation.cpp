class CustomStack {
public:
    int K=0;

    vector<int> num;
    CustomStack(int maxSize) {
        K=maxSize;
    }
    
    void push(int x) {

        if(num.size()<K)
        {    
            num.push_back(x);
        }
       
       return;


        
    }
    
    int pop() {

        if(num.size()>0)
        {
            int x=num[num.size()-1];
            num.pop_back();

            return x;
        }

        return -1;
        
    }
    
    void increment(int k, int val) {
        
        if(k>num.size())
        {
            for(int &x:num)
            {
                x+=val;
            }
        }

        else
        {
            for(int i=0;i<k;i++)
            {
                num[i]+=val;
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */