xxxxxxxxxxxxxxxxxxxxx DSU | UNION FIND Xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
class Solution {
    public:
     vector<int> parent;
     vector<int> rank;

public:
    int findCircleNum(vector<vector<int>>& g) {
        
        int n = g.size();
        parent.resize( n, -1);
        // all nodes are parent of themselves inititally, if parent[u] = -k thne u is leader of grp of k nodes
        rank.resize( n, 1); // initially no node is connected hence rank is 1 for all
        
        // edges
        for( int i =0 ; i < n ; i ++)
            for( int j = i+1; j<n ; j++)
            {
                if(g[i][j] ==1) // edge exists
                    addedge( i ,j);
            }
        // check how are parents
        int count =0;
        for( int i = 0 ; i <n ; i ++)
            if(parent[i] < 0)
                count++;
        return count;
        
   }
   
    void addedge( int i , int j )
        {
            // add edge if their parents are diff
            if( find(i) == find(j))
                return; // same parents, also condition for cycle present
            else 
                merge( i , j);
        }
    int find( int u) // return parent of u 
    {
        if( parent[u] < 0 ) // it is its own parent
            return u;
        else 
            return parent[u] = find(parent[u]);
    }
    void merge( int u , int v )
    {
        // merge by rank
        int a = find(u); // find parent of both of them
        int b = find(v);
        if( a == b) // both have same parents
            return;
        int ra= rank[u]; // rank of parent a
        int rb = rank[v];
        if( ra > rb) // a has more nodes chain in its grp, hence add b in a's grp, to keep parent chain hierachy as sort as possible
        {
            parent[a] += parent[b]; //add nodes in b to nodes of a
            parent[b]=a;
        }
        else if( ra < rb) // a has more nodes chain in its grp, hence add b in a's grp, to keep parent chain hierachy as sort as possible
        {
            parent[b] += parent[a]; //add nodes in b to nodes of a
            parent[a]=b;
        }
        else // both have same rank
        {
            parent[a] += parent[b]; //add nodes in b to nodes of a
            parent[b]=a;
            rank[a]++;
        }
    }
};

xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx check if bipartite using dfs xxxxxxxxxxxxxxxxxxxxxxxxxxx
vector<int> adj[101];
    vector<int> col; // IF COLORED THEN ITS VISITED
 bool main ()
{
     col.resize(n, -1);
     for( int i =0 ; i < n; i ++ )
                if( col[i] == -1) // if not vis. connected component
                    if( !dfs(i)) //if not bipartite
                        return false;
            return true; // if every component was bipartite
 }
 
bool dfs( int u, int par =-1, int c=0)
    {
      col[u]=c; // gice col to the node
        for( auto child: adj[u]) // visit all children
        {
          if( child == par) //not needed here but part of template
                continue;
          else if( col[child] != -1 &&   col[child]  == c) // if child is already colored and same as current
               return false;
          else if( col[child] == -1) // not colored
            {
              if( !dfs( child , u, c^1)) // send to further check and if further check isnt bopartite 
                    return false;
            }
        }
    
        return true; // every chain of child was bipartite
    }
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx BELMON ford xxxxxxxxxxxxxxx
//shortest path at max k +1 edges 
class Solution
{
public:
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
    {        
        vector<vector<int>> dp(K+2, vector<int>(n, INT_MAX));
        
        //dp[i][j] = Dist to reach j using atmost i edges from src
        
        for(int i = 0; i <= K+1; i++)
        {
            dp[i][src] = 0; // Dist to reach src always zero
        }
        
        for(int i = 1; i <= K+1; i++)
        {
            for(auto &f: flights)
            {
                //Using indegree
                int u = f[0];
                int v = f[1];
                int w = f[2];
                
                if(dp[i-1][u] != INT_MAX)
                    dp[i][v] = min(dp[i][v], dp[i-1][u] + w);
            }
        }
        
        return (dp[K+1][dst] == INT_MAX)? -1: dp[K+1][dst];
    }
};




// space optimized

class Solution
{
public:
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
    {        
        vector<vector<int>> dp(2, vector<int>(n, INT_MAX));
        
        //dp[i][j] = Dist to reach j using atmost i edges from src
        
        for(int i = 0; i <= K+1; i++)
        {
            dp[i%2][src] = 0; // Dist to reach src always zero
        }
        
        for(int i = 1; i <= K+1; i++)
        {
            for(auto &f: flights)
            {
                //Using indegree
                int u = f[0];
                int v = f[1];
                int w = f[2];
                
                if(dp[ (i-1 )  %2][u] != INT_MAX)
                    dp[i %2][v] = min(dp[i%2][v], dp[(i-1 ) %2][u] + w);
            }
        }
        
        return (dp[(K+1) %2][dst] == INT_MAX)? -1: dp[(K+1) %2][dst];
    }
};

xxxxxxxxxxxxxxxxxxxxxxxxxxx
