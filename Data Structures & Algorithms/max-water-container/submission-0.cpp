class Solution {
public:
    int maxArea(vector<int>& heights) {

        int l = 0;
        int r = heights.size()-1;

        int maxAr = -1;
        int area = 0;
        //(l < heights.size() - 1) && (r > 0) &&

        while( (l < r) ){
            int minNum = min(heights[l], heights[r]);
            //cout <<"minNum: "<< minNum << endl;
            area = minNum * (r-l);
            maxAr = max(area,maxAr);
            //cout <<"area: "<< area << "   max area:" << maxAr <<endl;
            if(minNum == heights[l]){
                l++;
                //cout << l;
                continue;
            }

            if(minNum == heights[r]){
                r--;
                //cout << r;
                continue;
            }



        }


        return maxAr;
    }
};
