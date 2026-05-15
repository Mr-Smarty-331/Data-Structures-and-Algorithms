class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        priority_queue<int> pq;
        
        if (n == 0) return tasks.size();
        
        for (auto it: tasks){
            mp[it]++;
        }

        for (auto [task,cnt] : mp){
            pq.push(cnt);
        }

        queue<pair<int,int>> q; // store count of that rtask left with its next processing time

        int time = 0; 

        while( (!q.empty()) || (!pq.empty())) {
            time++;
            if (!pq.empty()) {
                int task = pq.top();
                task--;
                pq.pop();

                if (task!= 0){
                    q.push({task,time + n});
                }
            }

            if((!q.empty()) && (q.front().second == time)){
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};