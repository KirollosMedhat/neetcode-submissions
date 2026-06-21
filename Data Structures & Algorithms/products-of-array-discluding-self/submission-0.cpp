class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixSum(nums.size());
        vector<int> suffixSum(nums.size());
        vector<int> result(nums.size());

        prefixSum[0] = 1;
        suffixSum[nums.size() - 1] = 1;
        for(int i = 1; i < nums.size(); i++){
            
            prefixSum[i] = nums[i-1] * prefixSum[i-1]; 
        }

        for(int i = nums.size()-2; i >= 0; i--){
            suffixSum[i] = nums[i+1] * suffixSum[i+1];
        }

        for(int i = 0; i < nums.size(); i++){
            result[i] = prefixSum[i] * suffixSum[i];
        }

        return result;

    }
};
