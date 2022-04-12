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
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
