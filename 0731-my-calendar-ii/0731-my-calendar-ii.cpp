class MyCalendarTwo {
public:
   // vector<pair<int,int>>bookings;
    int maxb;
    map<int,int>bc;
    MyCalendarTwo() {
        maxb=2;
    }
    
    bool book(int startTime, int endTime) {
        bc[startTime]++;
        bc[endTime]--;
        int totalcount=0;
       for(auto b:bc){
            totalcount+=b.second;
            if(totalcount>maxb){
                bc[startTime]--;
                bc[endTime]++;
                if(bc[startTime]==0){
                    bc.erase(startTime);

                }
                if(bc[endTime]==0){
                    bc.erase(endTime);
                }
                



                return false;
            }


       }
       return true;


        
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */