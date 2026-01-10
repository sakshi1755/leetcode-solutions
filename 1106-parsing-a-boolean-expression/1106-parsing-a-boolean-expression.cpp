class Solution {
public:
    bool solve(string& exp, int i, int j) {

        while (exp[i] == '(' && exp[j] == ')') {
            i++;
            j--;
        }
        if (i == j && exp[i] == 'f')
            return false;
        if (i == j && exp[i] == 't')
            return true;
        if (exp[i] == '&') {
            int ans = true;
            int s = i + 1;
            int e = j;

            while (exp[s] == '(' && exp[e] == ')') {
                s++;
                e--;
            }
            while (s <= e) {
                int tempend = s;
                int depth = 0;
                while (tempend <= e) {
                    if (exp[tempend] == '(')
                        depth++;
                    else if (exp[tempend] == ')')
                        depth--;
                    else if (exp[tempend] == ',' && depth == 0)
                        break;
                    tempend++;
                }

                ans = ans & solve(exp, s, tempend - 1);
                if (ans == false)
                    return false;
                s = tempend + 1;
            }
            return ans;
        } else if (exp[i] == '|') {
            int ans = false;
            int s = i + 1;
            int e = j;

            while (exp[s] == '(' && exp[e] == ')') {
                s++;
                e--;
            }
            while (s <= e) {
                int tempend = s;
                int depth = 0;
                while (tempend <= e) {
                    if (exp[tempend] == '(')
                        depth++;
                    else if (exp[tempend] == ')')
                        depth--;
                    else if (exp[tempend] == ',' && depth == 0)
                        break;
                    tempend++;
                }

                ans = ans | solve(exp, s, tempend - 1);
                if (ans == true)
                    return true;
                s = tempend + 1;
            }
            return ans;
        } else {

            return !solve(exp, i + 1, j);
        }
    }
    bool parseBoolExpr(string expression) {
        int n = expression.size();
        return solve(expression, 0, n - 1);
    }
};