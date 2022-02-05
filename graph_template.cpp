using namespace __gnu_pbds;
#define mod 1000000007
#define M2 998244353
#define INT_MIN is -2147483648
#define ll long long
#define lli long long int
#define ld long double
#define pll pair<ll,ll>
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define F first
#define S second
#define PB push_back
#define DB pop_back
#define MP make_pair
#define MT make_tuple
#define G(a,b) get<a>(b)
#define V(a) vector<a>


static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<typename T>
#define o_set(T) tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>
// doc link  for all alg0s: https://docs.google.com/document/d/1ZhXmeJ13_mvbBRWz0PRryFsXf8C6TjpbWc6Eqypq5nA/edit#
/*member functions :

1. findbridge(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[]) : prints bridges in undirected graph
2. VariableSize_sliding_win(v,k,ptr=""): finds max/min wind allowing at max k constraint.   QUES: LONGEST SUBSTRING WITH K UNIQUE CHARACTERS
3. rabinkarp(srting st, string ptrn, V(ll) &ans):  returns all starting index in text(st) which matches to  ptrn . Matches string to text in O(N+M) , n= size of text/ string. M= size of ptrn
    sub func:   getHash(string key)  // returns polynomial hashing of string.: (key[0]*p^0+ key[1]*p^1+ ..key[n-1]*p^n-1) % mod
                txthash(string input_string ,V(ll) &dp, V(ll)&primes ) //dp[] stores all suffix hashes of st (text), primes[] stores power of p%mod



*/

xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx PRINTS BRIDGES IN UNDIRECTED GRAPHXXXXXXXXXXXXXXXXXXXXXX

void findbridge(int node, int parent, vector<int> &vis, vector<int> &in, vector<int> &low, int &timer, vector<int> adj[]) {
    vis[node] = 1; 
    in[node] = low[node] = timer++; 
    for(auto child: adj[node]) {
        if(child == parent) continue; // forward edge
        if(vis[child]==1) //  not parent hence ancestor, a back edge,  update path to ancestor
            low[node]= min( low[node], in[child] ); // checking if we can reach node from ancestor through another path
        
        else { // child not visited, a forward edge
            dfs(child, node, vis, in, low, timer, adj); // pass to dfs
            low[node] = min(low[node], low[child]);//  update path to ancestor, wont see this child again hence checking it here
            if(low[child] > in[node]) { // bridge detected no alternative path to child through ancestor or curr noded
                cout << node << " " << child <<<< " a bridge" endl;
            }
    }
}

int main() {
    int n, m;  // n= no of vertices, m = edges 
    cin >> n >> m; 
	vector<int> adj[n]; 
	for(int i = 0;i<m;i++) { // taking edges 
	    int u, v;
	    cin >> u >> v; 
	    adj[u].push_back(v);// undirected graph
	    adj[v].push_back(u); 
	}
	
	vector<int> in(n, -1); // initialise in time: indicates time at which we enter
	vector<int> low(n, -1);  // indicates if we can reach ancestor which is represented by its in- time
	vector<int> vis(n, 0); // visitred array
	int timer = 0; 
	for(int i = 0;i<n;i++) { // for all connected components, 0 based index of nodess
	    if(!vis[i]) {
	        dfs(i, -1, vis, tin, low, timer, adj);  // -1 passed as first parent 
	    }
	}
	
	return 0;
}
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

 xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx ARTICULATION POINT/ CUT VERTEX XXXXXXXXXXXXXXX

 int n; // number of nodes
<vector<int> adj[n+1]; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;
set<int> IS_CUTPOINT; // using set bec cut vertex can be neighbours of various nodes.
// in set will be unique

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0; // to count subtree of root node to decide if root is cut vertex
    for (int child : adj[v]) {
        if (child == p) continue; // was forward edge in dfs tree
        if (visited[child]) { // child is visited that is its ancestor -- a back edge
            low[v] = min(low[v], tin[child]); // update if another path exist to node thrpugh ancestor
        } else {  // child not visited a forward edge
            dfs(child, v);
            low[v] = min(low[v], low[child]);  // update low of current node
            if (low[child] >= tin[v] && p!=-1) // no path to child from ancestor hence curr node is cut vertex
                IS_CUTPOINT(v); // node shouldnt be root, will check for root later
            ++children; // for root node, if 2nd child isnt visited when dfs for 1st child was called, hence 2nd child belongs to
            // diff subtree. hence childree++ in unvisited child of root 1
        }
    }
    if(p == -1 && children > 1) // if more than one subtree add root to cut point vertex set
        IS_CUTPOINT(v);
}

void find_cutpoints() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) { // for connected components
        if (!visited[i])
            dfs (i);
    }
}


xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
#include <bits/stdc++.h>
using namespace std;


