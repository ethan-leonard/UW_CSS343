#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue> 

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


// 207. Course Schedule
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // 0 enables [1, 2, 3]
    unordered_map<int, vector<int>> nextCourse;

    // map of degree
    unordered_map<int, int> degree;

    // calulate the degrees for courses
    for (auto pre : prerequisites) {
        int prerequisite = pre[1];
        int course = pre[0]; 
        degree[course]++;
        nextCourse[prerequisite].push_back(course);
    }

    // courses with 0 degree added to take queue
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (degree[i] == 0) {
            q.push(i);
        }
    }

    if (q.empty()) { return false; }

    // take courses with 0 degree
    while (!q.empty()) {
        int taking = q.front();
        numCourses--;
        q.pop();
        for (int course : nextCourse[taking]) {
            degree[course]--;
            if (degree[course] == 0) {
                q.push(course);
            }
        }
    } return numCourses == 0;

}

// 133. Clone Graph
unordered_map<Node*, Node*> theClone;
Node* cloneGraph(Node* node) {
    if (node == nullptr) return nullptr;
    if (theClone.contains(node)) return theClone[node];
    Node* n2 = new Node(node->val);
    theClone[node] = n2;
    for (Node* neighbor : node->neighbors) {
        Node *clonedNeighbor = cloneGraph(neighbor);
        n2->neighbors.push_back(clonedNeighbor);
    }
    return n2;        
}
