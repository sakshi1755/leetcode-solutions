class Solution {
public:
    bool isValid(string s) {
        stack<char>stacks;
        int i=0;
        while(i < s.size()){
            char ch = s[i];
            if(ch=='(' || ch=='{' || ch=='['){
                stacks.push(ch);
            }
            else{
                if (stacks.empty()) return false;
                else{
                if(ch=='}' && stacks.top()=='{')stacks.pop();
                else if(ch==')' && stacks.top()=='(')stacks.pop();
                else if(ch==']' && stacks.top()=='[')stacks.pop();
                else return false;}
            }
            i++;
    }

      if(stacks.empty())return true;
      else return false;

        }
    
};