void findbridge(int node, int parent, vector<int> &vis, vector<int> &in, vector<int> &low, int &timer, vector<int> adj[]) {
    vis[node] = 1; 
    in[node] = low[node] = timer++; 
    for(auto child: adj[node]) {
        if(child == parent) continue; // forward edge
        if(vis[child]==1) //  not parent hence ancestor, a back edge,  update path to ancestor
            low[node]= min( low[node], in[child] ); // checking if we can reach node from ancestor through another path
        
        else { // child not visited, a forward edge
            dfs(child, node, vis, in, low, timer, adj); // pass to dfs
            low[node] = min(low[node], low[child]);//  update path to ancestor, wont see this child again hence checking it here
            if(low[child] > in[node]) { // bridge detected no alternative path to child through ancestor or curr node
                cout << node << " " << child <<<< " a bridge" endl;
            }
    }
}

int main() {
    int n, m;  // n= no of vertices, m = edges 
    cin >> n >> m; 
	vector<int> adj[n]; 
	for(int i = 0;i<m;i++) { // taking edges 
	    int u, v;
	    cin >> u >> v; 
	    adj[u].push_back(v);// undirected graph
	    adj[v].push_back(u); 
	}
	
	vector<int> in(n, -1); // initialise in time: indicates time at which we enter
	vector<int> low(n, -1);  // indicates if we can reach ancestor which is represented by its in- time
	vector<int> vis(n, 0); // visitred array
	int timer = 0; 
	for(int i = 0;i<n;i++) { // for all connected components, 0 based index of nodess
	    if(!vis[i]) {
	        dfs(i, -1, vis, tin, low, timer, adj);  // -1 passed as first parent 
	    }
	}
	
	return 0;
}
 xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx ARTICULATION POINT/ CUT VERTEX XXXXXXXXXXXXXXX

 int n; // number of nodes
<vector<int> adj[n+1]; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;
set<int> IS_CUTPOINT; // using set bec cut vertex can be neighbours of various nodes.
// in set will be unique

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0; // to count subtree of root node to decide if root is cut vertex
    for (int child : adj[v]) {
        if (child == p) continue; // was forward edge in dfs tree
        if (visited[child]) { // child is visited that is its ancestor -- a back edge
            low[v] = min(low[v], tin[child]); // update if another path exist to node thrpugh ancestor
        } else {  // child not visited a forward edge
            dfs(child, v);
            low[v] = min(low[v], low[child]);  // update low of current node
            if (low[child] >= tin[v] && p!=-1) // no path to child from ancestor hence curr node is cut vertex
                IS_CUTPOINT(v); // node shouldnt be root, will check for root later
            ++children; // for root node, if 2nd child isnt visited when dfs for 1st child was called, hence 2nd child belongs to
            // diff subtree. hence childree++ in unvisited child of root 1
        }
    }
    if(p == -1 && children > 1) // if more than one subtree add root to cut point vertex set
        IS_CUTPOINT(v);
}

void find_cutpoints() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) { // for connected components
        if (!visited[i])
            dfs (i);
    }
}


xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx M colOURING GRAPH,, chromatic number XXXXXXXXXXXXXXX

 void givecolor(int i, int n)
 {
     // using bfs to give min possible colors
 
     queue<int> q;
     q.push(i);
     vector<int> vis(n,0);
     int mx= max(2,n/2); // max required color
    vector<int>color_used(mx,0); //check which color have been used in neighbours
    vector<int> have_color; //which node have which color
     while(!q.empty())
     {
         // go to neighbours check which colors have been assigned and assign lowest availabe color
        int node=q.front();
         q.pop();
        vis[node]=1;//will be colored
        for(int it: adj[node]) // adjacent 
        {
            color_used.clear(); 
            if(vis[it]==0) //unvisited dont have color
                q.push(it); //will be assigned color
            else // have color
            {
                color_used[have_color[it]]=1;
            }
            //assign available color
            for(int i =0; i < color_used.size();i++)
            {
                if(color_used[i]==0) //lowest available color
                    break;
            }
            //if(i>1) cout<<"not a bipatite graph";
            have_color[node]=i;
            color[i].PB(node); //which nodes have ith color
            

        }
     }
 }


int main() {
    int n, m;  // n= no of vertices, m = edges 
    cin >> n >> m; 
	vector<int> adj[n]; 
	for(int i = 0;i<m;i++) { // taking edges 
	    int u, v;
	    cin >> u >> v; 
	    adj[u].push_back(v);// undirected graph
	    adj[v].push_back(u); 
	}
	
	unordered_map<vector<int>> color; // store which nodes are given which color
    vector<int> vis(n, 0); // visited array
	
	for(int i = 0;i<n;i++) { // for all connected components, 0 based index of nodess
	    if(!vis[i]) {
            color.clear(); 
            givecolor(i,n+10);  // 
            
            //if(color.size()==2) cout<<"BIPATITE GRAPH"; 
	    }
	}
	
	return 0;
}

xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx bipatite graph using dfs xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
 vector<int> col(2,0); // freq of color
 vector<int> color(n,0);
  vector<int> vis(n, 0); // visited array


 int bipatite( int node, int c)
 {
     // giving colors using dfs
    col[c]++;// inc freq of color c
     color[node]=c;
     vis[node]=1; // marked visited
     for(int it: adj[node])
     {  
         if(vis[it]==0) // not colored, give color opp to node
            {
                int x=bipatite(it,c ^1);
                if(x==-1) // not a bipatite graph
                    return -1;
            }
        else // already colored
        {
            if(color[it]==color[node])
            return -1; // not bipatite
        }    
     }
 }

 
int main() {
    int n, m;  // n= no of vertices, m = edges 
    cin >> n >> m; 
	vector<int> adj[n]; 
	for(int i = 0;i<m;i++) { // taking edges 
	    int u, v;
	    cin >> u >> v; 
	    adj[u].push_back(v);// undirected graph
	    adj[v].push_back(u); 
	}
	
    for(int i = 0;i<n;i++) { // for all connected components, 0 based index of nodess
	    if(!vis[i]) {
            col[0]=col[1]=0;
            
           int x= bipatite(i,0);  // giving 0 color to i
            if(x==-1) cout<<" not a BIPATITE GRAPH"; 
	    }
	}
	
	return 0;
}

xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx cycle retrieval,find cycle in undirected  graph, using dfs xxxxxxxx
int start=-1; // global
int dfs(node, p)
{
    vis[i]=1;
    for(int child: adj[node])
    {
        if(vis[child]==1 && child!=p) // found cycle, child is start of cycle
        {
            start=child;
            return node; // end of cycle
        }
        else if (vis[child]==0) // not visited
        {
            par[child]=node;
            int x=dfs(child,node);
            if (x)// cycle  found
            return x;
        }
    }
    return 0; // no cyle found
}

void cycle(node)
{
    unordered_map<int> um; // cyclic node hash table
    int x=dfs(node,-1);
    //CYCLIC NODES ARE
    if(x)// contains cycle
    back=x;
    while(back!= start)
    {
        um[back]=1;
        int back= par[back];
    }
    um[back]=1; //pushing start node in cycle
}

xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx find cycle in directed graph using dfs xxxxxxxxxxxxxxxx
int n, m;
vector<int> adj[n];
vector<int> vis(n,-1);
stack<int> recursionStack;
vector<bool> rsFlag(n,-1);

bool dfs(int u)
{
	vis[u] = true;
	recursionStack.push(u);
	rsFlag[u] = true; // to mark node in current path, ,recursion stack flag
	for(auto v: adj[u])
	{
		if(!vis[v])
			if(dfs(v)) // if cycle detected
				return true;
 
		if( vis[v] && rsFlag[v]) // cycle detected
		{
	
			return true;
			//no more dfs;
		}
	}
	recursionStack.pop(); // backtracking hence remove from current path
	rsFlag[u] = false;
	return false;
	//no cycle was detected
}

