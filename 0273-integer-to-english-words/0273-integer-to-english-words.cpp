class Solution {
public:
    map<string, string> once;
    map<string, string> tens;

    string solve(string nums1, string nums2, string nums3, string stage) {
        string ans = "";
        if (nums2 == "1") {
            ans = tens[nums2 + nums1];
        } else {
            ans = once[nums1];

            if (nums2 != "0") {
                if (ans != "")
                    ans = tens[nums2] + " " + ans;
                else
                    ans = tens[nums2];
            }
        }

        if (nums3 != "0") {
            if (ans != "")
                ans = once[nums3] + " " + "Hundred" + " " + ans;
            else
                ans = once[nums3] + " " + "Hundred";
        }

        if (stage != "none") {
            if (ans != "")
                ans = ans + " " + stage;
            
        }

        return ans;
    }

    string numberToWords(int num) {

        string nums = to_string(num);
        reverse(nums.begin(), nums.end());
        int n = nums.size();

        if (nums == "0")
            return "Zero";

        once["0"] = "";
        once["1"] = "One";
        once["2"] = "Two";
        once["3"] = "Three";
        once["4"] = "Four";
        once["5"] = "Five";
        once["6"] = "Six";
        once["7"] = "Seven";
        once["8"] = "Eight";
        once["9"] = "Nine";

        tens["10"] = "Ten";
        tens["11"] = "Eleven";
        tens["12"] = "Twelve";
        tens["13"] = "Thirteen";
        tens["14"] = "Fourteen";
        tens["15"] = "Fifteen";
        tens["16"] = "Sixteen";
        tens["17"] = "Seventeen";
        tens["18"] = "Eighteen";
        tens["19"] = "Nineteen";

        tens["2"] = "Twenty";
        tens["3"] = "Thirty";
        tens["4"] = "Forty";
        tens["5"] = "Fifty";
        tens["6"] = "Sixty";
        tens["7"] = "Seventy";
        tens["8"] = "Eighty";
        tens["9"] = "Ninety";

        vector<string> stage = {"none", "Thousand", "Million", "Billion"};

        string ans = "";

        int i = 0;
        int j = 0;

        while (i + 2 < n) {
            string temp = solve(string(1, nums[i]), string(1, nums[i + 1]),
                                string(1, nums[i + 2]), stage[j]);

            if (temp != "") {
                if (ans != "")
                    ans = temp + " " + ans;
                else
                    ans = temp;
            }

            i += 3;
            j++;
        }

        if (i + 1 < n) {
            string temp = solve(string(1, nums[i]), string(1, nums[i + 1]), "0",
                                stage[j]);

            if (temp != "") {
                if (ans != "")
                    ans = temp + " " + ans;
                else
                    ans = temp;
            }

            j++;
            i += 2;
        }

        if (i < n) {
            string temp = solve(string(1, nums[i]), "0", "0", stage[j]);

            if (temp != "") {
                if (ans != "")
                    ans = temp + " " + ans;
                else
                    ans = temp;
            }

            j++;
            i += 1;
        }
        while (!ans.empty() && ans.back() == ' ')
            ans.pop_back();

        return ans;
    }
};