class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f=0,te=0,tw=0;

        for (int x:bills){
            if (x==5) f++;
            else if (x==10) {
                te++;
                if (f<1) {
                    return false;
                }
                else f--;
            }
            else {
                tw++;
                if (te>=1&&f>=1){
                    te--;
                    f--;
                }
                else if(f>=3){
                    f-=3;
                }
                else {return false;}
            }
        }
        return true;
    }
};