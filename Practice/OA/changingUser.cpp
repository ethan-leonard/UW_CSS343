#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>

class Solution {
public:
    int countUsernames(std::string username) {
        std::unordered_set<std::string> uniqueUsernames;
        std::queue<std::string> queue;

        uniqueUsernames.insert(username);
        queue.push(username);

        while (!queue.empty()) {
            std::string current = queue.front();
            queue.pop();

            for (int i = 0; i < current.length() - 1; i++) {
                if (current.substr(i, 2) == "cc") {
                    std::string newUsername = current.substr(0, i) + "a" + current.substr(i + 2);
                    if (uniqueUsernames.find(newUsername) == uniqueUsernames.end()) {
                        uniqueUsernames.insert(newUsername);
                        queue.push(newUsername);
                    }
                }

                if (current.substr(i, 2) == "dd") {
                    std::string newUsername = current.substr(0, i) + "b" + current.substr(i + 2);
                    if (uniqueUsernames.find(newUsername) == uniqueUsernames.end()) {
                        uniqueUsernames.insert(newUsername);
                        queue.push(newUsername);
                    }
                }
            }
        }

        return uniqueUsernames.size();
    }
};

int main() {
    Solution sol;
    std::cout << sol.countUsernames("ccc") << std::endl;  // Output: 3
    std::cout << sol.countUsernames("ccd") << std::endl;  // Output: 2
    std::cout << sol.countUsernames("ddcc") << std::endl;  // Output: 4
    return 0;
}
