class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        uint32_t musk = 0b01;

        for(int i = 0; i < 32; i++){
            
            if(musk & n) res++;
            musk = musk << 1;
        }

        return res;

    }
};
