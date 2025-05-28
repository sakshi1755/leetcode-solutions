class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n=apples.size();
         int day=0;
          int eaten=0;
    while(day<n ||!pq.empty() ) {   
        if(day<n &&  apples[day] > 0)  pq.push({day+days[day],apples[day]});
        
       
       
        
            while(!pq.empty()&&day>=pq.top().first){
                    pq.pop();
            }
            if (!pq.empty()){
            pair<int,int>temp=pq.top();
            pq.pop();
            int exd=temp.first;
            int count=temp.second;
            eaten++;
            count--;
            if(count>0){
                pq.push({exd,count});
            }
            }
            day++;}
     return eaten;    
    }
       
    
};