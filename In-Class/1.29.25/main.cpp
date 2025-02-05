#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <unordered_map>
#include <unordered_set>


using namespace std;


// 215. Kth Largest Element in an Array
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


// 1971. Find if Path Exists in Graph
class Solution {
public:
    // vector<vector<int>> 
    // store all nodes connected to 0
    unordered_map<int, vector<int>> adj;
    unordered_set<int> visited;
    int destination; 

    bool dfsR(int curr) {
        if (curr == destination) return true;
        if (visited.count(curr)) return false;

        visited.insert(curr);
        for (int neighbor : adj[curr]) {
            if (!visited.contains(neighbor)) {
                bool success = dfsR(neighbor);
                if (success) return true;
            }
        } return false;
    }

    bool dfsS(int curr) {
        if (curr == destination) return true;
        stack<int> st;
        st.push(curr);
        visited.insert(curr);

        while (!st.empty()) {
            int top = st.top();
            st.pop();
            if (top == destination) return true;
            for (int neighbor : adj[top]) {
                if (!visited.contains(neighbor)) {
                    st.push(neighbor);
                    visited.insert(neighbor);
                } 
            }
        } return false;
    }

    bool bfs(int curr) {
        if (curr == destination) return true;
        queue<int> q;
        q.push(curr);
        visited.insert(curr);

        while (!q.empty()) {
            int top = q.front();
            q.pop();
            if (top == destination) return true;
            for (int neighbor : adj[top]) {
                if (!visited.contains(neighbor)) {
                    q.push(neighbor);
                    visited.insert(neighbor);
                } 
            }
        } return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        this->destination = destination;
        for (vector<int> edge : edges) {
            // [2, 0]
            int from = edge[0];
            int to = edge[1];
            adj[from].push_back(to);
            adj[to].push_back(from);
        } return dfsS(source); // return dfsR(source)
    }
};