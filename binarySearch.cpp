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
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
