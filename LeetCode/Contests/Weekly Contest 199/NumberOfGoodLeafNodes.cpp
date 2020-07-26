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
    int val = 0;
    vector<int> go(TreeNode * cur, int distance){
        if(!cur) return vector<int>();
        if(!cur->left && !cur->right){
            vector<int> ans;
            ans.push_back(0);
            return ans;
        }
        vector<int> lef = go(cur->left, distance);
        vector<int> rig = go(cur->right, distance);
        //cout << "at " << cur->val << endl;
        //for(int x : lef) cout << x << " ";
        //cout << endl;
        //for(int y : rig) cout << y << "  ";
        //cout << endl;
        for(int x: lef){
            for(int y: rig){
                if(x+y+2 <= distance) val++;
            }
        }
        
        vector<int> ans;
        for(int x : lef) ans.push_back(x+1);
        for(int x : rig) ans.push_back(x+1);
        return ans;
    }
    int countPairs(TreeNode* root, int distance) {
        go(root, distance);
        return val;
    }
};
