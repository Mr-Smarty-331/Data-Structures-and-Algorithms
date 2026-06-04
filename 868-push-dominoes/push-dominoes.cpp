class Solution {
    // the dir which reahces a domino early is the real dir
    // if the state has been vis before we dont tamper it,
    // we compare and save the earliest dirn

    void push(priority_queue<pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>, 
            greater<>>& pq,vector<pair<int,int>>& ans){
        int n = ans.size();
        auto [time,p] = pq.top();
        int ind = p.first;
        int dir = p.second;
        pq.pop();

        if(ind == n||ind==-1) return;

        if(ans[ind].first!=-1){
            if(ans[ind].first==time && ans[ind].second!=dir) {ans[ind].second = 0;return;}
            if(ans[ind].first>time) return;
        }
        else{
            ans[ind] = {time,dir};
            pq.push({time+1,{ind+dir,dir}});
        }
    }

public:
    string pushDominoes(string& str) {
        int n = str.size();
        priority_queue<pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>, 
            greater<>> pq;
        vector<pair<int,int>> ans(n,{-1,0}); //time , dir
        for(int i = 0;i<n;i++){
            if(str[i]=='R') pq.push({0,{i,1}});
            else if(str[i]=='L') pq.push({0,{i,-1}});
        }
        while(!pq.empty()){
            push(pq,ans);
        }
        string s(n,'.');
        for(int i = 0;i<n;i++){
            if(ans[i].second==-1) s[i] = 'L';
            else if(ans[i].second==1) s[i] = 'R';
        }

        return s;
    }
};