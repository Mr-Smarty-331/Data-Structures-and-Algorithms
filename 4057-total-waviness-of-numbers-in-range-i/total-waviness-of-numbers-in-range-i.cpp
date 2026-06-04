class Solution {
public:
    int totalWaviness(int num1, int num2) {
        if (num1<100 && num2>=100) num1 = 100;
        if (num1<100 && num2<100) return 0;
        int ans = 0;
        for(int i = num1;i<=num2;i++){
            vector<int> digits;
            int cur = i;
            while(cur){
                digits.push_back(cur%10);
                cur/=10;
            }

            for(int j = 1;j<digits.size()-1;j++){
                if(digits[j]>digits[j+1]&& digits[j]>digits[j-1]) ans++;
                else if(digits[j]<digits[j+1]&& digits[j]<digits[j-1]) ans++;
            }
        }

        return ans;
    }
};