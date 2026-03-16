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
    bool isEvenOddTree(TreeNode* root) {
        bool flag = 1;
        std::queue<TreeNode*> level;
        level.push(root);

        while(!level.empty()){
            int last = -1, size = level.size();
            for(int i=0; i<size; i++){
                TreeNode* cur = level.front();
                level.pop();
                if(flag){
                    if(!(cur->val % 2) || (last != -1 && cur->val <= last))
                        return false;
                }
                else{
                    if(cur->val % 2 || (last != -1 && cur->val >= last))
                        return false;
                }
                last = cur->val;
                if(cur->left)
                    level.push(cur->left);
                if(cur->right)
                    level.push(cur->right);
            }
            flag = !flag;
        }
        return true;
    }
};