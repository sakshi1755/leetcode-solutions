/*
 * @lc app=leetcode id=1209 lang=cpp
 *
 * [1209] Remove All Adjacent Duplicates in String II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        map<int,int>mp;
        for(int i=0;i<s.length();i++){
            if(st.empty() || st.top().first!=s[i]){
                st.push({s[i],i});
                mp[i]=1;

            }
            else{
                if(mp[st.top().second]+1==k){
                  //  int idx=st.top().second;
                    for(int i=0;i<k-1;i++)st.pop();
            
                }
                else{
                   
                    mp[i]=mp[st.top().second]+1;
                     st.push({s[i],i});
                }
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top().first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
// @lc code=end

