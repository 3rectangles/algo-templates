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

xxxxxxxxxxxxxxxxxxxxxxxxxxxxx
 