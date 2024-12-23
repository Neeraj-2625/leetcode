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
private:
    int solve(vector<int> arr){
        vector<int> target = arr;

        sort(target.begin(),target.end());
        int n = arr.size();
        int ans = 0;

        unordered_map<int,int> pos;

        for(int i=0;i<n;i++){
            pos[arr[i]] = i;
        }

        for(int i=0;i<n;i++){
            if(target[i]!=arr[i]){

                ans++;

                int curr = pos[target[i]];
                pos[arr[i]] = curr;
                swap(arr[curr],arr[i]);
            }
        }

        return ans;
    }    
public:
    int minimumOperations(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);

        int ans = 0;

        while(!q.empty()){
            int n = q.size();
            vector<int> v;

            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();

                v.push_back(temp->val);

                if(temp->left)
                  q.push(temp->left);

                if(temp->right)
                  q.push(temp->right);  
            }

            ans += solve(v);
        }

        return ans;
    }
};