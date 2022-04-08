xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx nearest smaller to right/ left
// find nect smaller element to right. 
// for each index of arr return index of next smaller element to its right

 stack<pair<int,int>>sr;

    stack<pair<int,int>>sl;
    vector<int>left;
    vector<int>right;
 void smallerleft(vector<int>& h)
    {
        sl.push({-1,-1}); // initial value . stack wil never be empty
        for(int i =0 ; i< h.size(); i++)
        {
            while( sl.top().first >= h[i]) 
                sl.pop();
            left.push_back(sl.top().second);
            sl.push({h[i],i});  // using pair is imp to return index of nearest smaller element to left
        }
    }
     void smallerright(vector<int>& h)
    {
        int n = h.size();
        sr.push({-1,-1}); // initial value . stack will never be empty
        for(int i =n-1 ; i >= 0; i--)
        {
            while( sr.top().first >= h[i]) 
                sr.pop();
            right.push_back(sr.top().second); // didnt use right[i]=sr.top().second; hence will reverse sr at last
            sr.push({h[i],i});
            
        }
         reverse(right.begin(),right.end()); 
    }
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
