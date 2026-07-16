class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        
        stack<int> openSt;
        stack<int> starSt;

        for(int i = 0;i<n;i++){
            char cur = s[i];
            if(cur == '(') openSt.push(i);
            else if (cur == ')') {
                if (!openSt.empty()){
                    openSt.pop();
                }
                else if (starSt.size()>0){
                    starSt.pop();
                }
                else{
                    return false;
                }
            }
            else{
                starSt.push(i);
            }
        }

        while(!starSt.empty() && !openSt.empty()){
            if(openSt.top()>starSt.top()) return false;
            openSt.pop();
            starSt.pop();
        }
        if(!openSt.empty()) return false;

        return true;
    }
};