class Solution {
public:
    bool sameTree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr)
            return true;

        if (root == nullptr || subRoot == nullptr)
            return false;

        if (root->val != subRoot->val)
            return false;

        return sameTree(root->left, subRoot->left) &&
               sameTree(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr)
            return false;

        if (sameTree(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};