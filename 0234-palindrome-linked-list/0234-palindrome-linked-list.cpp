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
class Solution {
public:
    using ln= ListNode *;
    bool isPalindrome(ListNode* head) {
    string s="";
    ln tail=head;
    while(tail!=nullptr){
       s.push_back(char(tail->val + '0'));
        tail=tail->next;
    } 
    int n=s.size();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-1-i])return false;
        }
        return true;
    }
};