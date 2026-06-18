class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> myMap;

        for(int i=0; i < strs.size(); i++){
            string order = strs[i];
            sort(order.begin(), order.end());
            myMap[order].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for( auto& i:myMap){
            result.push_back(i.second);
        }

        return result;


    }
};
