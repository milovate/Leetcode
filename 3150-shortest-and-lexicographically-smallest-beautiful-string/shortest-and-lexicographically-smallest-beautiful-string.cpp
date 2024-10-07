class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        
        int n=s.size();
        int j=0;
        int i=0;
        int cnt=0;

        int ans=INT_MAX;
        string res="";
        while(i<=j&&j<n){
            
            if(s[j]=='1'){
                    cnt++;
                    }       

            while(i<=j && j<n && cnt==k){

                   string s1=s.substr(i,j-i+1);
                    if(res.size()==0 || s1.size()<res.size())
                        res=s1;
                    else if(s1.size()==res.size())
                        res=min(res,s1);


                if(s[i]=='1'){
                    cnt--;
                }

                i++;
            }
            
            j++;
        }

        return res;
    }
};