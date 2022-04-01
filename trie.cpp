 #include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

//member functions :
//1. fixedSize_sliding_win(v,k,ptr=""): search in wind of fixed length k.   QUES:FIND MAX IN ALL SUBARRAYS OF SIZE K
//2. VariableSize_sliding_win(v,k,ptr=""): finds max/min wind allowing at max k constraint.   QUES: LONGEST SUBSTRING WITH K UNIQUE CHARACTERS


void fixedSize_sliding_win( V(ll) &arr ,int k=0, V(ll) &ans)  // stores ans in ans vector, ll can be replaced by int 
{
    ll i =0,j=0;          // wind i(left boundary).....j(right boundary)
    deque<int> dq(k);
    while(j < arr.size())
    {
        // add element in dq and maintain dq in decreaing order  
        while(!dq.empty() && dq.back() <= arr[j])
        {
            dq.pop_back();  // if arr[j]> last elm of dq eat it
        }
        dq.PB(arr[j]); // add element to deque
        if (j-i+1<k)  // win size not achieved inc left boundary
        {
            j++; 
        }
        if (j-i+1 == k) // win size achieved, candidate ans
        {
            ans.PB(dq.front());  // The element at the front of the queue is the largest element of
            j++;     //  win right boundary inc by 1 i.e inc size of win, after this win size > k
        }

        if (j-1+1 > k)  // win size > k
        {
            if (arr[j] == dq.front())
                dq.pop_front();
            i++; // inc left boundary i.e dec win size
        }
    }
}

xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void VarSize_sliding_win( string st ,int k=0, V(ll) &ans)  // stores ans in ans vector, ll can be replaced by int 
{
    ll i =0,j=0;          // wind i(left boundary).....j(right boundary)
    deque<int> dq(k);
    unordered_map<char, int> um; // stores frq of all characs
    ans.PB(INT_MIN);
    while(j < arr.size())
    {   
        um[st[j]]++;  // inc freq of char st[j] in um hash table
       
        // check if # of unique characters timm now that is um.size()
        if ( um.size() < k)  // cond < required cond --> inc left boundary
        {
            j++; 
        }
        if (um.size() == k) // condition matched, candidate ans
        {
            ans[0]= max(ans[0], j-i+1);  // storing longest subtring 
            j++;     //  win right boundary inc by 1 i.e inc size of win
        }

        if (um.size() > k)  // win size > k
        {
           um[st[i]]--;  // dec freq of charac i 
           if (um[st]==0)  // if 0 freq then unique characters 
                um.erase(st[i]); // 
            i++; // inc left boundary i.e dec win size
        }
    }
    // ans stored in ans[0]
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

lli power(lli a , lli n)
{   lli result = 1;
    while(n)
	{if(n & 1) result = (result * a) % mod; // odd
        n >>= 1; // now even
		a = (a * a) % mod;
    }return result;
}
lli getHash(string key)  // returns hashing of string.: (key[0]*p^0+ key[1]*p^1+ ..key[n-1]*p^n-1) % mod
{
	lli value = 0;
	lli p = 31;  //prime no used , total charac =26
	lli p_power = 1; // power of prime (initialised by p^0)
 
	for(char ch : key)
	{
		value = (value + (ch - 'a' + 1)*p_power) % mod;
		p_power = (p_power * p) % mod;
	}
 
	return value;
}
void txthash(string input_string ,V(ll) &dp, V(ll)&primes ) //dp stores all suffix hashes, primes stores power of p
{
	lli p = 31;
	lli p_power = 1; primes[0]=1
    dp[0] = (input_string[0] - 'a' + 1); //hash of substring 0-0
    for(int i=1;i<input_string.size();i++)  //all suffex hashes in dp[]
	{   
        char ch = input_string[i];
        p_power = (p_power * p) % mod; primes[i]= (primes[i-1] *p)%mod;
        dp[i] = (dp[i-1] + (ch - 'a' + 1)*p_power) % mod;  // dp[index] = hash value of substr(0,index). index of charac
	}
}

void rabinkarp(srting st, string ptrn, V(ll) &ans)
{   
    V(ll) dp(st.size(),0);
    V(ll)primes(st.size,0);
    lli ptrn_hash= gethash(ptrn);
    txthash(st, dp, primes);
     int i=0, j=ptrn.size()-1; // reached first win size
    int k=ptrn.size();
    while(j < st.size())  // sliding wind, compares hashing of win and  ptrn
    {
         ll substr_hash=0;
        if (i==0)   // finding sub_str
            substr_hash=dp[j];
        else if (i>0)
            substr_hash= (dp[j]- dp[i-1]); // substring hash from txt
        if ( (ptrn_hash *primes[i])%mod  == substr_hash)  // The element at the front of the queue is the largest element of
                    ans.PB(i);   
        i++;// shift win
        j++;         
     }
}


xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  TRIE without Class XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#include<bits/stdc++.h>
using namespace std;

const int SIZE = 26;

struct node{
	bool endOfWord;
	node* ar[SIZE];
};

node* getNode()  // initialises the node
{
	node* n = new node;
	n->endOfWord = false;
	
	for(int i=0;i<SIZE;i++)
	n->ar[i] = NULL;
	
	return n;
}

void insert(node *root , string st)  // root is imp pointer of whole trie
{ // root should be preserved hence copied. passed as pointer
	node *tempRoot = root;
	
	for(int i=0;i<st.size();i++)
	{
		int index = st[i] - 'a';
		
		if(tempRoot->ar[index] == NULL)
		tempRoot->ar[index] = getNode();
		
		tempRoot = tempRoot->ar[index];
	}
	
	tempRoot->endOfWord = true;
}

bool search(node *root , string st)
{
	node *tempRoot = root;
	
	for(int i=0;i<st.size();i++)
	{
		int index = st[i] - 'a';
		
		if(tempRoot->ar[index] == NULL)
		return false;
		
		tempRoot = tempRoot->ar[index];
	}
	
	return tempRoot->endOfWord;
}

int main()
{
	node *root = getNode(); // start of trie DS.
	
	int n , code;
	string st;
	
	while(1)
	{
		cin>>code;
		
		if(code == 1)
		{
			cout<<"Enter string to insert\n";
			cin>>st;
			insert(root , st);
		}
		else
		if(code == 2)
		{
			cout<<"Enter string to search\n";
			cin>>st;
			cout<<search(root , st)<<endl;
		}
		else
		break;
	}
}


xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
struct Node  // for character trie
{ int count; // stores count of words that end below it + at it.
    // count is how many times  this char/node is visited during insertion.
    int eof; //  no of words ending at this char
    Node* arr[26];

    Node()  // constructor
    {for(int i =0; i<26;i++)
        arr[i]=NULL;
        eof=0; count=0;
    }

    bool contains(char ch) // returns true if char exists below it
    { return (arr[ch-'a']!= NULL);  }

    Node* get( char ch) // returns node of the char
    {return arr[ch-'a']; }

    void put(char ch,Node* node) //adds node 
    {arr[ch-'a']= node;}

    void eofplus()
    {eof++;}

    void countplus()
    {count++;}

    void eofminus()
    {eof--;}

    void countminus()
    {count--;}
    
    int eof()
    {return eof;}

    int count()
    {return count;}
}

class Trie()
{
    private: Node* root;

    public:
    Trie() // intialises root
    { root= new Node;}

    void insert(string st)  /** Inserts a word into the trie. */    
    {
        Node* temp = root;
        for(int i =0; i< st.size();i++)
        {   if(!tmp->contains(st[i]))
                tmp->put(st[i], new Node());
            tmp=tmp->get(st[i]);
            tmp->countplus();

        }// reached last char
        tmp->eofplus();
    }

    void delete(string st) // deletes the string, if it exists in the trie, eof-- and all the counts--
    {
        Node* temp=root; 
        vector<Node*> visited[]; // all nodes that are visited
        for(int i =0;i< st. size(); i ++)
        {
             if(!tmp->contains(st[i]));
                return;
            tmp=tmp->get(st[i]);
            visited.PB(tmp);
        }
        if( tmp->eof()>0)
            {   tmp->eofminus();
                for(auto x: visited)
                    x->countminus();
            }
    }

    lli search(string st) // returns count of st in trie
    {   Node* tmp=root;
        
        for(int i=0;i< st.size();i++)
            {
                if(!tmp->contains(st[i]))
                    return 0;
                tmp=tmp->get(st[i]);
            } // reached last char
        return tmp->eof(); // if 0 then doesnt exists else exists with eof freq
    }

    lli prefixmatch(string st)// returns count of words matched with longest prefix of st
    {   
        //modify fnc to return longest word with common prefix of st.
        Node* tmp=root;  lli ans=0;
         for(int i=0;i< st.size();i++)
            {
                if(!tmp->contains(st[i]))
                    return ans=tmp->count();
                tmp=tmp->get(st[i]);
                ans=tmp->count();

            } // reached last char
        return ans;
    }
    
};

xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx leet code trie with class xxxxxxxxxxxxxxxxxxxxxxxxx
#define ll long long
// return sum, of all keuy that matches with prefix, and if key already present update key	
struct node{
 
    ll score=0;
    vector<node*> child;
  
    int eof=0; // if 0 then no word ends here , else tells freq of words
    node(){
      
        child.resize(26,nullptr);
    }
    
};

class MapSum {

public:
    
node* root;    
unordered_map<string, int> um;    
public:
    MapSum() {
        root= new node();
    }
    
    void insert(string key, int val) {
        if(um.find(key)!= um.end()) // key already present, update value
            { 
           // cout<< key<<" present  with val "<<um[key]<<endl;
                int old= um[key];
                um[key]=val; // update map with new value
                val= val-old;
               
         //   cout<< key<<" present chamnged to  "<<um[key]<<endl;
            }
        else // new key adding
            um[key]=val; // put new key
            
        node* temp= root;
        for(int i=0; i< key.length(); i++)
        {
            int index=key[i]-'a';
            if(temp-> child[index]==NULL) //key not present add it
                temp-> child[index]= new node();
            temp=temp-> child[index]; //
            temp->score+=val;
            
        }
         temp-> eof+=1; // inc freq of word
         //cout<< key<<" "<<val<<" "<< temp->score<<endl;
    }
    
    int sum(string prefix) {   // without dfs
        node* temp =root;
        
         for(int i=0; i< prefix.length(); i++)
        {
            int index=prefix[i]-'a';
            if(temp-> child[index]==NULL) // prefix nopt present return 0
                return 0;
            temp=temp-> child[index]; // if present move down 
           
            
        }
         return temp->score; // return sum of all key with given prefix
        
    }
	
	int sum(string prefix)
	{   // with dfs
		val = 0;
		node* temp= root;
		for(char c:  prefix) {
		    if(temp->child[c-'a']==NULL) // prefix not present
			return 0;
		    curr = curr->dict[c-'a']; // else travel down till we reach the prefix
		}
		 return helper(curr); // prefix reached call dfs for all keys below it
		
	
	ll helper(node* temp)
	{
		ll ans=0;
		
		if(temp->isEnd)
		    ans += temp->score;
		for(int i=0;i<26;i++){ // travel to children
		    if(temp->child[i])
			ans+=helper(temp->child[i]);
        	return ans;
	}
		
    }

};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx trie with dfs 


XXXXXXXXXXXXXXXXXXxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx binsry trie xxxxxxxxxxxxxxxx


struct Node1 {  // binary trie
    Node *links[2]; 

    int count; // stores count of words that end below it + at it.
    // count is how many times  this char/node is visited during insertion.
    int eof; //  how many numbers ending at this bit
    

    Node()  // constructor
    {for(int i =0; i<1;i++)
        link[i]=NULL;
        eof=0; count=0;
    }
 
    bool contains(int ind) {
        return (links[ind] != NULL); 
    }
    Node* get(int ind) {
        return links[ind]; 
    }
    void put(int ind, Node* node) {
        links[ind] = node; 
    }

     void eofplus()
    {eof++;}

    void countplus()
    {count++;}

    void eofminus()
    {eof--;}

    void countminus()
    {count--;}
    
    int eof()
    {return eof;}

    int count()
    {return count;}
}; 
class bTrie { // binary trie
    private: Node* root; 
public:
    bTrie() {
        root = new Node(); 
    }
    
    public: 
    void insert(int num) {
        Node* node = root;
        // cout << num << endl; 
        for(int i = 31;i>=0;i--) {
            int bit = (num >> i) & 1; 
            if(!node->contains(bit)) {
                node->put(bit, new Node1()); 
            }
            node = node->get(bit); 
            node->countplus();
        }
        node->eofplus();
    }
    public:
    int findMax(int num) // findin max xor with num
    {
        Node* node = root; 
        int maxNum = 0; 
        for(int i = 31;i>=0;i--) {
            int bit = (num >> i) & 1; 
            if(node->contains(!bit)) { 
                maxNum = maxNum | (1<<i); 
                node = node->get(!bit); 
            }
            else {
                node = node->get(bit); 
            }
        }
        return maxNum; 
    }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) // return max xor btw x^y such that xin arr1 and y in arr2
{
    bTrie trie; 
    for(int i = 0;i<n;i++) {
        trie.insert(arr1[i]); 
    }
    int maxi = 0;
    for(int i = 0;i<m;i++) {
        maxi = max(maxi, trie.findMax(arr2[i])); 
    }
    return maxi; 
}
