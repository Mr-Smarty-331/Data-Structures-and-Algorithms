class Solution {
public:
    int convertTime(string& input, string& output) {
        int in_h = (input[0]-'0')*10 + (input[1]-'0');
        int in_m = (input[3]-'0')*10 + (input[4]-'0');

        int out_h = (output[0]-'0')*10 + (output[1]-'0');
        int out_m = (output[3]-'0')*10 + (output[4]-'0');

        int in_time = in_h*60 + in_m;
        cout<<in_time<<" ";
        int out_time = out_h*60 + out_m;
        cout<<out_time;
        int diff = abs(out_time - in_time);

        int ops=0;

        ops+=diff/60;
        diff%=60;
        ops+=diff/15;
        diff%=15;
        ops+=diff/5;
        diff%=5;
        ops+=diff/1;
        diff%=1;

        return ops;
    }
};