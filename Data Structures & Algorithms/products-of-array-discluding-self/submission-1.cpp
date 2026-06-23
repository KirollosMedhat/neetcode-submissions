class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int zeroCount = 0;
        for(int num:nums){
            if(num != 0){
                prod = prod * num;
            }else{
                zeroCount++;
            }
        }

        if(zeroCount > 1){
            return vector<int>(nums.size(),0);
        }

        vector<int> result(nums.size());

        for(size_t i = 0; i < nums.size(); i++){
            if(zeroCount > 0){
                if(nums[i] == 0){
                    result[i] = prod;
                }else{
                    result[i] = 0;
                }
            }else{
                result[i] = prod/nums[i];
            }
        }
        
        
        return result;



    }
};
