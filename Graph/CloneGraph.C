/********************************************
Given a reference of a node in a connected undirected graph.
Return a deep copy (clone) of the graph. 
*********************************************/

#include<unordered_map>
#include<queue>
#include<vector>

using namespace std;

// Definition for a Node.
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

class Solution {
public:
    //BFS method using queue
    Node* cloneGraph(Node* node) {

        // no nodes found in a graphs, return null
        if (node == NULL)
            return node;

        // queue to all nodes to iterate and clone if not found in clone map
        queue<Node*> que;
        que.push(node);
        clones[node] = new Node(node->val);

        while (!que.empty()) {
            Node* cur = que.front();
            que.pop();
            // iterate through neighbors
            for (auto neighbor : cur->neighbors) {
                if (clones.find(neighbor) == clones.end()) {
                    clones[neighbor] = new Node(neighbor->val);
                    que.push(neighbor);
                }
                clones[cur]->neighbors.push_back(clones[neighbor]);
            }
        }
        return clones[node];
    }

private:
    unordered_map<Node*, Node*> clones;
};