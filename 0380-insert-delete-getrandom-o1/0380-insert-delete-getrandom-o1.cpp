class RandomizedSet {
public:

    //dekh ek vector lunga store karne ke lie elements 
    //but agr delete karna hai muje toh wo o(n) jaa skta toh iske lie
    //muje index store karna padega toh uske lie mai map lelunga jo muje 
    //index btadega element ka jo delete karna hai muje

    vector<int> set;
    unordered_map<int,int> mp;


     
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        //agr mai phle se hi us eleemnt ko find karta toh insert nhi karpaunga
        //toh
        if(mp.find(val)!=mp.end())
        return false;

        set.push_back(val);
        mp[val]=set.size()-1;
        return true;
        
    }
    
    bool remove(int val) {
        //ab remove mai hamesa peeche se hi karunga 
        //toh i will have to first check if i can remove this number

        if(mp.find(val)==mp.end())
        return false;

        int idx=mp[val];
        int lastele= set.back();

        set.back()=val;
        set[idx]=lastele;
        mp[lastele]=idx;

        set.pop_back();
        mp.erase(val);

        return true;
        
    }
    
    int getRandom() {

        int n=set.size();

        //ab mai random index generate karunga 0 to n-1 tak ka  toh
        //uske lie rand() but %n lagayenge taaki wo range 0 to n-1 me hi aaye
        int random= rand()%n;
        return set[random];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */