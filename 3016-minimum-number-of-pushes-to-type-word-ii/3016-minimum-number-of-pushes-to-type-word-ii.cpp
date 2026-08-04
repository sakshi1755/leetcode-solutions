class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        map<char,int>freq;
        for(int i=0;i<n;i++){
            freq[word[i]]++;
        }
        priority_queue<int>pq;
        for(int i=0;i<26;i++){
            pq.push(freq['a'+i]);

        }
        int i=0;
        int j=1;
        long long ans=0;
        while(!pq.empty() ){
            int t=pq.top();
            pq.pop();
            ans+=t*j;
            i++;
            if(i>7){
                j++;
                i=0;
            }

        }
        return ans;
        
    }
};