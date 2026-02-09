class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int arr[26]={0};
        int l=0;
        int maxf=0;
        int maxl=0;
        for (int r=0;r<n;r++){
            int ch=s[r]-'A';
            int len=r-l+1;
            arr[ch]++;
            
            // maxf=*max_element(arr,arr+26); this is slow(O(26)) 
            
            maxf=max(maxf,arr[ch]); // faster (O(1))

            if (len-maxf<=k) {
                maxl=max(maxl,len);
            }
            else{
                arr[s[l]-'A']--;
                l++;
            }
        }
        return maxl;
    }
};