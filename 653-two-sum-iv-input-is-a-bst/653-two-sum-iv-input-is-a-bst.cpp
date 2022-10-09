/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int,int>mp;
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL){
            return false;
        }
        bool l = findTarget(root->left, k);
        auto it = mp.find(k - root->val);
        if(it != mp.end())
            return true;
        mp[root->val]++;
        bool r = findTarget(root->right, k);
        if(l or r)
            return true;
        return false;
    }
};