class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        int l=0;
        int r=n-1;
        int count=0;
        sort(people.begin(), people.end());

        while(l<=r){
            if((people[l]+people[r])<=limit){
                count++;
                r--;
                l++;
            }
            else{
                count++;
                r--;
            }
        }
        return count;

        
    }
};