class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) {
        int m = img.size();
        int n = img[0].size();

        if (img[sr][sc]==color) return img;

        queue<pair<int,int>> q;

        int og = img[sr][sc];
        img[sr][sc]=color;
        q.push({sr,sc});

        while(!q.empty()){
            int s = q.size();

            for (int i=0;i<s;i++){
                pair<int,int> px=q.front();
                int x=px.first;
                int y=px.second;
                q.pop();

                pair<int,int> dir[4]={{x-1,y},{x,y-1},{x+1,y},{x,y+1}};

                for(int k=0;k<4;k++){
                    int X = dir[k].first;
                    int Y = dir[k].second;

                    if ((X>=0&&X<m)&&(Y>=0&&Y<n) && (img[X][Y]==og)){
                        q.push({X,Y});
                        img[X][Y]=color;
                    }
                }
            }
        }

        return img;

    }
};