#include <vector>
#include <queue>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int> mpq;
        for (int n : nums) mpq.push(n);
        while (k > 1) {
            mpq.pop();
            k--;
        } return mpq.top();
    }
};