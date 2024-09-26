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

        //    if(start<y && x<end)
        //    return false;

        //    else if(start==x && end==y)
        //    return false;


        //iska ek aur tareek hota 

        if(max(start,x) < min(end,y))
        return false;
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