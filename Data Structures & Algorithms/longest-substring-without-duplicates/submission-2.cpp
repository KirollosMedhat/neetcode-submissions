class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> myMap;
        int l = 0;
        int maxLen = 0;

        for(int r = 0; r < s.size(); r++){
            while(myMap.find(s[r]) != myMap.end()){
                myMap.erase(s[l]);
                l++;
            }

            myMap.insert(s[r]);
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }



};
