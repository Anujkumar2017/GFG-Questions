class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> mp;
        for(string x:words){
            mp[x]++;
        }
        
        vector<string> v;
        int ans=0,twice=0;
        
        for(auto itr=mp.begin(); itr!=mp.end(); itr++){
            string st = itr->first,rev;
            rev=string(st.rbegin(),st.rend());
            
            //cout<<mp[rev]<<" ";
            if(st==rev){
                v.push_back(st);
                //itr->second=1;
            }else if(mp.find(rev)!=mp.end() && itr->second!=-1){
                ans+=min(mp[rev],itr->second)*4;
                mp[rev]=-1;
            }
            //cout<<ans<<"\n";
        }
        int mxodd=-1;
        
        for(auto x:mp){
            cout<<x.first<<" ";
            string st=x.first;
            string rev=string(st.rbegin(),st.rend());
            
            if(x.second%2!=0 && x.first==rev){
                mxodd=max(mxodd,x.second);
            }
            cout<<x.second<<"\n";
        }
        
        for(auto x:v){
            if(mp[x]%2==0){
                ans+=mp[x]*2;
            }
            else{
                if(mp[x]==mxodd && twice!=1){
                    ans+=mxodd*2;
                    twice=1;
                }else{
                    ans+=(mp[x]-1)*2;
                }
            }
        }
        
        // if(v.size()==1)
        //     ans+=2;
        
        return ans;
    }
};