int main()
{
    // read the graoh in adj list
    for(int i = 0; i < m; ++i) // reading edges
	{
		int u, v;
		cin >> u >> v;
		adj[u].insert(v);
	}
	visit_all();
	if(recursionStack.empty()) // no cycle
	{		
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

    vector<int> ans;
    while(!recursionStack.empty())
	{
		ans.push_back(recursionStack.top());
		recursionStack.pop();
	}
    reverse(ans.begin(), ans.end()); // if cycle is 1 2 3 4 1,  ans has 1 2 3 4 
    for(auto u: ans)
	{
		cout << u << " ";
	}


}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx Subtree XXXXXXXXXXXXXXX
vector<lli> size(n,0); // global

subtree(i)
{
    size[i]=1; // atleast 1 size
    lli a=0;
    for(int child: adj[node])
    {
        if(size[child]==0 &&(1)) // unvisited & checking some other condition that child node has to satisfy
            a+=subtree(child);
        // no need to check for unvisted child bec its tree, not a graph    
        
    }
    return size[i]= size[i]+a;
}

xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  multisource bfs  distance, level order traversal xxxxxxxx
vector<int> start; //global contains starting sources
time=0;// to cover whole graph
bfs()
{
    queue<int>q;
    for(int i=0;i< start.size();i++)
    {q.push(start[i]); 
    dis[start[i]]=0; // source dist/ level =0
    vis[start[i]]=1;
    }

    while(!q.empty())
    {
        for( int j=0; j< q.size();j++) // for levels
        {   node=q.front(); q.pop(); 
            this_level.clear();
            for( auto child: adj[node]) // visiting every neighbor/child
            {
                // if (child == to search)
                    // return dist[node]+1;  i.e hops+1
                if(vis[child]==0) // unvisited push and mark
                {
                  this_level.PB(child);   // level order traversal
                    q.push(child);
                    vis[child]=1;
                    dis[child]=dis[node]+1; // level inc or distance from source nodes
                   // this_level.PB(child);
                }
                if(vis[child]==1) // already visited either parent or visited by some other source
                    {
                        // acc to ques
                    }
            }
        }
        time++; 

        level.PB(this_level); // nodes in level. level.size()= time= hops

    }
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx count of shortest path in undirected graph xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx


vector<int> dis(n,INT_MAX);
vector<int> num(n,0);
vector<int> par(n,-1);
bfs(i,n)
{
    queue<int>q;
    q.push(i);
    dis[i]=0; //src
    

    while(!q.empty())
    {
        node=q.front(); // once taken out from q its proven its the shortest path for this node. lemma 2
        q.pop();
        for(int it: adj[node])
        {
            if(dis[it]>dis[node]+1)  //relaxation
            {
                dis[it]=dis[node]+1;
                q.push(it); // push
                par[it]=node;
                num[it]=num[node]; // stores shortest path till, all shortest path to it comes from node, bec dis got relaxed
            }

            if(dis[it]=dis[node]+1) //not shortest but of same length hence got one more shortest path
                { 
                    num[it]=num[node]+1;
                } 
        }
    }
}


xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx dfs on grid: count of connected components in grid xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//  https://www.youtube.com/watch?v=WUqkIH1gHMM&list=PL2S6Mj7iLqEjNVq0e-pZ9rSnpAacHzVm3&index=3

int n, m; //rows and columns
int components=0;
vector<vector<bool>> visited; // grid image to keep track of path and blocked cells in grid. mark blocked cells visited will never visit them.
vector<pair<int,int>> moves{ {-1,0},{1,0},{0,-1},{0,1}}//up down left right

// cell boundary, blocked cells and visited cells in current path
isvalid(int x, int y) // if this pos is valid or not
{
    if( x<0 or x>= n or y<0 or y>= n) // cell boundary
        return false;
    if(vis[x][y] == 1) // already visited or blocked
        return false;
    return true;
}

void dfs(int x, int y)
{
    // if x,y is target paths++
    vis[x][y]=true;
    for( auto it : moves)
    {
        if(isvalid(x + it.first,y + it.second))
            dfs(x + it.first,  y + it.second);
    }
    // before returning unmakr vis cell,( if finding all possible paths , same like euler tour)
}
void components()
{

    for(int i=0; i<=n; i++ )
    {
        for(int j=0;j<=n ; j++)
        {
            if (grid[i][j]=="blocked")
                vis[i][j]= true;
            if(!vis[i][j])
            {
                dfs(i,j);
                components++;
            }
        }
    }
}
// dp on 


xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx dijkstra Algo: shortest path in weighted graph xxxxxxx
# define INF 0x3f3f3f3f
typedef pair<int, int> iPair;
void shortestPath(int src,n)  // Prints shortest paths from src to all other vertices
{   // https://www.geeksforgeeks.org/implement-min-heap-using-stl/
	priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
	vector<int> dist(n, INF);
	pq.push({0, src});  
	dist[src] = 0;
    while (!pq.empty())
	{
    	int u = pq.top().second;  // {dist, u} in pq
        int d=pq.top().first; // d cost to reach u, for thgis path
        pq.pop();

        if(dist[u] <  d) continue;  // if we already know a path to reach u better than this, so avoid this path 
        for (auto it : adj[u]) //it ={v,wt}
		{
	        int v = it.first;
			int weight = it.second; //edge weight
            if (dist[v] > d + weight) // If there is shorted path to v through u.
			{
				dist[v] = d + weight;// Updating distance of v
                par[v]=u; // Updating par of v
				pq.push(make_pair(dist[v], v));
			}
		}
	}
}

xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx k shortest path using dijkstra  xxxxxxxxxxxxxxx

lli inf= 1e9;
vector<vector<int> > dis(n + 1, vector<int>(k, inf)); // Vector to store distances
typedef pair<int, int> ppi;
void findKShortest(int src, int n, int m, int k) // Function to find K shortest path lengths
{
    priority_queue< ppi, vector<ppi>, greater<ppi> > pq; // Initialization of min priority queue
	pq.push({ 0, src }); // src
	dis[1][0] = 0; // dist[i][0] stores shortest dist, dist[i][k-1] stores kth shortest dist
        
        while (!pq.empty()) {
		// Storing the node value
		int u = pq.top().second;

		// Storing the distance value
		int d = (pq.top().first);
		pq.pop();
		if (dis[u][k - 1] < d)
			continue;
		vector<pair<int, int> > v = g[u]; // neighbour vertices of u

		// Traversing the adjacency list
		for (int i = 0; i < v.size(); i++) {
			int dest = v[i].first;
			int cost = v[i].second;

			// Checking for the cost
			if (d + cost < dis[dest][k - 1]) { // whatever the scenario the kth dist will be popped out always hence only check that
				dis[dest][k - 1] = d + cost;

				// Sorting the distances
				sort(dis[dest].begin(), dis[dest].end());

				// Pushing elements to priority queue
				pq.push({ (d + cost), dest });
			}
		}
	}
}

// Driver Code
int main()
{
    int src=1;
	findKShortest(src, N, M, K);
    // k distances to nth node 
    for(int i:dis[n])
    {
            cout<<i<<endl;
    }

	return 0;
}

xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx single source longest path/:  bellmon fordxxxxxxxx
// mulitply all edges weight by -1 to find single source longest path

lli inf=1e17+1000;
vector<int> dis(n+1,inf);
struct triplet
{
    int first; int second;int third;
};
vector< triplet> edges;

int bellmon(int src)
{
    dist[src]=0;
    // rest all are inf
    for(int i=1;i<n-1;i++) //n-1 relaxations for all edges
    {   bool flag=false;
        for (auto e: edges)
        {
            int u= e.first;
            int v=e.second;
            int wt= e.third;
            if(dis[u]==inf) continue;// prevent overflow inf + wt
            if(dis[v]> dis[u] + wt) //relax
            {
                dis[v]= dis[u] + wt;
                flag=true;
            }
        }

        if(!flag) // not a single relaxation happened
            break;
    }

    // checking for negative cycle
    for (int e=1; e<=m;e++)
        {
            int u= e.first;
            int v=e.second;
            int wt= e.third;
            if(dis[v]> dis[u] + wt) //relax
            {
                return -1; // negative cycle found
            }
        }

    return 0;

}

xxxxxxxxxxxxxxxxxxxxxxxxxxxxx retrieve negative cycle in graph and print it xxxxxxxxxxxxxxx
lli inf=1e17+1000;
vector<int> dis(n+1,inf);
struct triplet
{
    int first; int second;int third;
};

vector< triplet> edges;
vecttor<int> par(n,-1);
vector<int> cycle;

int negativecycle(int src)
{
    dist[src]=0;
    // rest all are inf
    for(int i=1;i<n-1;i++) //n-1 relaxations for all edges
    {   bool flag=false;
        for (auto e: edges)
        {
            int u= e.first;
            int v=e.second;
            int wt= e.third;
            if(dis[u]==inf) continue;// prevent overflow inf + wt
            if(dis[v]> dis[u] + wt) //relax
            {
                dis[v]= dis[u] + wt;
                flag=true;
                 par[v]=u;
            }
        }

        if(!flag) // not a single relaxation happened
            break;
    }
    int c=0; int relaxant=-1;
    // checking for negative cycle
    for (int e=1; e<=m;e++)
        {
            int u= e.first;
            int v=e.second;
            int wt= e.third;
            if(dis[v]> dis[u] + wt) //relax
            {
                c= -1; // negative cycle found
                relaxant= u; // or v doesnt matter
            }
        }
    if(c==0) return -1; //  no negative cycle found
     if (C != -1) {
  
    for (int i = 0; i < n; i++) // retracing n-1 times to make sure we land up in negative cycle
         relaxant  = par[relaxant];
        
    // storing cycle
    
    int start=relaxant;
    while(true)
    {
        cycle.PB(relaxant);
        relaxant=par[relaxant];
        if(relaxant==start) break; // cycle complete
    }

   reverse(cycle.begin(), cycle.end());
 return 0;

}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	cin >> n >> m;
	
	for(int i = 0; i < m; ++i)
	{
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v,c}); // directed graph
	}
 
	if(negativecycle()==-1) cout<< "No  negative cycle";
    else{
        for(auto v: cycle)
		{
			cout << v << " ";
		}
 
		cout << endl;
    }
    return 0;
}

xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  cheapest flight route with a coupn : dijkstra modified xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

// https://www.youtube.com/watch?v=GZtZXhir7Wg&list=PL2S6Mj7iLqEjNVq0e-pZ9rSnpAacHzVm3&index=16
// ques: https://cses.fi/problemset/task/1195 
#define inf 1e17;

typedef pair<int, pair<int,int> ippi; // {cost,{node, coupon flag}}
vector<lli> dist(n,inf);
vector<lli> distc(n,inf);
vector<pair{int,int}> adj[n+10];


void dij(int src) //  ans is distc[n]
{
     priority_queue< ippi, vector<ippi>, greater<ippi> > pq; // Initialization of min priority queue
     dist[src]=0;
     distc[src]=0;
     pq.push({0,{src,0}}); // {src,0}: node and coupon not used

    while (!pq.empty())
	{
        int d=pq.top().first; //  { dist,{node, coupon flag} }  in pq
    	int u = pq.top().second.first;  // {dist, coupon flag} in pq
        int f = pq.top().second.second; 
		pq.pop();

        if(f==1 && distc[u] <d  ) continue; //coupon used and still know better path to u where we used coupon hence skip
        if(f==0 && dist[u] <d  ) continue; //coupon not  used and still know better path to u where we didnt  used coupon hence skip
        
         for (auto it : adj[u]) //it ={v,wt} in adj list
		{
	        int v = it.first;
			int weight = it.second;
            if(f==0) // coupon not used
            {
                if (dist[v] > d + weight) // not using coupon
                    {
                        dist[v] = d + weight;// Updating distance of v
                        par[v]=u; // Updating par of v
                        pq.push({ dist[v],{v,0}});
                    }  
                if (distc[v] > d + weight/2 ) // using coupon
                    {
                        distc[v] = d + weight/2;// Updating distance of v
                        par[v]=u; // Updating par of v
                        pq.push({ distc[v],{v,1}});
                    }  
                    
            }
            if(f==1) // coupon  used
            {
                if (distc[v] > d + weight) // using coupon
                    {
                        distc[v] = d + weight;// Updating distance of v
                        par[v]=u; // Updating par of v
                        pq.push({ distc[v],{v,1}});
                    }  
            }
        }
	}
}

 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	cin >> n >> m;
	
	for(int i = 0; i < m; ++i)
	{
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v,c}); // directed graph
	}
 
	dij();
    cout << disc[n] << endl;
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx topological sort, kanhs algo xxxxx
int n, m;
vector<int> degree;// indegree of every node
priority_queue<int, vector<int>, greater<int>> noInDeg;
vector<vector<int>> g

