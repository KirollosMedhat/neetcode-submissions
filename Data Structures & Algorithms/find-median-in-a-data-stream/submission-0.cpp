class MedianFinder {
public:
    //int flag = 0;
    priority_queue<int, vector<int>, less<int>> max_lower_half_pq;
    priority_queue<int, vector<int>, greater<int>> min_upper_half_pq;
    MedianFinder() {
        
    }
    
    // void addNum(int num) {
    //     if(max_lower_half_pq.size() >= min_upper_half_pq.size()){
    //         max_lower_half_pq.push(num);
    //         min_upper_half_pq.push(max_lower_half_pq.top());
    //         max_lower_half_pq.pop();
    //     }else{
    //         max_lower_half_pq.push(num);
    //     }
    // }

    void addNum(int num) {
        // Add to lower half first
        max_lower_half_pq.push(num);

        // Make sure every element in lower <= every element in upper
        if (!min_upper_half_pq.empty() &&
            max_lower_half_pq.top() > min_upper_half_pq.top()) {

            int temp = max_lower_half_pq.top();
            max_lower_half_pq.pop();

            min_upper_half_pq.push(temp);
        }

        // Lower can have at most one more element than upper
        if (max_lower_half_pq.size() > min_upper_half_pq.size() + 1) {
            int temp = max_lower_half_pq.top();
            max_lower_half_pq.pop();

            min_upper_half_pq.push(temp);
        }

        if (min_upper_half_pq.size() > max_lower_half_pq.size()) {
            int temp = min_upper_half_pq.top();
            min_upper_half_pq.pop();
            max_lower_half_pq.push(temp);
        }
    }
    
    double findMedian() {
        if (max_lower_half_pq.size() > min_upper_half_pq.size()) {
            return max_lower_half_pq.top();
        }

        return (max_lower_half_pq.top() +
                min_upper_half_pq.top()) / 2.0;
    }
};
