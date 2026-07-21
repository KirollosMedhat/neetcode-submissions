class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> charSet;
        int l = 0;
        int maxF = 0;
        int res = 0;
        for(int r = 0; (r < s.length()); r++){
            //int windowSize = r - l + 1; 
            charSet[s[r]]++;

            maxF = max(maxF, charSet[s[r]]); //da el satr ely kan na2esny

            while( (r - l + 1) - maxF > k){
                charSet[s[l]]--;
                l++;
                //windowSize = r - l + 1;
            }

            res = max(res, (r - l + 1));
        }
        return res;
    }
};
