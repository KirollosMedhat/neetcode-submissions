class Solution {
public:
    string longestPalindrome(string s) {
        
        int reslen = 0;
        int residx = 0;

        for(int i = 0; i < s.size(); i++){
            int l = i; 
            int r = i;

            while(l >=0 && r < s.size() && s[l] == s[r]){
                
                if(r - l + 1 > reslen) {
                    reslen = r - l + 1;
                    residx = l;
                }
                l--;
                r++;
            }

            l = i;
            r = i+1;

            while(l >=0 && r < s.size() && s[l] == s[r]){
                
                if(r - l + 1 > reslen) {
                    reslen = r - l + 1;
                    residx = l;
                }
                l--;
                r++;
            }






        }

        return s.substr(residx, reslen);
    }
};
