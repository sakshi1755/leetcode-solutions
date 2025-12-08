class Solution {
public:
   bool isprime(int n){
    if(n==1)return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)return false;
    }
    return true;
   }
    bool completePrime(int num) {
        // vector<int>isprime(num+1,true);
        // isprime[1]=false;
        // for(int i=2;i<=sqrt(num);i++){
        //     if(isprime[i]){
        //         for(int j=i*2;j<=num;j+=i){
        //         isprime[j]=false;
        //         }
        //     }
            
            
        // }
        //142  ..142....//2,4,1 
        vector<int>number;
        while(num>0){
            number.push_back(num%10);
            num=num/10;
            
        }
        reverse(number.begin(),number.end());
        int n=number.size();
        int start=0;
        for(int i=0;i<n;i++){
            start=start*10+number[i];
            if(!isprime(start))return false;
        }
        start=0;
        //142
        //2
        //4*10+2=42;
        //1*100
        int j=1;
        for(int i=n-1;i>=0;i--){
              start=j*number[i]+start;
            j*=10;
            if(!isprime(start))return false;
            
        }
        return true;
        
        
    }
};