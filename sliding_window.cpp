
xxxxxxxxxxxxx count of subarrays whose product < k
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int l=0; int r=0; int p=1; int res=0;
        while(r < nums.size())  // first adjust the window to requirement and then add the candidate
        {
            p*= nums[r];  //add current r to the window
           
           
                while(p>=k && l<=r ) // decrease window from left if conditions not met,
                { // shift from left, till l<=r, (imp, if k=0 then  loop wont end
                    p=p/nums[l];
                    l++;
                }
           if(p<k) // candidate check. no n eed for if statement, win already adjusted
                res+= r-l+1; 
            r++; //extend win to right
            
        }
        return res;
        
    }
};
