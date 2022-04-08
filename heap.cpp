xxxxxxxxxxxxxxxxxxxxxxxx find kth smallest element  in sorted matrix xxxxxxxxxxxxxxxxxxx
// for smallest use max heap
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq; // by default max heap
        int n= matrix.size();
        int m =matrix[0].size();
        for( int i=0;i<n ;i++)
        {
            for(int j=0; j<m; j++)
            {
                pq.push(matrix[i][j]);  // time complexity is O(N logk), where N=n*m
                while(pq.size()>k)  // space complexity is O(k)
                    pq.pop();// the greatest element is popped, hence in pq there are always k smallest element
            }
            //kth smallest element is toopmost of pq
           
        }
      return pq.top();   
    }
};
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
