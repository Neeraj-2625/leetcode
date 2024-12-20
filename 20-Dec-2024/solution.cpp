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
    TreeNode* reverseOddLevels(TreeNode* root) {
        unordered_map<int,vector<int>> mp;

        queue<TreeNode*> q;
        q.push(root);
        int lvl = 0;

        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                mp[lvl].push_back(temp->val);

                if(temp->left)
                   q.push(temp->left);
                if(temp->right)
                   q.push(temp->right);   
            }
            lvl++;
        }

        for(auto i:mp){
            if(i.first&1){
                reverse(mp[i.first].begin(),mp[i.first].end());
            }
        }

        q.push(root);
        lvl = 0;

        while(!q.empty()){
            int n = q.size();
            int k = 0;
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();

                temp->val = mp[lvl][k++];

                if(temp->left)
                  q.push(temp->left);
                if(temp->right)
                  q.push(temp->right);  
            }
            lvl++;
        }

        return root;
    }
};