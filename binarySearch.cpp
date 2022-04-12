xxxxxxxxxxxxxxxxx search target in 2d matrix
 class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size(); // row
        int n = matrix[0].size();  //colms
        
        int i =0;   // row 
        int j = n-1;  //col
        //search starts from here,  and move only in 2 directions left or bottom
        
        while(i < m  && j>=0 ) // bound range of matrix
        {
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j]> target) 
            {
                // ith row becomes useless  
                j--;
            }
            else // less
                i++;
        }
        return false;
        
        
    }
};
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  F 0/1 func
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l =1; 
        int r= 1e9; 
        // r always points to k which is acceptable
        int ans = 1<<30;
        
        while(l<= r)
        {
            int k = l + (r-l)/2;
            if(pass(piles,k,h)) // possible to eat all bananas if rate is k and h hrs time
                { 
                ans = min(ans, k);
                    r= k-1; 
                }
            
            else // not possible to eat at k rate have to increase  the tare
                l = k+1;
        }
        return ans;
       
    }
    bool pass(vector<int>& nums,int k, int h){
        int NumberOfHours=0;
        for(int i=0;i<nums.size();i++){
            NumberOfHours+=(nums[i]%k==0) ? nums[i]/k : (nums[i]/k)+1;
        }
        return NumberOfHours <= h;
    }
};
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx search in reverse sorted array xxxxxxxxxxxxxxxxxxxx
int l=0;
int r= v.size()-1;
int key; // tosearch
// 29  18 15 14 11  8 6 4 3 1 0
while(l<=r)
{
 int mid = l + (r-L)/2;
 if(v[mid] == key ) return mid; 
 else if (v[mid] > target) l = mid+1;
 else 
  r = mid - 1;
}
return -1 ; // not found
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  First and Last occurrence of an Element xxxxxxxxxxxxxxxx
// using stl 
int l = lower_bound(v.begin(), v.end(), key) - v.begin();   // index at which elmn isnt less than target
int r = upper_bound(v.begin(), v.end(), key-1) - v.begin(); // strictly greater than target
if(l ==n) // not found
  return -1;
if( v[l] != key) // target not found
  return -1; 
else // first occurance
int  f= l;
// if we reach till here then , key is present
if(r == n ) break; // not possible

lastocc=r;
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int firstocc( int l , int r, int k)
{
  int f=-1;
  while(l<=r)
     {
      int mid = l + (r-L)/2;
      if(v[mid] == k ) // can be first occurance but we cont our search to left side
      {  f= mid; r= mid-1; }
      else if (v[mid] > k) l = mid+1;
      else 
       r = mid - 1;
     }
  return f ; // not found
}

int lastocc( int l , int r, int k)
{
  int lo=-1;
  while(l<=r)
     {
      int mid = l + (r-L)/2;
      if(v[mid] == k ) // can be possible last occurance but we cont our search to righ side
      {  lo= mid; l= mid-1; }
      else if (v[mid] > k) l = mid+1;
      else 
       r = mid - 1;
     }
  return lo ; // not found
}
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx



