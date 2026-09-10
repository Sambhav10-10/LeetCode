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
    int count = 0;
    pair<int,int> findavg(TreeNode* root){
        if(root == NULL) 
            return {0,0};
        pair<int,int> left_ = findavg(root->left);
        pair<int,int> right_ = findavg(root->right);
        int sum_ = left_.first + right_.first + root->val;
        int count_ = left_.second + right_.second + 1;
        if(root->val == sum_/count_)
            count++;
        return {sum_,count_};
    }
    int averageOfSubtree(TreeNode* root) {
        findavg(root);
        return count;
    }
};