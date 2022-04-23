class Solution {
    public:
    int ans=0;
    int m=0;
    int  n  =0;
    vector<vector<int>> vis;   
public:
    int numIslands(vector<vector<char>>& grid)
    {
         m = grid.size();
        n = grid[0].size();
        vis.resize(m,vector<int>(n));
        for(int i =0; i < m; i++)
        {
            for( int j = 0; j< n ; j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    ans++;
                    bfs(i,j,grid);
                } 
                
            }
        }
    
        return ans;
    }
    
    void bfs(int i , int j, vector<vector<char>>& grid )
    {
       
        //mark all the neighbours vis
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=1; // mark it vis
        vector<pair<int,int>> moves={ {1,0},{-1,0},{0,1},{0,-1}  };
        
        while(!q.empty())
        {
            pair<int,int> it;
            it= q.front();
            q.pop();
            for(auto move: moves)
            {
                int r = it.first + move.first;
                int c = it.second + move.second;
                if( r >=0 && r<m && c >=0 && c<n ) // in board range
                {
                    if(!vis[r][c] &&  grid[r][c]=='1')
                    {
                        //push and mark
                        q.push({r,c});
                        vis[r][c]=1;
                    }
                }
                else
                    continue;
             }
        }
    }
};
