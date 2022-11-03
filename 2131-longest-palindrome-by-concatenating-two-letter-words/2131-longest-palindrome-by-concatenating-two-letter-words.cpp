class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        //map to count frequency of strings
        map<string,int> mp;
        for(string x:words){
            mp[x]++;
        }
        
        /* we store strings which is palindrome itself i.e reverse is same to particular                string */ 
        vector<string> v;
        int ans=0,twice=0;
        
        
        for(auto itr=mp.begin(); itr!=mp.end(); itr++){
            string st = itr->first,rev;
            rev=string(st.rbegin(),st.rend());
            
            // if string's reverse is same as string  
            if(st==rev){
                v.push_back(st);
            }else if(mp.find(rev)!=mp.end() && itr->second!=-1){
                // if reverse is present in map and it is not same as string
                
                /* it's contibution in length is min of revers string's frequency and                          frequeny of string multiply by 4 */
                ans+=min(mp[rev],itr->second)*4;
                
                // for preventing to check for reverse of string
                mp[rev]=-1;
            }
        }
        // maximum odd frequency in  palindrome strings
        int mxodd=-1;
        
        //calculation of mxodd
        for(auto x:mp){
            //cout<<x.first<<" ";
            string st=x.first;
            string rev=string(st.rbegin(),st.rend());
            
            if(x.second%2!=0 && x.first==rev){
                mxodd=max(mxodd,x.second);
            }
            //cout<<x.second<<"\n";
        }
        
        // traversing in vector of palindrome strings
        for(auto x:v){
            // if fequency is even
            if(mp[x]%2==0){
                ans+=mp[x]*2;
            }
            else{
                //calculation of mxodd only 1 time
                if(mp[x]==mxodd && twice!=1){
                    ans+=mxodd*2;
                    twice=1;
                }else{
                    // if mxodd in present many time or frequency is odd 
                    ans+=(mp[x]-1)*2;
                }
            }
        }
        
        return ans;
    }
};