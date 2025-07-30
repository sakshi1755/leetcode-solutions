/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        int ans=INT_MAX;
        int l=0;
        int r=0;
        int startpoint=l;
        map<char, int> count;
        map<char, int> countint;
        for(char c: t){
            count[c]=0;
        }
         for(char c: t){
            countint[c]++;
        }
        vector<char>uc;
        while(r<n){
            if(count.find(s[r])!=count.end()){
            count[s[r]]++;
           
                  uc.push_back(s[r]);
            
            }
              bool valid = true;
            for (auto &p : countint) {
                if (count[p.first] < p.second) {
                    valid = false;
                    break;
                }
            }
            while(valid){
               if(count.find(s[l])==count.end()){
                    l++;

                    
                }
                
              else{  if(r-l+1<ans){
                    ans=r-l+1;
                    startpoint=l;

                }
                count[s[l]]--;
                
                auto it = find(uc.begin(), uc.end(), s[l]);
                if (it != uc.end()) {
                 uc.erase(it);  // removes only the first occurrence of 2
                 }
                 for (auto &p : countint) {
                if (count[p.first] < p.second) {
                    valid = false;
                    break;
                }
                 }
            
                l++;
                }

            }
            r++;
        }
        
        
        if(ans==INT_MAX)
            return "";

        else return s.substr(startpoint, ans) ;

    }

};
// @lc code=end

