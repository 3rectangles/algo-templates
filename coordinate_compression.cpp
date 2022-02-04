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
/*member functions :

1. fixedSize_sliding_win(v,k,ptr=""): search in wind of fixed length k.   QUES:FIND MAX IN ALL SUBARRAYS OF SIZE K

used for segment tree queries. q1 point update. q2 range query. 
q1: 1 pos val
q2: 2 pos pos

 desc: to read all positions >=10^9 and map them to 10^5
*/

cont q=1e5+10; // no of queries
ll t[q];  //type of query. t[1]= query type of 1st query
ll x[q];// x[i]: pos in ith query and y[i], y[i] is uneffected bec not send in map
ll y[q];  // if q1 then x[i] stores pos and y[i] doesnt matter.

map<int,int> mp; // to sort pos can have duplicate values

compression()
{
    for(int i =1; i<=q; i++)  // insert in map
    {
        scanf("%d %d %d", &t+i, &x+i,&y+i); // store valus of ith query in ith index of t,x,y arrays

        if(t[i]==1)// q1. x[i] stores pos, y[i]= value 
            mp[t[i]]; //inserted in map
        else if (t[i]==2) // q2, x[i] and y[i] both stores pos
            {
                mp[x[i]]; mp[y[i]];
            }// mp sorts the keys

    }

        int ind=0;
        //compression index
        //note: imp to use &it else pair in maps wont get updates else it will be copy only
        for(auto &it : mp) // give indices to pos that is mapping 
        {
            // {it.first:it.second} stored in map
            it.second=ind; ind++;
        }
        for (int i =1; i<=q;i++)  //change the pos in query to mapped pos
        {
            if(t[i]==1)
                x[i]= mp[x[i]];
                //y[i] remains same as inputted query
            else if (t[i]==2)
                {
                    x[i]=mp[xi];
                    y[i]=mp[y[i]];
                }
        }
} 
int main()
{
    cin>>q;// read no of queries
    compression();
    i=1;
    while(i<t.size())
    {
        if(t[i]==1)
        { // 1 a b in ith quert. y[i] uneffeted
            // output ans of query
        }

        else if(t[i]==2)
        {

        }
    }

}