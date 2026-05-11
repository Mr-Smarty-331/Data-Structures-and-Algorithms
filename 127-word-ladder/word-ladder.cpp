class Solution {
public:
    struct Node {
        string str;
        int k;
    };

    int ladderLength(string begin, string end, vector<string>& wordList) {
        int n = begin.length();
        
        unordered_set<string> seen;
        seen.insert(begin);

        unordered_set<string> words(wordList.begin(),wordList.end());

        queue<Node> q;

        q.push({begin,1});
        words.erase(begin);

        while(!q.empty()){
            string oWord = q.front().str;
            int st = q.front().k;

            q.pop();

            for(int i=0;i<n;i++){
                for (int j=0;j<26;j++){
                    char ch = 97+j;
                    string nWord = oWord;
                    nWord[i]=ch;

                    if (nWord == end && (!(words.find(nWord)==words.end()))) {
                        return st+1;
                    }

                    if (!(words.find(nWord)==words.end())) {
                        q.push({nWord,st+1});
                        words.erase(nWord);
                    }
                }
            }
        }
        return 0;
    }
};