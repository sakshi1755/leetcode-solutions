class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        map<string,int>f;
        int n=chunks.size();
        int i=0;
        string currword="";
        //char prev=' ';
        while(i<n){
            int m=chunks[i].size();
            int j=0;
            while(j<m){
                if(chunks[i][j]==' '){
                      if(currword!=""){f[currword]++;
                    //   
                    
                        }
                    currword="";
                }
                else if(chunks[i][j]=='-'){
                    char prev=' ';
                    char next=' ';
                    if(j>0)prev=chunks[i][j-1];
                    else if(i>0)prev=chunks[i-1].back();
                    if(j<m-1)next=chunks[i][j+1];
                    else if(i<n-1)next=chunks[i+1][0];

                    if(next!=' ' && next!='-' && prev!=' ' && prev!='-')currword.push_back(chunks[i][j]);
                    else {
                        if(currword!=""){f[currword]++;
                      cout<<f[currword] ;
                        cout<<currword<<" ";}
                        currword="";
                        
                    }

                }
                else currword.push_back(chunks[i][j]);
               j++; 
            }
            i++;
        }
          if(currword!=""){f[currword]++;
                    //   
                    }
          int q=queries.size();
          vector<int>ans(q,0);
          for(int i=0;i<q;i++){
            ans[i]=f[queries[i]];
          }
        return ans;
        
    }
};