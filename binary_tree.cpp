
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
    {for( int i =0; i< level.size(); i++)
        {for( int j =0; j<level[i].size(); j++)
                cout<<level[i][j]<<" ";
            cout<<endl;}}
   
};
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx vertical order traversal xxxxxxxxxxxxxxxxxxxxxxxxxx
class Solution {
public:
    void dfs(TreeNode* root, int dist, int level, map<int, vector<pair<int, int>>> &m){
        if(!root)return;
        m[dist].push_back(make_pair(level, root->val));
        dfs(root->left, dist-1, level+1, m);
        dfs(root->right, dist+1, level+1, m);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> m;
        vector<vector<int>> ans;
        
        dfs(root, 0, 0, m);
        for(auto it:m){
            sort(it.second.begin(), it.second.end());
            vector<int> tmp;
            for(auto i:it.second)tmp.push_back(i.second);
            ans.push_back(tmp);
        }
        return ans;
    }
};
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  vertical order traversal in binary tree, using level order traversal xxxxxxxxxxxxxxxxxx
class Solution {
    public:
     vector<vector<int>> level;
    unordered_map< int, vector<pair<int,int>> > um;
    int mleft=1;
    int mright=-1;
     queue<pair<TreeNode*, int>> q;
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        levelorder(root, 0);
     //   print();
        
       vector< vector<int>> ans;
        
        
        for( int i =mleft; i<= mright; i++)
        {
            //int n = level[i].size();  // imp bec we cant access q size during loop when we are updating the size during the loop
            sort(um[i].begin(),um[i].end(),cmp);
            vector<int> suba;
            for(int j =0; j< um[i].size(); j++)
                suba.push_back(um[i][j].second);
            ans.push_back(suba);
        }
            //ans.push_back(level[i].back());
        return ans;
        
    }
  static  bool cmp( pair<int,int> const v1, pair<int,int>  const v2)
    {
        if(v1.first < v2.first) return true;
        else if (v1.first == v2.first && v1.second < v2.second) return true;
        else 
            return false;
    }
    
         void levelorder( TreeNode* root, int i)
    {
        if ( root == NULL) return;
        q.push({root , i});
              int  l=0;
        while(!q.empty())
        {
          
           // cout<< "q size = "<<q.size()<<endl;
            int s= q.size();
            for(int i = 0; i< s;i++)
            {
                TreeNode* temp= q.front().first;
                int ind = q.front().second;
                q.pop();
                um[ind].push_back({l,temp->val});
                mleft= min(mleft, ind);
                mright= max(mright, ind);
               
              //  l.push_back(temp->val);
                if(temp-> left != NULL)
                    q.push({temp->left , ind-1});
                  
                if(temp-> right != NULL)
                   q.push({temp->right , ind+1});
            }
           // cout<<"l size "<<l.size()<<endl;
           l++;
        }
    }
};
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