topo()
{
	for(int i = 1; i <= n; ++i)
	{
		if(!degree[i])
			noInDeg.push(i);   // all nodes having indegree 0, topo start from here
	}
 
	vector<int> ans;
	while(!noInDeg.empty())
	{
		int u = noInDeg.top();
		noInDeg.pop();
		ans.push_back(u); // add to topo sort
		for(auto v: g[u])
		{
			--degree[v];// go to every neighbor vertex decrease the indegree by 1
			if(!degree[v]) noInDeg.push(v); // when indegree become 0 add to queue
		}
	}
} 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	g.resize(n+1);
	degree.resize(n+1);
 
	for(int i = 0; i < m; ++i) // read all edges and note their indgree
	{
		int u, v;
		cin >> u >> v; // u--> v
		g[u].push_back(v);
		++degree[v];  // indegree[v]+=1
    }

    topo();    

	if(ans.size() != n) // topo sort not possible contains cycle
	{
		cout << "IMPOSSIBLE";
	}
	else
	{
		for(auto u: ans)
			cout << u << " ";
	}
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx all possible paths from src to dest in  dag directed  acyclic graph/ or any graph using dfs xxxxxxxx

int n, m;
vector<int> adj[n];
vector<int> vis(n,-1);
stack<int> path;
vector<bool> pathflag(n,-1);

bool dfs(int u, int dst)
{
	// vis[u] = true;
	path.PB(u);
	pathflag[u] = true; // to mark node in current path, ,recursion stack flag
    if(u==dst) // reached dst, possible path
    ans.pb()
	for(auto v: adj[u])
	{
        if( !pathflag[v]) // if not part of current path go ahead 
		{
            dfs(v,dst);
		}
	}
	path.pop_back(); // going back no more in current path
	pathflag[u] = false; // to mark node in current path, ,recursion stack flag
	//no cycle was detected
}
// Time Complexity: O(V^V).  from each vertex, v connections should use topo sort instead for DAG
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxxxx  count possible paths in dag using topo sortxxxxxxxxxxxxxxxxxxxxxxxx

int top_sort()
{   
    // pruning
    src=1;
	queue<int> q;
	for(int i = 2; i <= n; ++i) // not including src node
	{
		if(inDegree[i] == 0)
		{
			q.push(i);	
		}
	}
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(auto v: g[u])
		{
			--inDegree[v];
			if(inDegree[v] == 0)
				q.push(v);
		}
	}
	q.push(1); // starting topo only from src node
	cnt[1] = 1; // path count to src is 1
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(auto v: g[u])
		{
			--inDegree[v];
			cnt[v] = cnt[v] + cnt[u];
			cnt[v] %=  modb;  //if mmentioned in ques to mod total paths possible
			if(inDegree[v] == 0)
				q.push(v);
		}
	}
    return cnt[dst];
}


xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
---binary lifting code / successor graphs 
--kosaraju- strongly conneted components
---mst -kruskal
----dsu on trees
coin collector cses ---  dfs in scc visits all nodes of that scc. starting from one scc which nodes we can visit depends on DAG of scc. longest path in scc. can use dp no need for topo sort.
--longest path in dag // https://www.youtube.com/watch?v=BrLekXK2hxg
--Eulerian Path/Circuit algorithm (Hierholzers algorithm) in graph --// https://www.youtube.com/watch?v=8MpoO2zA2l4  cses ques https://cses.fi/problemset/task/1693
De Bruijn sequence - leetcode hard -  https://leetcode.com/problems/cracking-the-safe/ 

 --DP on Graph With Bitmasking hamiltoninan path//  https://www.youtube.com/watch?v=e9BQcgI-gWI 
 2 sat - https://www.youtube.com/watch?v=0nNYy3rltgA


xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx longest path in dag
lli mx= -1e17;
 void dfs(int u)
{
    // same code as subtree
    vis[u]=1;
    dp[u]=0; // atleast 2 nodes for 1 unit path, 1 edge takes 2 nodes
    for(auto child: adj[u])
    {
        if(!vis[child])
        {
            dfs(child);
        }
        // now visited, and we know longest path from child update for u
        dp[u]= max(dp[u],dp[child]+1);
    }
    mx=max(mx,dp[u]); // stores longest path from any u to any destination
}
int main()
{
    // read graph
    for(int i=0; i<n;i++)// for connected components
        if(!vis[i]) dfs(i);
    return mx;
}

xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx eulerian path directed graph xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
vector<int> in(n,0);
vector<int> out(n,0);
vector<int> adj[n];

int main()
{
    int n, m;
    cin>>n;
    n+10; // extra space precaution
    while(m--)
    {
        int u,int u;
        cin>>u>>v;
        adj[u].PB(v);
        out[u]++; in[v]++;
    }
    if(eulerian()>0) 
        cout>>"path exist in ans vector";
    else
        cout>>"path doesnt exists";
}

int eulerian()
{
    // check if exist
    //  decide starting  point
    // run dfs and store the path
    // chewck if contains all edges for no disconnected graph

    if(!exists())
    {
        return -1;
    }
    start=startpoint();

    dfs();

    if(ans.size()==m+1) return 1;
    return -1;
}

void dfs( int u)
{ // doing for edges, keep travelling till edges available
    // no need for visited array as doing for edges not nodes
    while(out[i]>0)
    {
        dfs(adj[u].back()); // access last child
        adj[u].popback();// delete last child
        out--; // dec edges left to traversal
    }
    ans.PB(i); // while retracing add to ans

}
startpoint()
{ //for euler path: start point is node having out[i]==in[i]+1
    // for undirected graph: start point is node having odd edges. note undirected graph has total even degree. 
// odd degree appears in pairs
    int startpoint=1;
    for(int i=1; i <=n;i++)
    {
        if(out[i]==in[i]+1) return i; // start for euler path

        else if(out[i]>0) startpoint=i; //for euler circuit. cond to provide singleton node
            
    }
    return startpoint;
}

