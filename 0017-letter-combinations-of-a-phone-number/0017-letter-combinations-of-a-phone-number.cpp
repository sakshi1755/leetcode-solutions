class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())return{};
        vector<string> temp={""};
        vector<string> results;
        unordered_map <char, string>m={
     {'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"}, {'6', "mno"}, {'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
     
    
    for(char dig:digits){
        for(string &combinations:temp){
            for(char l:m[dig]){
                //combinations=combinations+l;
                results.push_back(combinations+l);


            }
            
        }
        temp=move(results);

    }
    return temp;
    }
};