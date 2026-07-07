class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int len = 0;
        for(int i = n-1;i>=0;i--){
            while(len==0 && i>=0 && s[i]==' ') i--;
            if(len>0 && (s[i]==' ')) break;
            len++;
        }

        return len;
    }
};