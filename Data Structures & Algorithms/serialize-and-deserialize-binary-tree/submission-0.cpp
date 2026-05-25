class Codec {
public:

    string serialize(TreeNode* root) {
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            if(curr){
                s += "#" + to_string(curr->val);
                q.push(curr->left);
                q.push(curr->right);
            }
            else s += "#n";
        }
        return s;
    }

    TreeNode* deserialize(string data) {
        if(data == "") return NULL;
        vector<TreeNode*> nodes;
        string curr = "";
        for(char c : data){
            if(c == '#'){
                if(curr != ""){
                    nodes.push_back(
                        curr == "n" ? NULL : new TreeNode(stoi(curr))
                    );
                    curr = "";
                }
            }
            else curr += c;
        }
        if(curr != "")
            nodes.push_back(
                curr == "n" ? NULL : new TreeNode(stoi(curr))
            );
        for(int i=0,j=1; j<nodes.size(); i++){
            if(!nodes[i]) continue;

            if(j < nodes.size()) nodes[i]->left = nodes[j++];
            if(j < nodes.size()) nodes[i]->right = nodes[j++];
        }

        return nodes[0];
    }
};