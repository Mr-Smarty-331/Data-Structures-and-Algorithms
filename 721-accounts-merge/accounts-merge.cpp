class Solution {
private:
    vector<int> parent;
    vector<int> size;

    int findPar(int a) {
        if (parent[a] == a) return a;

        return parent[a] = findPar(parent[a]);
    }

    void unite(int a,int b) {
        if (a == b) {
            return;
        }
        int pa = findPar(a);
        int pb = findPar(b);

        if (pa == pb) return;
        
        if (size[pa] > size[pb]){
            swap(pa,pb);
        }

        parent[pa] = pb;
        size[pb] += size[pa];
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        int n = acc.size();
        unordered_map<string,int> mp;
        parent.resize(n);
        size.resize(n,1);

        for(int i =0;i<n;i++) {
            parent[i] = i; 
        }

        for(int i =0;i<n;i++) {
            for(int j=1;j<acc[i].size();j++) {
                if (mp.find(acc[i][j]) == mp.end()) {
                    mp[acc[i][j]] = i;
                }
                else{
                    unite(mp[acc[i][j]],i);
                }
            }
        }

        vector<vector<string>> newDat(n);
        for (auto it : mp) {
            int node = findPar(it.second);
            string mail = it.first;

            newDat[node].push_back(mail);
        }

        // int c =0;

        // for(int i=0;i<n;i++) {
        //     if (newDat.size()!=0) c++;
        // }

        vector<vector<string>> ans;
        // int k=0;
        for(int i = 0;i<n;i++) {
            if (newDat[i].empty()) continue;

            sort(newDat[i].begin(),newDat[i].end());
            
            vector<string> cur;

            cur.push_back(acc[i][0]);

            cur.insert(cur.end(),newDat[i].begin(),newDat[i].end());

            ans.push_back(cur);
        }

        return ans;
    }
};