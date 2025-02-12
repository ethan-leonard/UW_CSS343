#include <vector>
#include <set>
#include <string>
#include <unordered_set>

using namespace std;

// 575. Distribute Candies
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> candies;

        for (int n : candyType) {
            candies.insert(n);
        }

        return min(candyType.size()/2, candies.size());
    }
};

// 242. Valid Anagram
class Solution {
    public:
        bool isAnagram(string s, string t) {
            if (s.length() != t.length()) return false;
            int sCount[26];
    
            for (char c : s) {
                sCount[c - 'a']++;
            } for (char c : t) {
                sCount[c-'a']--;
                if (sCount[c-'a'] < 0) {
                    return false;
                }
            } return true;
        }
    };