
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
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx level order traversal | right side view o fbinary tree xxxxxxxxxxxxxxxxxxxxxxxxx
class Solution {
    public:
    vector<vector<int>> level;
     queue<TreeNode*> q;
public:
    vector<int> rightSideView(TreeNode* root) {
        levelorder(root);
     //   print();
        
        vector<int> ans;
        
        for( int i =0; i< level.size(); i++)
        {
            int n = level[i].size();  // imp bec we cant access q size during loop when we are updating the size during the loop
             ans.push_back(level[i][n-1]);
        }
            //ans.push_back(level[i].back());
        return ans;
        
    }
     void levelorder( TreeNode* root)
    {
        if ( root == NULL) return;
        q.push(root);
        while(!q.empty())
        {
            vector<int> l;
           // cout<< "q size = "<<q.size()<<endl;
            int s= q.size();
            for(int i = 0; i< s;i++)
            {
                TreeNode* temp= q.front();
                q.pop();
                
                l.push_back(temp->val);
                if(temp-> left != NULL)
                    q.push(temp->left);
                if(temp-> right != NULL)
                    q.push(temp->right);
            }
           // cout<<"l size "<<l.size()<<endl;
            level.push_back(l);
        }
    }
    
    void print()
    {
        for( int i =0; i< level.size(); i++)
        {
            
             for( int j =0; j<level[i].size(); j++)
                {
                    cout<<level[i][j]<<" ";
                }
            cout<<endl;
        }
    }
    
    void levelorder( TreeNode* root)
    {
        if ( root == NULL) return;
        q.push(root);
        while(!q.empty())
        {
            vector<int> l;
           // cout<< "q size = "<<q.size()<<endl;
            int s= q.size();
            for(int i = 0; i< s;i++)
            {
                TreeNode* temp= q.front();
                q.pop();
                
                l.push_back(temp->val);
                if(temp-> left != NULL)
                    q.push(temp->left);
                if(temp-> right != NULL)
                    q.push(temp->right);
            }
           // cout<<"l size "<<l.size()<<endl;
            level.push_back(l);
        }
    }
};
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
