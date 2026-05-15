class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        if (hand.size()%k != 0) return false;

        map<int,int> mp;
        
        for(auto it : hand) {
            mp[it]++;       
        }

        for (auto [key,val] : mp) {
            while(mp[key]!=0) {
                mp[key]--;
                for(int i =1;i<k;i++){
                    if(mp[key+i] == 0) return false;
                    mp[key+i]--;
                }
            }
        }

        return true;
    }
};