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

void fill_inorder(TreeNode *root, vector<int> &ans)
{
    if(!root) return;

    fill_inorder(root->left, ans);
    ans.push_back(root->val);
    fill_inorder(root->right, ans);
}

public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;

        fill_inorder(root1, v1);
        fill_inorder(root2, v2);

        vector<int> ans;
        int i=0, j=0;
        while(i<v1.size() && j<v2.size())
        {
            if(v1[i] < v2[j])
                ans.push_back(v1[i++]);
            else
                ans.push_back(v2[j++]);
        }
        while(i<v1.size())
            ans.push_back(v1[i++]);
        while(j<v2.size())
            ans.push_back(v2[j++]);

        return ans;
    }
};