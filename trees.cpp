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
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
const ll mod = 1e9 + 7,inf = 1e18;
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<typename T>
#define o_set(T) tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>
// doc link  for all alg0s: https://docs.google.com/document/d/1ZhXmeJ13_mvbBRWz0PRryFsXf8C6TjpbWc6Eqypq5nA/edit#
/*member functions :

1. findbridge(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[]) : prints bridges in undirected graph


*/


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

xxxxxxxxxxxxxxxxxxxxxxxxxxfinding centroid of tree xxxxxxxxxxxxxxx
// root tree. find subtree size of all
//do dfs and move to child node whose subtree size > n/2

int sub[200001];
int n;
vi ar[200001];
 
void subSize(int node ,int par) // subtree size
{
	sub[node] = 1;
	
	for(int child : ar[node])
	if(child != par)
	{
		subSize(child , node);
		sub[node] += sub[child];
	}
}
 
int centroid(int node , int par)
{for(int child : ar[node])
	if(child != par && sub[child] > n/2) return centroid(child , node); // no child has size>n/2 hence 
    //current node is centroid
	return node;
}
 
int main()
{// read tree
	subSize(1 , -1);// root at 1
	cout<<centroid(1 , -1); // start search from 1
}

xxxxxxxxxxxxxxxxxxxxxxxxxxxxx LONGEST DIAMETER, DP ON TREE XXXXXXXXXX
int n = 3e5 + 5;
vvvl adj(n);//we need to store the edge weights
vvl dp(n,vl(2));// //dp[u][0]: longest path  in subtree of u ending at u. dp[u][1]: longest path  in subtree of inclusind u and not ending at u. 
vl w(n);
ll ans = 0;
int main()
{// read tree
	cin>> n; // # nodes?
	for( int i =1; i<=n-1; i++) // n-1 edges for trees
	{
	if	cin>>u>>v;
		adj[u].PB(v); adj[v].PB(u);	
	}
	dfs(1); // rooting at node 1
	cout<< ans; // ans is max path in subtree of 1 ending at 1 or passing through 1
}

void dfs(int u, int p =-1)
{
	  dp[u][0]=0; dp[u][1]=0;	
	  for(auto v:adj[u])
	 {	
		 if(v==p) continue;
		  dfs(v,u); // done for childeren
		  l.PB(dp[v][0]); // pushing it in list for path passing through u , selecting best 2 children
	}
	sort(l.begin(), l.end());// decreaisng order sort. picking 2nd best child
	if(l.size()>0) // not a leaf node
	{
		dp[u][0]= l[0] +1;
		if(l.size()>1) // u have 2 children else dp[u][1]==0+
		dp[u][1]= l[0] +1+ l[1] +1;
	}
	else // leaf node
	{ dp[u][1]==0; dp[u][0]==0;}
	    ans = max(ans,max(dp[u][0],dp[u][1]));

}

xxxxxxxxxxxxxxxxxxxxxxxxxxxxx no of paths of k length in tree , DP ON TREE XXXXXXXXXX
// edge cas: simple paths
int n = 5e4 + 5,k = 505;
vvl dp(n,vl(k));
vvi adj(n);
ll ans = 0;
 
void dfs(int u,int p)
{
    dp[u][0] = 1; // base case. product of  count of paths of x len * count of path of k-x len 
 
    for (int v:adj[u]){
        if (v == p)continue;
        dfs(v,u); // calculate for child first
 
        for (int x = 1;x<=k;x++)
            dp[u][x] += dp[v][x - 1]; // for dp[u][x]: paths start at u of len x, add x-1 len path of every child
    }
    
    ans += dp[u][k]; // all paths start at u of len k
 
    ll tot = 0; // initialised to 0 for every node, count of paths passing through u of len k
    
    for (int v:adj[u]){ // O(# children * K)
        if (v == p)continue; //skip the par, par isnt in subtree of u
        
        for (int x = 1;x<=k - 1;x++) // x is[1,k-1]: to prevent -ve parameters, also beck len paths having u as endpoint already added 
            tot += dp[v][x - 1] * (dp[u][k - x] - dp[v][k - x - 1]); // add all k leng pair pasing through u, from every child 
	    // for every child of u (v) iterate over path of len 1 to k-1 and multiply with paths of complementary lengths.
        
    }
 
    ans += tot/2;//double counted joining paths 
}
 
int main()
{
    setIO();
    cin>>n>>k;
 
    for (int i = 1;i<=n - 1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v),adj[v].pb(u);
    }
 
    dfs(1,-1);
 
    cout<<ans;
    return 0;
}

