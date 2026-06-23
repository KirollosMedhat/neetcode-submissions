class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int longest = 0;
        int current = nums[0];
        int streak = 0;
        int i = 0;

        while(i < nums.size()){
            if(current != nums[i]){
                current = nums[i];
                streak = 0;
            }

            while(i < nums.size() && current == nums[i]){
                i++;
            }


            streak++;
            current++;
            longest = max(longest, streak);



        }

        return longest;
    }
};
