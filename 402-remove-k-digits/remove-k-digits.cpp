class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<int> dq;
        int n=num.size();
        int c=0;
        for (int i=0;i<n;i++){
            int cur=num[i]-'0';
            while(dq.size()&&(dq.front()-'0')>cur&&c<k){
                dq.pop_front();
                c++;
            }
            dq.push_front(num[i]);
        }
        while(c<k){
            dq.pop_front();
            c++;
        }
        while(dq.size()&&(dq.back()=='0')){
            dq.pop_back();
        }
        
        string ans="";

        while(dq.size()){
            ans+=dq.back();
            dq.pop_back();            
        }
        return (ans.size())? ans:"0";
    }
};