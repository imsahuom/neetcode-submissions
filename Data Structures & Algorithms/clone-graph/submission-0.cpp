/*
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
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return node;
        Node* root = new Node(node->val);
        unordered_map<Node*, Node*> mp;
        mp[node] = root;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* curr = q.front(); 
            q.pop();
            for(auto n: curr->neighbors){
                if(!mp.count(n)){
                    Node* nn = new Node(n->val);
                    mp[n] = nn;
                    q.push(n);
                }
                mp[curr]->neighbors.push_back(mp[n]);
            }
        }
        return root;
    }
};
