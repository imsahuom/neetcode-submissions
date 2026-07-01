/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* help(vector<vector<int>>& grid, int xs, int xe, int ys, int ye){
        bool flag = true;
        int v = grid[xs][ys];
        int n = (xe - xs);
        for(int i = xs; i<xe; i++){
            for(int j=ys; j < ye; j++){
                if (grid[i][j] != v){
                    flag = false;
                    break;
                }
            }
        }
        if (flag){
            if (v == 0) flag = false;
            Node* root = new Node(flag, true);
            return root;
        }else{
            Node* root = new Node(true, false);
            root->topLeft = help(grid, xs, xs + n/2, ys , ys + n/2);
            root->topRight = help(grid, xs, xs + n/2, ys + n/2, ye);
            root->bottomLeft = help(grid, xs + n/2, xe, ys, ys + n/2);
            root->bottomRight = help(grid, xs + n/2, xe, ys + n/2, ye);
            return root;
        }
        return nullptr;
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return help(grid, 0, n, 0, n);
    }
};