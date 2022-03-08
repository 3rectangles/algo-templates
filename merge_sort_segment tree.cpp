
#include <bits/stdc++.h>
using namespace std;
#define M1 1000000007
#define M2 998244353
#define INT_MIN is -2147483648
#define ll long long
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



/*
ques: given an array of size N and Q queries (L,R), find number of elmns in range L,R which are 
strictly smaller than K. K is fixed for all queries
*/
const int n= 1000;
int arr[n+1]; // input array
vi seg[n+1]; // each array cell is vector container storing nos in sorted way  

void build(int index, int low, int high) 
{
    //parent node range is devided into 2 halves which is stored in 2 children
    // recursive way--> recursion build the two other half, iduction: joining children ans
    //  base case for children

    if(low==high)// size =1
        {seg[index].PB(arr[low]) ;
        return;
        }
    int mid= low + (high-low)/2;
    int lc = 2*i; //left child index
    int rc = 2*i+1; // right child index
    build( lc ,low,mid); //do for left child
    build( rc , mid+1, high); //do for right child
    merge(seg[lc].begin(), seg[lc].end(), seg[rc].begin(), seg[rc].end(), seg[index].begin() ); // merge is stl lib fnc to merge : https://www.geeksforgeeks.org/merge-in-cpp-stl/ 
    return ;
}

node query(int index , int low,int high, int l, int r)
{
    
    // NO OVERLAP, PARTIAL OVERLAP, COMPLETE OVERLAP
    if( low >=l &&  high <= r) // complete overlap
        return  upper_bound(seg[index].begin() , seg[index].end() , k-1) - seg[index].begin();
        // upper_bound( returns index of first elm which is striclty greater than k-1)
    if(high < l or r < low)  // no overlap
		return node{INT_MAX}; 
	//else now: partial overlap

    int mid= low+ (high-low)/2;
    int lc = 2*i; //left child index
    int rc = 2*i+1; // right child index
    node left= query( lc, low, mid , l,r );
    node right= query(rc,mid+1, high, l, r);
    return left+right;
}

int main()
{
    int size;
    cin>>size;
    for(int i =0; i<size; i++)
        cin>>arr[i]; // read the input array

    build(0, 0, size-1);  // low=0 i.e 0 based indexing on input array
    int q=0;
    cin>>q; // # queries
    while(q--)
    {   
        int l,r;
        cin>>l>>r; // l,r should be 0 based indexing on input array
        // if not then l-- and r--
       //  node ansnode = query(0,0,size-1, l,r);
         cout<< query(0,0,size-1, l,r) <<endl;
    }    
}