int exists()
{ //checks: if indegree= outdegree (even) for all nodes. start and point can be exception
    //  in euler path start point has 1 extra out degree, in point have 1 extra in degree. they appear together
    // for euler circuit all nodes have outdgree == indgree
    // for undirected graph-- even degree for all nodes, except  for start and end point can have odd degree
    int start,end=0;
    for(i=1;i<=n;i++)  // nodes start from index 1
    {
        if(out[i]==in[i]) continue;  // even in and out
        if(out[i]==in[i]+1) start++; // start and end  in euler path appears together
        if(in[i] ==out[i]+1) end++;
        if(out[i]>in[i]+1) return 0; // rest all are impossible
        if(in[i] > out[i]+1) return 0;
    }
    if(start==1 && end==1) return 1;// euler path
    if(start==0 && end==0) return 1;// euler circuit
    return 0; 
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx DSU xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

struct edge{
    int u;
    int v;
    int wt;
};
int n=1e5;
vector<edge> edges;
vector<int>par(n,-1); // initially all form single set
vector<int>ranks(n,1); // initially all form single set
vector<int> a5;


int find( int u)
{
    if(par[u]<0) return u;
    return par[u]=find(par[u]);
}
void merge(int x, int y)
{
    int a= find(x);
    int b= find(y);
    if( rank[a]>rank[b]) //  b's  tree is larger
        {
            par[a]+=par[b]; //INCREASE set size of a
            par[b]=a; // update parent of b
        }
    if( rank[b]>rank[a]) //  a's  tree is larger
        {
            par[b]+=par[a]; //INCREASE set size of a
            par[a]=b; // update parent of b
            a5[]
        }
    else { // both tree have same size
        
        par[a]+=par[b];
        par[b]=a;
        rank[a]++;
    }
        
}
void addedges()
{
    //add edge. union if par of u, v are diff . if same parnts, cycle exists
    while(auto e:edges)
    {
        if(find(e.u)==find(e.v) cout>>"cycle";
        union(e.u,e.v);
    }
}

int main()
{
    int m , int u, v;
    int wt=1;
    while(m--)
    {
        cin>>u>>v>>wt;
        edges.PB({u,v,wt});
    }
    addedges();
}

xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx kruskal algo
// sort edges
// loop for n-1 edges, if no cycle add edge to graph
xxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxx successor graph / binary lifting xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// uses binary lifting 

#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

// N = maximum number of nodes
// L = log2(N) + 2
const int n= 2e5+1, level = 30;

vector<vector<ll>> table(n,vector<ll>(level,-1));
filltable()
{
    dfs(1); // for trees, for  successor graph table[i][0]=directed node
    for(int l=1;l<=level;l++) // fill levels for all nodes
    {
        for(i=1;i<=n;i++) // all nodes
        { // to fill 2^l level use 2^ (l-1) level
            if(table[i][l-1] == -1 or table[i][l-1] ==i ) //if no ancestor or self cycle in graph
                    table[i][l]=table[i][l-1];
            else
                ll x==table[i][l-1]; // ancestor i at  2^l-1 level
                table[i][l]=table[x][l-1];
        }
    }
}

void dfs(int u,int p=-1, int h=0)
{   
    // no cyces in tree hence vis array not required
    table[u][0]=p;
    height[u]=h;
    for(int child : adj[u]) 
        {
            if(child!=p)
                dfs(child,u,h+1);
        }
}

int lca(int x, int y)
{
    if(height[x]<height[y]) swap(x,y); // assuming x is deeper than y
    // lift x to the level of y
    int d= height[x]- height[y];
    while(d>0)
    {
        int i=log2(d);
        x=table[x][i];
        d=d-(1<<i);
    }
    if (x==y) //y isancestor of x
        return y;

    // both are at same height, lift both of them till 1st diversion point in tree
    for(int i =30; i>=0; i--) // running back loop imp
    {
        if(table[x][i]!=-1 && table[y][i]!=-1) // both their ancestors exist and they arent same.
        {
            if(table[x][i]!=table[y][i]) // if this isnt ancestor then lift
                {   x=table[x][i];
                    y=table[y][i];
                }                    

        }
    } // x and y at diversion  point. lift them up by 1 to get to lca
    return table[x][0]; 
}

//find the k-th ancestor of x
int lift(int x, int k) {
    for (int i = 0; i < level; ++i)
        if ((1<<i) & y)
            x = table[x][i];
    return x;
}

xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx kosaraju, scc, strongly connected xxxxxxxxxxxxxxx

// do topo 
// flip edges
//run dfs in reverse topo sort
const int n =1e5;
stack<int> recursionStack;
int components=0;
vector<int> vis(n,0);
vector<int> vis2(n,0);
vector<vector<int>> components_grp();


scc() //exists only in directed graph
{
    while(!recursionStack.empty())
    {
        node=recursionStack.top(); recursionStack.pop();
        if(!vis2[node])
            {
                components++; //compon
                grp.clear();               
                dfs(node); 
                components_grp.PB(grp); //componenet1 in component_grp[0]
            }
    }
}

bool reversedfs(int u)
{
	vis[u] = true;
	for(auto v: adj[u])
	{
		if(!vis[v])
			(dfs(v)) // if cycle detected
	}
    recursionStack.push(u);    
}
bool dfs(int u)
{
	vis2[u] = true;
    grp.PB(u);
	for(auto v: adj[u])
	{
		if(!vis[v])
			(dfs(v)) // if cycle detected
	}
}

int main()
{
    int m;
    while(m--){
        int u,v;
        cin>>u>>v;  //directed graph only
        g[u].PB(v);
        // reverse the edges
        adj[v].PB(u);
    }
    scc();
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx hamiltonian path, cover all nodes from 1 to N
// use bit mask to denote which cities have been visited
const int n =20; // chenge acc to ques
vector<int> adj[n];
vector<vector<int>>dp( n, vector<int>( (1<<n) ,-1));
solve(int u,mask)
{
    if(u==n && __builtin_popcount(mask)==n) // reached dest with all cities traveled
        return 1;
    if(u==n) return 0;

    if(dp[u][mask] != -1) return dp[u][mask];

    // visit unvisited cities 
    ll ans=0;
    for(int city: adj[u])
    {
        if(mask & ( 1<< (city-1) )) // city is visited
            continue;
        //not visited
        ans= (ans+solve(city, mask^( 1<< (city-1) )) ) %mod; // city index start from 1
    } 
    return dp[u][mask] =ans;
}

	
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx spanning tree with one 