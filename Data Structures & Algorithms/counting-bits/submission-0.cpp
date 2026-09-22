class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        for(int i=0; i <= n; i++){
            unsigned short mask = 0b01;
            int currentRes = 0;
            while(mask < 1000){
                if((mask & i)) currentRes++;
                //currentRes = currentRes + (mask & i);
                mask = mask << 1;
            }
            result.push_back(currentRes);
        }

        return result;
    }
};
