class MyCalendar {
public:

    
    set<pair<int,int>> st;

    //ab isko mai aur optimise kar skta hu instead of checking by iterating through the whole list
    //I can just check lower bound and compare it with the current pair

    //agr mera lower bound ka start<curr node ka end mtlb overlap hai

    //uar mai previous iterationb pe bhi jaunga
    //agr mera previous iteration ka end> currnode ke start toh mtlb overlap hai 

    MyCalendar() {

        
       

        
    }
    
    bool book(int start, int end) {

        //pehle i will find the first eventhat starts after or st the same time of {start,end}

        //mai lower bound se nikaal lunga element >=start or agr start se nhi milta toh end pe check karega ye code
        auto it = st.lower_bound({start,end});

        //it kispe point karega element >= start 
        //aur agr nhi milta toh wo fir element >=end pe dhundega 

        //aur agr wo bhi nhi milta toh end pe point karega yaani ki st.end() pe point karega

        if(it != st.end() && it->first<end)
        {
            return false;
        }

        //ab previous wale se check karunga ki previous se na overlap hojaaye
        //toh agr previous ke lie condiiton ye hai ki previous hona bhi choaye
        //agr st.begin() pe point karraha hoga toh previous nahi milega muje

        if(it!=st.begin())
        {
            //phle prev wale pe point karte hai ab
            auto prevIt = prev(it);
            if(prevIt->second>start)
            {
                return false;
            }
        }

        //aur agr nhi hua flase toh vlaid hai to insert kardunga apne set mei
        st.insert({start,end});
        return true;

        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */




// ye upar wala mera tha optimised approach 
































//ab isiko brute force se karta toh har element pe iterate karke check karta overalpa ka hai ya nahi
//uska code-:

class MyCalendar {
public:

    
    set<pair<int,int>> st;

    MyCalendar() {

        
       

        
    }
    
    bool book(int start, int end) {

        for(auto t:st)
        {
            int x=t.first;
            int y=t.second;

           // iska ye condition hota check karne 
           //naye wale interval ka start already present ke end se compare karte
           //aur already present ke start ko naye ke end se compare karte

           if(start<y && x<end)
           return false;

        //    else if(start==x && end==y)
        //    return false;
        }

        st.insert({start,end});

        return true;

        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
