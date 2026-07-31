class Solution {
public:
    string minWindow(string s, string t) {

        if(t.empty()) return "";

        unordered_map<char,int> window,countT;
        for(char c:t){
            countT[c]++;
        }
        int l = 0;
        int have = 0;
        int need = countT.size();
        int resLen = INT_MAX;
        int resL = 0;
        int resR = 0;
        for(int r = 0; r < s.length(); r++){
            window[s[r]]++;

            if(countT.count(s[r]) && window[s[r]] == countT[s[r]]){
                have ++;
            }

            while(have == need){
                if((r - l + 1) < resLen){
                    resLen = r - l + 1;
                    resL = l;
                    resR = r;
                }

                window[s[l]]--;

                if(countT.count(s[l]) && window[s[l]] < countT[s[l]]){
                    have--;
                }
                l++;

            }

        }

        return resLen == INT_MAX ? "" : s.substr(resL, resLen);
    }
};
