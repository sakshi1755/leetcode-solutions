class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;

        int i = 0;
        int n = words.size();
        while (i < n) {
            vector<string> take;
            int totalchars = 0;
            int temp = 0;
            while (temp <= maxWidth && i < n) {
                int ws = words[i].size();
                temp += ws;
                if (temp <= maxWidth) {
                    take.push_back(words[i]);
                    totalchars += ws;
                    temp++;
                    i++;
                } else
                    break;
            }
            string oneline = "";
            if (take.size() == 1) {
                oneline += take[0];
                for (int j = totalchars; j < maxWidth; j++) {
                    oneline += ' ';
                }
            } else {
                if (i < n) {
                    int totalspaces = maxWidth - totalchars;
                    int tn = take.size();
                    int evenspaces = totalspaces / (tn - 1);
                    int remspaces = totalspaces % (tn - 1);
                    oneline += take[0];
                    int spaces = evenspaces;
                    if (remspaces) {
                        spaces++;
                        remspaces--;
                    }
                    for (int k = 0; k < spaces; k++) {
                        oneline += ' ';
                    }
                    for (int j = 1; j < tn - 1; j++) {
                        oneline += take[j];
                        spaces = evenspaces;
                        if (remspaces) {
                            spaces++;
                            remspaces--;
                        }
                        for (int k = 0; k < spaces; k++) {
                            oneline += ' ';
                        }
                    }
                    oneline += take[tn - 1];
                } else {
                    int tn=take.size();
                    for(int j=0;j<tn-1;j++){
                        oneline+=take[j];
                        oneline+=' ';
                    }
                    oneline+=take[tn-1];
                    while(oneline.size()<maxWidth){
                        oneline+=' ';
                    }


                }
            }
            ans.push_back(oneline);
        }
        return ans;
    }
};