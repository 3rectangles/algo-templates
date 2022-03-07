
xxxxxxxxxxxxxxxxxxxxxx lazy  segment tree with nodes  xxxxxxxxxxx
// build ,  point update, query , nodes in segment tree

const int n= 2e5;
int arr[n+1]; // input array


struct node{
    int a;
};
int seg(4*n +5); // seg array 
int lazy(4*n +5); // lazy nodes 

void build(int index, int low, int high) 
{
    if(low==high)// size =1
        {seg[index]= {arr[low]};
        return;
        }
     int mid = (low + high) >> 1; 
	build(2*ind, low, mid, arr); 
	build(2*ind+1, mid+1, high, arr); 
	seg[ind] = seg[2*ind] + seg[2*ind+1];
}

void update(int index, int low, int high, int key, int value) 
{   
    // update the previous remaining updates 
	// and propogate downwards 
    //  go down till we reached complete overlap range --> update this range corrsponding seg cell
    if(lazy[ind] != 0) //updates remaining for this range 
    {
		seg[ind] += (high - low + 1) * lazy[ind];  // range sum query
		if(low != high) //if parent has children propogate the info 
        {
			lazy[2*ind] += lazy[ind]; 
			lazy[2*ind+1] += lazy[ind]; 
		}
        lazy[ind] = 0; // update done fot this node, hence lazy node turnded to 0
	}
    
    if(high < l or r < low) // no overlap do nothing, this isnt the range to update
			return; 
    if(low>=l && high <= r) //  complete overlap: l low high r 
    {
        seg[ind] += (high - low + 1) * val; // update the range sum
        // if not leaf node, it will have childrens
        if(low != high) {
            lazy[2*ind] += val; 
            lazy[2*ind+1] += val; 
        }
        return; 
	}

    // last case has to be no overlap case
    int mid = (low + high) >> 1; 
    update(2*ind, low, mid, l, r, val);
    update(2*ind+1, mid+1, high, l, r, val); 
    seg[ind] = seg[2*ind] + seg[2*ind+1]; 
     
}

int query(int index , int low,int high, int l, int r)
{ //perform pending and set lazy=0 ,then if children present propogate 

    if(lazy[ind] != 0)
     {
        seg[ind] += (high - low + 1) * lazy[ind]; 
        if(low != high) // not a leaf node, i.e have children
        {
            lazy[2*ind] += lazy[ind]; 
            lazy[2*ind+1] += lazy[ind]; 
        }
        lazy[ind] = 0; 
    }
    if(high < l or r < low)  // no overlap
		return 0 ; // for range sum. for range min query return INT_MAX

    if( low >=l &&  high <= r) // complete overlap
        return seg[index];
    
	//else now: partial overlap

    int mid = (low + high) >> 1; 
    int left = query(2*ind, low, mid, l, r);
    int right = query(2*ind+1, mid+1, high, l, r);
    return left + right; 
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
    while(q--) {
		int type;
		cin >> type; 
		if(type==1) {
			int l, r;
			cin >> l >> r; // 0 based indexing
			cout << st.query(0,0,n-1,l,r) << endl; 
		}
		else {
			int l, r, val;
			cin >> l >> r >> val; 
			st.update(0,0,n-1,l,r,val);
		}    
    return 0;
}

