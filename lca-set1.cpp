/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findPath(TreeNode *root, TreeNode *node, vector<TreeNode *> &arr) {
        if (root == NULL) {
            return false;
        }
        
        arr.push_back(root);
        if (root->val == node->val) {
            return true;
        }
        
        if (findPath(root->left, node, arr) || findPath(root->right, node, arr)) {
            return true;
        }
        arr.pop_back();
        return false;
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return root;
	
	    vector<TreeNode *> path1;
	    vector<TreeNode *> path2;
	
	    findPath(root, p, path1);
	    findPath(root, q, path2);
	
	    int i = 0, j = 0;
	    while (i < path1.size() && j < path2.size()) {
		    if (path1[i]->val == path2[j]->val) {
			    i++;
			    j++;
	    	} else {
		    	break;
		    }
	    }
	    return path1[i-1];
    }
};
