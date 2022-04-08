
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
            while(j <=i && s>= target) // decrease the win size till we can. note: imp that j<=i (equal to) for wins of size 1
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
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  longest window with no repeating characters xxxxxxxxxxxxxxxxxxxxxxxx
 class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> um; // to count freq of each charact. um.size() represents no of uniques characters in um
        int r=0;
        int l=0;
        int ans=0;
        
        while(r < s.length())
        {
            um[s[r]]+=1; // add the extended window calculations
          //  cout<<s[r] <<" "<< um[s[r]]<<endl;
            while(l <= r && um.size()< r-l+1) //  duplicate in win, decrease wind from left 
            {  // for abb r-l+1 =3 bugt um.size()=2 i.e window have duplicate characters
                um[s[l]]-=1;
                if(um[s[l]]==0) um.erase(s[l]);
                l++;
            }
            
            if(um.size() == r-l+1) // all unique characters candidate
                ans= max(ans, r-l+1);
                
            r++; // increase window
                
        }
        return ans;
        
    }
};
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  fixed window size xxxxxxxxxxxxxxxxxxxxxxxxx
// return the max element for each win of size k: uses deque
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        int l=0,r=0;
        if(nums.size()<k) return ans;  // empty vector
        
        while(r<nums.size())
        {
            // add r in dequ
            while( !dq.empty() && nums[r]>dq.back()){
               // cout<<"r= "<<r<<" "<< dq.front()<<" ";
                dq.pop_back();
            }
                
            dq.push_back(nums[r]);
            if( r-l +1 < k) // window size not achieved
                r++;
            else if(k==r-l+1) // window size achieved
            {
                ans.push_back(dq.front());
                // slide the window
                if(!dq.empty() && dq.front() ==nums[l])
                    dq.pop_front();
                l++;r++;
            }
        }
        return ans;
    }
};
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  all windows in string s1 which are permutaion of string s2
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1.length() > s2.length()) return false;
               vector<int>count1(26,0), count2(26,0);
           int i;
           
          vector<int> ans;
        for(i = 0; i < s1.size(); i++) {
            // compute the frequency of each char for the first window
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }
         if(count1 == count2)  ans.push_back(0);
        
           
        cout<<"ok"<<endl;
         int start = 0, end = s1.length();
         int k= 0; // window size
        
        while(end < s2.size()){
        //remove char at 'start' index and add char at 'end' index
            count2[s2[start] - 'a']-=1; 
            l++; // new wind starting
            count2[s2[end] - 'a']+=1;
            
          
            if(count1 == count2) ans.PB( start); // adds O(26) can improve by using freq of freq
            end++; //win shifted to take new character
        }
        if(ans.size()==0) 
        return false;
        else 
        return ans;
        
    }
};

xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx max element in each wind of size k , dequeue xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        int l=0,r=0;
        if(nums.size()<k) return ans;  // empty vector
        
        while(r<nums.size())
        {
            // add r in dequ
            while( !dq.empty() && nums[r]>dq.back()){
               // cout<<"r= "<<r<<" "<< dq.front()<<" ";
                dq.pop_back();
            }
                
            dq.push_back(nums[r]);
            if( r-l +1 < k) // window size not achieved
                r++;
            else if(k==r-l+1) // window size achieved
            {
                ans.push_back(dq.front());
                // slide the window
                if(!dq.empty() && dq.front() ==nums[l])
                    dq.pop_front();
                l++;r++;
            }
        }
        return ans;
    }
};
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

