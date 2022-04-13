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
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int k) {
        vector<int> ans;
        int l =0; int r =nums.size()-1;
      ans.push_back(firstocc( nums, l , r, k));
        ans.push_back(lastocc(nums, l , r, k));
        return ans;
        
    }
int firstocc( vector<int>& v,int l , int r, int k)
    {
      int f=-1;
      while(l<=r)
         {
          int mid = l + (r-l)/2;
          if(v[mid] == k ) // can be first occurance but we cont our search to left side
          {  f= mid; r= mid-1; }
          else if (v[mid] > k) r = mid - 1;
          else 
           l = mid+1;
         }
      return f ; // not found
    }

int lastocc(vector<int>& v, int l , int r, int k)
    {
      int lo=-1;
      while(l<=r)
         {
          int mid = l + (r-l)/2;
          if(v[mid] == k ) // can be possible last occurance but we cont our search to righ side
          {  lo= mid; l= mid+1; }
          else if (v[mid] > k) r = mid - 1;
          else 
           l = mid+1;
         }
      return lo ; // not found
    }
    
};
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx count of elmn in sorted array
// find foiorst occur and last occur
//edge case
if(v[0] == v[v.size()-1])  // 5 5 5 5 5 5 5 5 5 5 
  if(v[0]==k) return v.size();
  else return 0;
return lo- f+1;
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  Number of Times a Sorted array is Rotated, unique elements xxxxxxxxxxxxxxxxxxxxxxxxx
// 2 4 6 8 11 12 15 18
// rotate 4 times == // 11 12 15 18 (break)  2 4 6 8 == index of smallest element in given array
// edge case if last elmn >= first elmn then 0 rotation
// concept if mid > = start index elmn (sorted portion ), then the break didnt happen, smallest elmn lies in unsorted array
//and break/ smallest elmn lies left  of mid. else lies on right of mid
// when to return mid? only smallest elmn is smaller then both of its neighbours. 
//also   11 12 15 18    2 2 2 4 6 8 (should return first occurance of 2
//         first half   second half (smallest lies in second half only)                                                 



int findMin(vector<int>& nums)   // works for duplicate values too
{
        int n = nums.size();
        
		//if size of array is one
        if(n==1)
            return nums[0];
        
        //if array is sorted then first element is smallest
        if(nums[0] <=  nums[n-1])
            return nums[0];
        
        int start = 0;
        int end = n-1;
        
        int ans = INT_MAX;
        int ind=-1;
        while(start <= end){
            
            int mid = start  + ( end -  start ) / 2;
			
			//if mid is in first part of array
            if(nums[mid] >= nums[0])  //  2 2 2 2 3  (second half)2 2 doesnt work for this
                start = mid +1;
            
            else // mid is in 2nd half, mid is possible ans
            {
                ans = min(ans , nums[mid]);
                ind=mid;
                end = mid - 1;
                
            }
        }
        //ind = no of times array is rotated
        return ans;
    }
    xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  peak element xxxxxxxxxxxxxxxxxx
    // remember before accessing container to check if it exists or not
    
    class Solution {
public:
     int findPeakElement(vector<int>& nums) {
        int low=0; int high= nums.size()-1;
        
        while(low<=high){
            int mid= low+ (high-low)/2;
            
            if( (mid==0 || nums[mid-1]<nums[mid]) && (mid==nums.size()-1 || nums[mid+1]<nums[mid]) ){
                return mid;
            }
            else if(mid-1>=0 && nums[mid-1]>nums[mid]){ // go to left
                high= mid-1;
            }
            else if(mid+1<=nums.size()-1 && nums[mid+1]>nums[mid]){ // got to right               
                low= mid+1;
            }
        }
        return 0; // useless, just for the sake of returning any integer
    }
};
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  median  of two sorted array xxxxxxxxxxxxxxxxxxxxxxxx
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2, nums1);
        int n1 = nums1.size();
        int n2 = nums2.size(); 
        int low = 0, high = n1;
        
        while(low <= high) {
            int cut1 = (low+high) >> 1;
            int cut2 = (n1 + n2 + 1) / 2 - cut1; 
            
        
            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1]; 
            
            int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int right2 = cut2 == n2 ? INT_MAX : nums2[cut2]; 
            
            
            if(left1 <= right2 && left2 <= right1) {
                if( (n1 + n2) % 2 == 0 ) 
                    return (max(left1, left2) + min(right1, right2)) / 2.0; 
                else 
                    return max(left1, left2); 
            }
            else if(left1 > right2) {
                high = cut1 - 1; 
            }
            else {
                low = cut1 + 1; 
            }
        }
        return 0.0; 
    }
};
