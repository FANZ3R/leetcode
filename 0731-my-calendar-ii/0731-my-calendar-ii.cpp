class MyCalendarTwo {
public:

//dekh very important agr muje intervals wale quesiton mei overlap wala type kux nikaalna hota hai toh
//iske lie 2 fromulas very important hai
//phla to check overlaps between two regions (x1,y1) & (x2,y2)
//toh if max(x1,x2) < min(y1,y2)  toh overlap hota hai 


//and to find the overlapped region we do 
//{max(x1,x2) , min(y1,y2)}


//ab is quesiton pe aate toh dekh muje triple overlap check karna hai
//toh mai 2 vector banaunga ek toh first tme booking wala jo overall_booking bolunga mai use
//fir double overlapping wala kyuki isi mei check karke mei triple overlap nikaal paunga

vector<pair<int,int>> overall_bookings;
vector<pair<int,int>> double_overlaps;
    
    
    //overlap check krne ke lie function
    bool check_overlap(int start1,int end1, int start2, int end2)
    {
        if(max(start1,start2) < min(end1,end2))
        return true;

        return false;
    }

    //ab overlapped region find karne ke lie function

    pair<int,int> find_overlapped_region(int start1, int end1 ,int start2, int end2)
    {
        return {max(start1,start2), min(end1,end2)};
    }
    
    
    MyCalendarTwo() {
        
    }


    
    bool book(int start, int end) {
        
        //pehle triple booking ke lie check karunga double overlaps mei
        for(pair<int,int> region: double_overlaps)
        {
            if(check_overlap(region.first,region.second,start,end))
            return false;

        }

        //ab triple overlap nhii aarha toh check karunga ki double overlap toh nhi banara kahi

        for(pair<int,int> region: overall_bookings)
        {
            if(check_overlap(region.first,region.second,start,end))
            {
                //agr overlap aaya toh mai overlapped region ko double overlap mei push kardunga
                double_overlaps.push_back(find_overlapped_region(region.first,region.second,start,end));
            }

        }

        overall_bookings.push_back({start,end});
        return true;
        
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */