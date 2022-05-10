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

xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx