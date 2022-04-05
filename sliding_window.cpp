
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
xxxxxxx min len windown whose sum >= k, return 0 if no such subarray xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int mlen= 200000;
        int i=0; int j=0;
        int s=0;
        while(i< nums.size())
        {
            s+=nums[i]; // calculations
            while(j <=i && s>= target) // decrease the win size till we can
            {
                if( i-j+1 < mlen ) mlen=i-j+1;
                s=s-nums[j]; //remove left elm from calculation
                j++;
            }
            // candidate ans already done while decreasing j
            i++; // increase win size
        }
        if(mlen== 200000) mlen=0;  // if no such window found retunr 0
        return mlen;
    }
};
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx max elmns in window such that at max 2 different types of elmns are possible
// leetcode fruit basket 
class Solution {
public:
    int totalFruit(vector<int>& nums) {
        
         int mlen= 0;
        unordered_map<int,int> um ;
        int i=0; int j=0;
        int s=0;
        while(i< nums.size())
        {
            um[nums[i]]+=1; //calculations
            while(j <=i && um.size()>2 ) // decrease the win size till constraint
            {
                um[nums[j]]-=1;
                if(um[nums[j]]==0) um.erase(nums[j]);  //remove left elm from calculation
                j++;
            }
            if(um.size()<=2) // check for candidate
            { 
                int ans=0;
               for(auto it:um)
                   ans+= it.second;
                mlen=max(mlen,ans);
            }
          
            i++; // increase win size
        }
        //if(mlen== 200000) mlen=0;  // if no such window found retunr 0
        return mlen;
        
    }
};
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx