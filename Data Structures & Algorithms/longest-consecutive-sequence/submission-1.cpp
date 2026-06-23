class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //sort(nums.begin(),nums.end());
        unordered_set<int> myMap(nums.begin(),nums.end());

        int longest = 0;
        int current = 1;
        for(auto i:myMap){
            if(myMap.find(i - 1) == myMap.end()){
                current = 1;
                while(myMap.find(i + current) != myMap.end()){
                    current++;
                }
            }

            if(current>longest){
                longest = current;
            }
        }


        return longest;


    }
};
