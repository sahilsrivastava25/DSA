class Solution {
public:
    unordered_map<int, TreeNode*> parent;
    unordered_map<int, int> height;
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string firstPath = "", secondPath = "";
        TreeNode* lca = findLCA(root, startValue, destValue);
        construct(lca, firstPath, startValue);
        construct(lca, secondPath, destValue);
        reverse(firstPath.begin(), firstPath.end());
        reverse(secondPath.begin(), secondPath.end());
        return string(firstPath.size(), 'U') + secondPath;
    }
    
    
    void dfs(TreeNode* p, TreeNode* root, int h) {
        if(root == NULL) return;
        dfs(root, root -> left, h + 1);
        dfs(root, root -> right, h + 1);
        parent[root -> val] = p;
        height[root -> val] = h;
    }
    
    TreeNode* findLCA(TreeNode* root, int u, int v) {
        dfs(NULL, root, 0);
        TreeNode* lca;
        while(u != v) {
            if(parent[u] == parent[v]) {
                lca = parent[u];
                break;
            }
            if(height[u] > height[v]) {
                if(parent[u] -> val == v) lca = parent[u];
                u = parent[u] -> val;
            } else {
                if(parent[v] -> val == u) lca = parent[v];
                v = parent[v] -> val;
            }
        }
        return lca;
    }
    
    bool construct(TreeNode* root, string& s, int val) {
        if(root == NULL) {
            return false;
        }
        if(root -> val == val) {
            return true;
        }
        
        bool left = construct(root -> left, s, val);
        bool right = construct(root -> right, s, val);
        if(left) s += "L";
        else if(right) s += "R";
        return left | right;
    }
};