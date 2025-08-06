/*
 * @lc app=leetcode id=846 lang=cpp
 *
 * [846] Hand of Straights
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }
        for (auto it = count.begin(); it != count.end(); ++it) {
            int card = it->first;
            if (it->second > 0) {
                int numGroups = it->second;
                for (int i = 0; i < groupSize; i++) {
                    if (count[card + i] < numGroups) {
                        return false;
                    }
                    count[card + i] -= numGroups;
                }
            }
        }   

        
        return true;    
        
    }
};
// @lc code=end

