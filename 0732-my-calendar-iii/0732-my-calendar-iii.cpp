class MyCalendarThree {
public:

    //muje basically har time point pe simultaneous kitne max event hai wo batana hai
    //aur ek global max maintain karke rakhna 
    //agr kam ayega toh global max hi send karna hai

    //aur muje har time stamp pe events ko add karna ya ghatana maintain karna hai
    //toh mai har event ke starting point pe events ko 1 se badha dunga
    //aur mai har event ke end point pe events ko 1 se ghata dunga

    //ek map maintain karlunga events jo ki har time stamp pe active events batayega

    map<int,int> events;
    int maxi=0;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {

        events[startTime]++;
        events[endTime]--;

        int activeEvents=0;

        for(auto it:events)
        {
            activeEvents+=it.second;
            maxi = max(maxi,activeEvents);
        }

        return maxi;
        
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */