class Solution {
public:
    struct cmp {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
            if (a.first != b.first) return a.first > b.first; // higher freq first
            return a.second > b.second; // larger val first
        }
    };

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        map<int,int> freq;
        set<pair<int,int>, cmp> s;   // top x (descending by freq, then val)
        set<pair<int,int>, cmp> ns;  // rest
        vector<long long> result;
        int n = nums.size();
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int val = nums[i];

            // --- ERASE old pair if exists and adjust ans if it was in s ---
            int oldf = 0;
            if (freq.count(val)) oldf = freq[val];
            if (oldf > 0) {
                pair<int,int> oldp = {oldf, val};
                if (s.find(oldp) != s.end()) {
                    s.erase(oldp);
                    ans -= 1LL * oldf * val;   // subtract contribution removed from s
                } else {
                    ns.erase(oldp);
                }
            }

            // --- INCREMENT freq and insert updated pair ---
            freq[val] = oldf + 1;
            int newf = freq[val];

            if ((int)s.size() < x) {
                s.insert({newf, val});
                ans += 1LL * newf * val;
            } else {
                pair<int,int> smallestInS = *prev(s.end()); // smallest in s (lowest priority among top-x)
                if (newf > smallestInS.first ||
                    (newf == smallestInS.first && val > smallestInS.second)) {
                    // move smallest from s -> ns
                    s.erase(prev(s.end()));
                    ns.insert(smallestInS);
                    ans -= 1LL * smallestInS.first * smallestInS.second;

                    // insert new into s
                    s.insert({newf, val});
                    ans += 1LL * newf * val;
                } else {
                    ns.insert({newf, val});
                }
            }

            // --- REBALANCE: ensure no element in ns outranks smallest in s ---
            while (!ns.empty() && !s.empty()) {
                pair<int,int> bestInNs = *ns.begin();          // best candidate in ns
                pair<int,int> smallestInS = *prev(s.end());   // worst in s
                // If bestInNs should be in s (better freq or same freq but larger val)
                if (bestInNs.first > smallestInS.first ||
                    (bestInNs.first == smallestInS.first && bestInNs.second > smallestInS.second)) {
                    // swap them
                    ns.erase(ns.begin());
                    s.erase(prev(s.end()));
                    ans -= 1LL * smallestInS.first * smallestInS.second;
                    s.insert(bestInNs);
                    ns.insert(smallestInS);
                    ans += 1LL * bestInNs.first * bestInNs.second;
                } else break;
            }

            // if window formed
            if (i >= k - 1) {
                result.push_back(ans);
                int rem = nums[i - k + 1];

                // --- ERASE current pair of rem and adjust ans if needed ---
                int curf = 0;
                if (freq.count(rem)) curf = freq[rem];
                if (curf > 0) {
                    pair<int,int> curp = {curf, rem};
                    if (s.find(curp) != s.end()) {
                        s.erase(curp);
                        ans -= 1LL * curf * rem;   // removed from contribution
                    } else {
                        ns.erase(curp);
                    }
                }

                // decrement frequency of rem
                if (freq.count(rem)) {
                    freq[rem]--;
                    if (freq[rem] == 0) {
                        freq.erase(rem);
                    } else {
                        int f_new = freq[rem];
                        // reinsert updated rem
                        if ((int)s.size() < x) {
                            s.insert({f_new, rem});
                            ans += 1LL * f_new * rem;
                        } else {
                            pair<int,int> smallestInS = *prev(s.end());
                            if (f_new > smallestInS.first ||
                                (f_new == smallestInS.first && rem > smallestInS.second)) {
                                // move smallest from s -> ns
                                s.erase(prev(s.end()));
                                ns.insert(smallestInS);
                                ans -= 1LL * smallestInS.first * smallestInS.second;

                                // insert updated into s
                                s.insert({f_new, rem});
                                ans += 1LL * f_new * rem;
                            } else {
                                ns.insert({f_new, rem});
                            }
                        }
                    }
                }

                // balance after removal: move best from ns → s if s has < x
                while ((int)s.size() < x && !ns.empty()) {
                    pair<int,int> mv = *ns.begin(); // best in ns
                    ns.erase(ns.begin());
                    s.insert(mv);
                    ans += 1LL * mv.first * mv.second;
                }

                // ensure s has exactly x (if too big)
                while ((int)s.size() > x) {
                    pair<int,int> mv = *prev(s.end());
                    s.erase(prev(s.end()));
                    ns.insert(mv);
                    ans -= 1LL * mv.first * mv.second;
                }

                // final safety rebalance: promote any ns item that outranks s's smallest
                while (!ns.empty() && !s.empty()) {
                    pair<int,int> bestInNs = *ns.begin();
                    pair<int,int> smallestInS = *prev(s.end());
                    if (bestInNs.first > smallestInS.first ||
                        (bestInNs.first == smallestInS.first && bestInNs.second > smallestInS.second)) {
                        ns.erase(ns.begin());
                        s.erase(prev(s.end()));
                        ans -= 1LL * smallestInS.first * smallestInS.second;
                        s.insert(bestInNs);
                        ns.insert(smallestInS);
                        ans += 1LL * bestInNs.first * bestInNs.second;
                    } else break;
                }
            }
        }
        return result;
    }
};
