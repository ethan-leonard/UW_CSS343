#include <iostream>
#include <vector>
#include <queue>

// 1046. Last Stone Weight
class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        std::priority_queue<int> queue;
        for (int n : stones) {
            queue.push(n);
        }

        while (queue.size() >= 2) {
            int i = queue.top();
            queue.pop();
            int j = queue.top();
            queue.pop();
            if (i != j) {
                queue.push(i - j);
            }
        }

        if (!queue.empty()) {
            return queue.top();
        } return 0;
    }
};

