class Solution {
public:
    string smallestPalindrome(string& s) {
        map<char,int> mp;
        int n = s.size();
        
        for(int i = 0;i<n/2;i++){
            mp[s[i]]++;
        }

        string str="";
        int l = 0;
        for(auto [ch,cnt] : mp){
            string temp(cnt,ch);
            str+=temp;
        }
        string ans = str;
        reverse(str.begin(),str.end());

        if(n&1){
            ans+=s[n/2];
        }
        ans+=str;

        return ans;   
    }
};