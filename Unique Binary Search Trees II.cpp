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
        TreeNode* clone(TreeNode* root){
            if(root == nullptr)//nullptr空指针
                return nullptr;
            TreeNode* newroot = new TreeNode(root->val);
            newroot->left = clone(root->left);
            newroot->right = clone(root->right);
            return newroot;
        }
        vector<TreeNode *> generateTrees(int n) {
            if(n <= 0) return {};
            vector<TreeNode *> res(1,nullptr);
            for(int i = 1; i <= n; i++){
                vector<TreeNode *> tmp;
                for(int j = 0; j<res.size();j++){
                    TreeNode* oldroot = res[j];
                    TreeNode* root = new TreeNode(i);
                    TreeNode* target = clone(oldroot);
                    root->left = target;
                    tmp.push_back(root);
                   
                    if(oldroot!=nullptr){
                        TreeNode* tmpold = oldroot;
                        while(tmpold->right!=nullptr){
                            TreeNode* nonroot = new TreeNode(i);
                            TreeNode *tright = tmpold->right;
                            tmpold->right = nonroot;
                            nonroot->left = tright;
                            TreeNode *target = clone(oldroot);
                            tmp.push_back(target);
                            tmpold->right = tright;
                            tmpold = tmpold->right;
                        }
                        tmpold->right = new TreeNode(i);
                        TreeNode *target = clone(oldroot);
                        tmp.push_back(target);
                        tmpold->right = nullptr;
                    }
                }
                res=tmp;
            }
            return res;
        }
    };
/*
1. 选出根结点后应该先分别求解该根的左右子树集合，也就是根的左子树有若干种，它们组成左子树集合，根的右子树有若干种，它们组成右子树集合。 
2. 然后将左右子树相互配对，每一个左子树都与所有右子树匹配，每一个右子树都与所有的左子树匹配。然后将两个子树插在根结点上。 
3. 最后，把根结点放入链表中。*/
class Solution {  
public:  
    vector<TreeNode *> generateTrees(int n) {  
        if(n <= 0) return {};
        return createTree(1,n);  
    }  
      
    vector<TreeNode *> createTree(int start, int end)  
    {  
        vector<TreeNode *> results;  
        if(start>end)  
        {  
            results.push_back(NULL);  
            return results;  
        }  
          
        for(int k=start;k<=end;k++)  
        {  
            vector<TreeNode *> left = createTree(start,k-1);  
            vector<TreeNode *> right = createTree(k+1,end);  
            for(int i=0;i<left.size();i++)  
            {  
                for(int j=0;j<right.size();j++)  
                {  
                    TreeNode * root = new TreeNode(k);  
                    root->left = left[i];  
                    root->right = right[j];  
                    results.push_back(root);  
                }  
            }  
        }  
        return results;  
    }  
};