class CustomStack {
public:

    //dekh isse phle wale approach mei mere push and pop toh O(1) jaare the
    //but increment waale mei mai loop lagake krra tha toh wo worst case mei o(k) jaa skta
    //toh interviewer pooch skta hai usko bhi O(1) me dede
    //toh ek vector toh implementation ke lie rakhunga hi 
    //ek dusra bhi rakhunga for increments

    //lazy propagation method bhi kehte is increments wale method ko



    vector<int> st;
    vector<int> increments;

    int K;
    CustomStack(int maxSize) {
        K=maxSize;
    }
    
    void push(int x) {
        if(st.size()<K)
        {
            st.push_back(x);
            increments.push_back(0);//kyki abhi kux increment krne ko hai hi nahi
        }
        
    }
    
    int pop() {

        //pop tabhio karunga jab wo khaali ni higa
        if(st.size()==0)
        return -1;

        
        int x= st[st.size()-1];
        

        //aur muje increment ko propagate karna hoga mtlb ye wala increment puraane wale mei jud jaayega
        //kyuki mai increment last wale index ke lie store krra hu har ek ko nhi increase krra simultaneously
        // jab jroorat pdegi tb increment kardunga

        int idx=st.size()-1;

        if(idx>0)
        increments[idx-1] += increments[idx];

        //ab muje jo top mei hogi value usko increment ke sath return karna hoga
        x+=increments[idx];
        st.pop_back();
        increments.pop_back();

        return x;
        
    }
    
    void increment(int k, int val) {

        int idx=min(k,(int)st.size())-1;

        if(idx>=0)
        increments[idx]+=val;
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */