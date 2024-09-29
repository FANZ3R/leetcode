class AllOne {
public:

//dekh isko agr sirf mai map lekr ke karugnga toh wo tle dega nhai hora hai submissions mei dkeh lena
//kyuki problem aari hai max key aur min key ki jiske lie mai baar baar iterate maar raha hu apne map mei'

//toh take care of thjis mai map toh  lunga hi to store count of each string but
//order mai maintain krne ke lie muje count ke basis pe sort bhi rakhna padega
//toh mai ek set rakh lunga aur set mei mai pair bhejunga count ka aur string ka
//agr 2 string ka count same hai toh fir wo lexigropahical order mei store hongi automatically

//but ye dhyan dena hai jab bhi mai increment karunga toh usi string ka puraana count hatana padega muje set se
//aur naya daalna hoga

//aur agr count of string  0 hojaata toh use map aur set se dono se hatana padega

    unordered_map<string ,int> count;
    
    
    set<pair<int,string>> st;
    //ye set mere stirngs ko count ke basis pe sorted rakhega kyuki ordered set hai
    //aur kisi 2 string ka count same raha toh fir string ke basis pe sorted rakhega
    //thats how ordered set works


    AllOne() {

        count.clear();        
    }
    
    void inc(string key) {

        int n=count[key];//ye n muje previous count batadega is string ka

        count[key]++;

        //ab set mei bhi daalunga but muje iska previous wala count hatana padega
        st.erase({n,key});
        
        //aur naya wala count mai daal dunga apne set mei
        st.insert({n+1,key});

        
    }
    
    void dec(string key) {

        //pehle previous count nikaa leta set mei insert aur delete karne ke lie
        int n = count[key];

        count[key]--;

        //ab iska purana wala count hata do 
        st.erase({n,key});

        //ab naya wala count tabhi daalunga agr 0 nhi hoga
        if(n-1>0)
        {
            st.insert({n-1,key});
        }
        //aur agr 0 hota hai toh map aur set dono se delete karte hai
        //but set ka check toh maine yhi pe krliya kyuki mai use daal hiu nhi raha toh map se bhi delete kar dete
        else
        {
            count.erase(key);
        }
        
    }
    
    string getMaxKey() {

        //ab dekh tera max value hoga set ke end mei
        //toh set mai 2 operation hote begin() ye first element ko point krega jo smallest count pe hoga
        //ordered set mai

        //aur last element ke lie hota hai rbegin() ye largest element ko point karega ordered set mei

        //ab important yaha pe check set aur stack mei elements ko traverse karne se phle 
        //check daalna padta ki wo empty toh nhi hai
        //aur uske lie return statement dena pdta empty ke lie
        //jaise ki yaha pe muje null return karna padega agr set empty hua toh


        if(!st.empty())
        {
        string ans = st.rbegin()->second;
        return ans; 
        }

        //warna return null

        return "";
        
    }
    
    string getMinKey() {
        
        if(!st.empty())
        {
        string ans= st.begin()->second;
        return ans;
        }
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */