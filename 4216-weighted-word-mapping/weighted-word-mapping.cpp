class Solution {
    int wordMap(string &word,vector<int>& weights){
        int sum = 0;

        for(char ch : word){
            int id = ch-'a';
            sum+=weights[id];
        }
        cout<<sum<<" ";
        return sum%26;
    }
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for (string word : words){
            ans+='z' - wordMap(word,weights);
        }
        return ans;
    }
};