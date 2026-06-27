#include "bits/stdc++.h"

// Node structure for a binary tree. Can change according to the problem statement. 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int col = 18; // For 2^17 jumps

    // This function fills the direct parent of each node in the ancestor map. It assigns the parent of each node to the first column (index 0) of the ancestor vector for that node. The function is called recursively for the left and right children of the current node. 
    void fillDirectParent(TreeNode* node, TreeNode* parent,unordered_map<TreeNode*, vector<TreeNode*>>& ancestor){
        if(node == NULL)    return;

        ancestor[node].assign(col, NULL);   // Assign a new Row to each value of column 0
        ancestor[node][0] = parent;
        
        if(node->left)  fillDirectParent(node->left, node, ancestor);
        if(node->right) fillDirectParent(node->right, node, ancestor);
    }

    // This function fills the higher ancestors of each node in the ancestor map. It uses the previously filled direct parents to compute the ancestors at higher levels. The function is called recursively for the left and right children of the current node.
    void getHigherAncestor(TreeNode* node, unordered_map<TreeNode*, vector<TreeNode*>>& ancestor){
        if(node == NULL)    return;

        // Fill the remaining Table, using Binary Lifting. Formula: ancestor[node][j] = ancestor[ancestor[node][j - 1]][j - 1]
        for(int j = 1; j < col; j++){
            if(ancestor[node][j -1] != NULL){
                ancestor[node][j] = ancestor[ancestor[node][j - 1]][j - 1];
            }
        }

        if(node->left)  getHigherAncestor(node->left, ancestor);
        if(node->right) getHigherAncestor(node->right, ancestor);
    }   

    // Compute the depth of each node recursively and store it in the depthMap. 
    void getDepthMap(TreeNode* node,int currDepth, unordered_map<TreeNode*, int>& depthMap){
        if(node == NULL)    return;

        depthMap[node] = currDepth;

        if(node->left)  getDepthMap(node->left, currDepth + 1, depthMap);
        if(node->right)  getDepthMap(node->right, currDepth + 1, depthMap);
    }

    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, vector<TreeNode*>> ancestor;
        unordered_map<TreeNode*, int> depthMap;
        
    
        this->fillDirectParent(root, NULL, ancestor);   // Fill Direct Parents
        this->getDepthMap(root, 0, depthMap);           // Get the Depth of all nodes
        this->getHigherAncestor(root, ancestor);        // Fill Indirect, remaining parents

        if (depthMap[p] < depthMap[q])  swap(p, q);    // to make sure 'p' is always deeper than q
            
        int depthDifference = depthMap[p] - depthMap[q];

        // Lift 'p' up by matching the active bits of depthDifference
        for (int j = 0; j < col; j++) {
            if ((depthDifference >> j) & 1) {
                p = ancestor[p][j];
            }
        }

        // Alignment ke baad agar p aur q same node hain, toh q hi LCA hai
        if (p == q) return p;

        // Simultaneous binary lifting search
        // Higher jumps se niche ki taraf aayenge
        for (int j = col - 1; j >= 0; j--) {
            // Agar unka j-th ancestor different hai, toh dono ko lift karo
            if (ancestor[p][j] != ancestor[q][j]) {
                p = ancestor[p][j];
                q = ancestor[q][j];
            }
        }
        // Loop ke end par, p aur q bilkul LCA ke ek step niche khade hote hain.
        // Unka immediate parent (index 0) hi unka Lowest Common Ancestor hai.
        return ancestor[p][0];
        
    }
};