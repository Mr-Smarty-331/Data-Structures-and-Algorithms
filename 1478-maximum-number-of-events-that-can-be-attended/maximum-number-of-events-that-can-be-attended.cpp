class Solution {
    static bool compare(vector<int>&v1,vector<int>&v2){
        return v1[0]<v2[0];
    }
public:
    int maxEvents(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end(),compare);

        int i = 0;
        int day;
        int counter = 0;
        priority_queue<int,vector<int>,greater<int>> pq;

        while(i<n||(!pq.empty())){
            // if the pq is empty we reset the day to the start of first remainiing event
            if (pq.empty()) {
                day = arr[i][0];
            }

            // push all the events that start this day into pq
            while(i<n&&(arr[i][0]==day)){
                pq.push(arr[i][1]);
                i++;
            }

            // remove the expired events
            while(!pq.empty() && pq.top()<day){
                pq.pop();
            }

            // process one event a day
            if(!pq.empty()){
                pq.pop(); // the event with closest deadlines are removed
                counter++;
                day++;
            }
        }

        return counter;
    }
};