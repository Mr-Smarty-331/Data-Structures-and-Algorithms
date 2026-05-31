class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        int i = 0;
        int n = asteroids.size();
        while(i<n){
            if (asteroids[i]>mass) return false;
            if (mass>=INT_MAX - asteroids[i]) mass = 1e6;
            mass += asteroids[i];
            i++;
        }
        return true;
    }
};