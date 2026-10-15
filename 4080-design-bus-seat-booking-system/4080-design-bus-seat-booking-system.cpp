class BusBooking {
public:
    int r;
    map<string, long long>mp;
    long long s;
    long long tt;
    BusBooking(int n) {
        r=n;
        tt=0;
        s=0;
        
        
    }
    
    void toggle(string seat) {
        if(!mp[seat]){
            char cc=seat[0];
            s++;
            if(cc=='B' || cc=='C'){
                
                tt++;
                mp[seat]=1;
            }
            else{
                string newseat;
                newseat=seat;
                if(cc=='A')newseat[0]='B';
                if(cc=='D')newseat[0]='C';
                if(!mp[newseat])mp[seat]+=1;
                else mp[seat]+=3;
                tt+=mp[seat];



            }
        }
        else{
            s--;
            tt-=mp[seat];
            mp[seat]=0;
        }
    }
    
    int getTotalTime() {
        return tt;
        
    }
    
    int getMinTime() {
        return s;
        
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */