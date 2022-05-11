xxxxxxxxxxxxxxxx GRID DP tabulation : no of max path value xxxxxxxxxxxxxxxxxxxxx

// find pahts from src to target, some are blocked, return max value paths and no of paths possible paths which have max value

class Solution  // moving from source to end or end to source doesnt matter. 
{
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int mod = 1000000007, n = board.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1)); // stores max value path 
        vector<vector<int>> cnt(n+1,vector<int>(n+1));  // store no of paths from this cell to tarhet cell
        board[n-1][n-1] = board[0][0] = '0'; // board[n-1][n-1] is start cell and board[0][0] is source. marked as S and E, initialise them with 0 value
        cnt[n-1][n-1] = 1; // one path to move from target to target. same as no of paths from src to target using topo sort. only start cell has 1 value,
        for(int i=n-1;i>=0;--i){
            for(int j=n-1;j>=0;--j)
            {
                if(board[i][j] != 'X') // if this cell is restricted the max value and cnt of paths from this cell remains 0
                {
                    int m = max({dp[i+1][j],dp[i][j+1],dp[i+1][j+1]}); // find the max value from three options, down, right, and down right
                    dp[i][j] = (board[i][j]-'0')+m; // add the current cells value to max of three path choices
                    if(dp[i+1][j] == m) // check how many paths from the options contains max value. and increment the no of possible paths
                        cnt[i][j] = (cnt[i][j]+cnt[i+1][j]) % mod; 
                    if(dp[i][j+1] == m)
                        cnt[i][j] = (cnt[i][j]+cnt[i][j+1]) % mod; // dont worry if any of choice cell is 'X' its cnt is 0. hence it doesnt contribut to ans
                    if(dp[i+1][j+1] == m)
                        cnt[i][j] = (cnt[i][j]+cnt[i+1][j+1]) % mod;
                }
            }
        }
        return {cnt[0][0]?dp[0][0]:0,cnt[0][0]}; // if the cnt of src cell isnt 0 return, max  value and path , else return 0 as max value path 
    }
};
 xxxxxxxxxxxxxxxx GRID DP Memorization xxxxxxxxxxxxxxxxxxxxx

class Solution {
public:
    int dir[3][2]={{0,-1},{-1,0},{-1,-1}};
    int mod=1000000007;
    int n;
    pair<int,int> dp[101][101];
    pair<int,int> max_sum(int i,int j,vector<string>& board)
    {
        if(i<0 || j<0 || board[i][j]=='X')  // out of bound or cant reach x marked cell, hence no way from here. hence return -inf
            return {INT_MIN,0}; // no path from such cells to end cell( board[0][0])
        if(i==0 && j==0)  // reached target cell. path from this cell to itself is 1. and max path value is 0
            return {0,1};
        if(dp[i][j].first!=-1) // caching
            return dp[i][j];
        int val=board[i][j]=='S'?0:board[i][j]-'0'; // the value of current cell
        
        int res=INT_MIN,count=0; // to choose best path of three choices from current cell
        
        for(int k=0;k<3;k++) // three directions to move from here. left, up, or upper left
        {
            pair<int,int> p=max_sum(i+dir[k][0],j+dir[k][1],board); 
            if(p.first+val>res) // if this path is better than out prev path of 3 choices
            {
                res=p.first+val;
                count=p.second; // if this is the best till now then copy the count
            }
            else if(p.first+val==res)  // if this path's value is same as max value of other choices, then we got more paths choices 
                count=(count+p.second)%mod;
        }
        return dp[i][j]={res,count};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) 
    {
        n=board.size();
        for(int i=0;i<=100;i++)
            for(int j=0;j<=100;j++)
                dp[i][j]={-1,0}; // initially max value for every cell -1 and 0 path to reach the target cell
        pair<int,int> p=max_sum(n-1,n-1,board); // start cell
        int sum=p.first;
        int paths=p.second;
        if(sum<0) // if max value is less than 0 that means no path to reach the target cell hence 0 path 
            return {0,0};
        return {sum,paths}; // else return what we got
    }
};

xxxxxxxxxxxxxxxxxxxxx cherry pick 2 , xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// two robots moving down simultaneously, from each cell can pick no of cherries, if both robots are in same cell, only one robot can pick tthe cherry. 
//return nmax cherry robots can ghather
class Solution {
public:
int dp[71][71][71]; // ror col1 col2 : at every each robot moves down, hence row is always constant. even if robots move in opposite direct still r1+c1= r2+c2

int func(vector<vector<int>>&grid,int r1,int c1,int c2){
    int r2=r1;
    if(r1>=grid.size() || r2>=grid.size() || c1<0 || c2<0 || c1>=grid[0].size() || c2>=grid[0].size()){ // out of bound
        return INT_MIN;
    }
    
    if(dp[r1][c1][c2]!=-1){ // caching
        return dp[r1][c1][c2];
    }
    
    if(r1==grid.size()-1){ /// reached the last row. if both robots are in same cell. cherry can be added only once
        if(c1==c2){
            return grid[r1][c1];
        }
        else{ // both are in diff cells hance add cherries from both the cells
            return grid[r1][c1]+grid[r1][c2];
        }
        
    }
    
    int cherry=0;
    if(c1==c2){ //induction step, if both robots are in same cell, cherries are added once else add from both cells
        cherry+=grid[r1][c1];
    }
else{
        cherry+=grid[r1][c1];
        cherry+=grid[r1][c2];
    }
    
    int maxcherry=0;
    for(int i=-1;i<=1;i++){ // recursive step
        
        for(int j=-1;j<=1;j++){ // all possible states of both robots, chose the best one
            maxcherry=max(maxcherry,func(grid,r1+1,c1+i,c2+j));
        }
    }
    
    return dp[r1][c1][c2]=cherry+maxcherry; // reutn future best state + current state value
    
}

int cherryPickup(vector<vector<int>>& grid) {
    
    int m=grid.size();
    int n=grid[0].size();
    
    memset(dp,-1,sizeof(dp));
    
    int ans=func(grid,0,0,n-1); // the intial pos of robots, top left and top right. [0][0] and [0][n-1]
    return ans;
    
}
};
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
