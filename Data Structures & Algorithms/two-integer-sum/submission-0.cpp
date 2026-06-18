class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> myMap;
        for(int i=0; i<nums.size();i++){
            myMap[ nums[i] ] = i;
        }

        for(int i=0; i<nums.size();i++){
            int remainder = target - nums[i];
            if(myMap.find(remainder) != myMap.end() && myMap[remainder] != i){
                return vector<int>{i,myMap[remainder]};
            }
        }
        
        return vector<int>{};
    }
};
