

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

xxxxxxxxxxxxxxxxxxxxxx segment tree with nodes  xxxxxxxxxxx
// build ,  point update, query , nodes in segment tree

const int n= 2e5;
int arr[n+1]; // input array

struct node{
    int a;
};
node seg(4*n +5); // array of struct

node f(node left, node right) // returns struct node
{
    node ans;
    ans =min(left.a, right,a);
    return ans; // returns node having computation of LC node & R Cnode
}
void build(int index, int low, int high) 
{
    //parent node range is devided into 2 halves which is stored in 2 children
    // recursive way--> recursion build the two other half, iduction: joining children ans
    //  base case for children

    if(low==high)// size =1
        {seg[index]= {arr[low]};
        return;
        }
    int mid= low + (high-low)/2;
    int lc = 2*i; //left child index
    int rc = 2*i+1; // right child index
    build( lc ,low,mid); //do for left child
    build( rc , mid+1, high); //do for right child
    seg[index]= f(seg[ lc ],seg[ rc ]); // do for parent node
    return ;
}

void update(int index, int low, int high, int key, int value)
{
    if(low == high) // reached leaf node
    { seg[ind]= value; return;}
    int mid= low+ (high-low)/2;
    if ( key <= mid) //have to update in left size else in right side
        update(2* index,low, mid, key , value);
    else
        update(2*index+1 , mid+1, high, key ,value);
    // update dome for children
    seg[index] =  f(seg[2 * index], seg[2 * index+1];  
}

node query(int index , int low,int high, int l, int r)
{
    
    // NO OVERLAP, PARTIAL OVERLAP, COMPLETE OVERLAP
    if( low >=l &&  high <= r) // complete overlap
        return seg[index];
    if(high < l or r < low)  // no overlap
		return node{INT_MAX}; 
	//else now: partial overlap

    int mid= low+ (high-low)/2;
    int lc = 2*i; //left child index
    int rc = 2*i+1; // right child index
    node left= query( lc, low, mid , l,r );
    node right= query(rc,mid+1, high, l, r);
    return f(left,right);
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
         node ansnode = query(0,0,size-1, l,r);
         cout<< ansnode.a <<endl;
    }    
}
