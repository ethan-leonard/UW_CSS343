#include <iostream>

// 1137. N-th Tribonacci Number
class Solution {
public:
    int tribonacci(int n) {
        static int cache[100];
        if (n == 0) {
            return 0;
        } if (n == 1 || n == 2) {
            return 1;
        } if (cache[n] == 0) {
            cache[n] = tribonacci(n-3) + tribonacci(n-2) + tribonacci(n-1);
        } return cache[n];
    }
};