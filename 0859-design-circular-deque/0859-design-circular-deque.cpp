class MyCircularDeque {
public:
//ek vecotr define karleta hu
    vector<int> nums;
    int K;//eys size batata rahega mere nums ka 
    MyCircularDeque(int k) {
        //iniitially mia K ko equal to k kardubga
        K=k;
        
    }
    
    bool insertFront(int value) {
        
        if(nums.size()<K)
        {
            nums.insert(nums.begin(),value);
            return true;
        }
        return false;
        
    }
    
    bool insertLast(int value) {
        
        if(nums.size()<K)
        {
            nums.push_back(value);
            return true;
        }

        return false;

    }
    
    bool deleteFront() {
        if(nums.size()>0)
        {
            nums.erase(nums.begin());
            return true;
        }

        return false;

        
    }
    
    bool deleteLast() {
        if(nums.size()>0)
        {
            nums.pop_back();
            return true;
            
        }
        return false;
        
    }
    
    int getFront() {
        if(nums.size()>0)
        return nums[0];

        return -1;
        
    }
    
    int getRear() {

        if(nums.size()>0)
        return nums[nums.size()-1];

        return -1;
        
    }
    
    bool isEmpty() {
        if(nums.size()==0)
        return true;

        return false;
        
    }
    
    bool isFull() {
        if(nums.size()==K)
        return true;

        return false;
        
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */