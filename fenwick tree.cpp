using namespace __gnu_pbds;
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


const int n=2e5;
vi arr; // input array
vi bit(n+1); // fenwick tree starts from index 1
//bit[i] stores sum from range j+1 to i. where j= remove_last_set_bit(i)
//bit[12]= sum from range (9-12)\
// bit[i]= i where i is odd index
//12 = 1100 --> remove last set bit --> 1000=8 

int sum(int i) // sum from arr[0] to arr[i]
{
    int ans=0;
    while(i>0)
    {
        ans+=bit[i];
        i= i- ( i & (-i) );
    }
    return ans;
}


// increases ith value by x 
//to index i, to replace ith index by x add x-arr[i]
 // arr[i] is included in bit[i] onwards.
void update(int i, int x) 
{ 
    while(i<=n)
    {
        bit[i] + = x;
        i= i+  ( i & (-i) );
    }
}

int main()
{
    int s=0; // input array size
    cin>>s;
    for(int i =1; i< = s; i++)
    { 
        cin>> arr[i]; // read arr startig from index1
        update(i, arr[i]); // built BIT TREE
     
     } // storing fro index 1 bec bit[0] is undefined, bit[1]=arr[1]
   
    int q;
    cin>> q;
    while(q--)
    {
        int type;
        cin>>type;
        if(type == 1) // update
        {
            int index, x;
            cin>> index>> x;
            index++; // convert 1 based indexing if input is acc to 0 based
            update(index,x);
            arr[index]=x;
        }
        else // read query
        int l,r;
        cin>>l>>r;
        cour<<sum(r)- sum(l-1)<< endl;
    }

}



xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx bit tree compression. inversion count type xxxxxxxxxxxxxxxxx 
// find pairs where num[i] > 2*num[j ] , such that i< j
class Solution {
    public:
    int bit[50000+5]; //5 * 1e5
    int n;
    
    unordered_map<int, int> mp; // for compression
public:
    
    void update( int i, int v)
    {
        while(i<=n)
        {
            bit[i]+=v;
            i+=(i&(-i));
        }
    }
    int sum(int i)
    {
        if(i==0) return 0;
        int ans=0;
        while(i>0)
        {
            ans+= bit[i];
            i-= (i&(-i));
        }
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        
        // using bit
        // using compression by map
        // find sum of l,r
        // update nums[j]
        n = nums.size();
        int bit[n+1]; //bit[0] is invalid in bit tree
        
        vector<int>v;
        for(int i =0; i< n;i++)
            v.push_back(nums[i]);
        sort(v.begin(),v.end());
         for(int i=0;i<n;i++) //give index in bit to every elmn in input array
        {
            mp[v[i]]=i+1;  //+1 bec of 1+ indexing in bit
        }
        long long int ans=0; int pos;
        for( int i=0;i<n;i++)
        {
            long long int val=nums[i];
            long long int val2=2*val;
            long long int idx=upper_bound(v.begin(),v.end(),val2)-v.begin();
            if(idx!=n) // i.e searched no by upperbound exists in v.
            {
               pos=mp[v[idx]]; //finding searced no index wrt to bit
                
                
                    ans+=(sum(n)-sum(pos-1));
            }
            pos=mp[nums[i]]; // update: imp, see
            update(pos,1);
            
        }
        return ans;
    }
};
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
