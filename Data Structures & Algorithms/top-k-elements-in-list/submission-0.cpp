class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> myMap;

        for(auto& i:nums){
            myMap[i]++;
        }

        vector<pair<int,int>> list;

        for(const auto& i:myMap){
            list.push_back({i.second,i.first});
        }
        sort(list.begin(), list.end());

        vector<int> result;
        for(int i = 0; i < k;i++){
            result.push_back(list.back().second);
            list.pop_back();
        }

        return result;
    }
};
