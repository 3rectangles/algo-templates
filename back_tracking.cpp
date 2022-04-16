xxxxxxxxxxxxxx all permutaion such that alphabets can be in lowerc ase / upper case
  class Solution {
    public:
      string a="";
    int n =0;
     vector<string> fa;
    //vector<int>a;
public:
    vector<string> letterCasePermutation(string s) {
        
         n = s.size();        
        // a.resize(n,0);
        dfs(s,0);
        return fa;
    }
    
    void dfs(string &s, int i )
    {
        if(a.size() >= s.size())
        {
            fa.push_back(a);
            return;
        } 
       // cout<<n<<endl;
        if(s[i] >= '0' && s[i] <='9')// charac
        {
            a=a+s[i];
            dfs(s,i+1);
            a.erase(i,1); //delte it for backtracking
        }    
        else // letter
        {
            // make it to lower case
            char ch= s[i];
            if(ch >= 'A' && ch <='Z') // in upper case 
                ch= ch-'A' +'a';
            a=a+ch;
            dfs(s,i+1);
            a.erase(i,1);
            // make it to upper case
             if(ch >= 'a' && ch <='z') // in upper case 
                ch= ch-'a' +'A';
            a=a+ch;
            dfs(s,i+1);
            a.erase(i,1);
        
        }
       
    } //end of dfs
    
};
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
