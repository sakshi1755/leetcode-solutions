/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    using ln=ListNode*;
    ln mergesort(int i,int j,vector<ln>&lists){
        if(i>=lists.size() || j>=lists.size()) return NULL;
        if(i==j)return lists[i];
        ln rl=mergesort(i,(i+j)/2,lists);
        ln rr=mergesort((i+j)/2+1,j,lists);
        ln dummy=new ListNode(-1);
        ln temp=dummy;
        while(rl && rr){
            if(rl->val<rr->val){
                temp->next=rl;
                rl=rl->next;
            }
            else{
                temp->next=rr;
                rr=rr->next;
            }
            temp=temp->next;
        }
        if(rl){
            temp->next=rl;
        }
        if(rr){
            temp->next=rr;
        }
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if(k==0) return NULL;
        if(k==1) return lists[0];
       return mergesort(0,k-1,lists);
        
    }
};
// @lc code=end

