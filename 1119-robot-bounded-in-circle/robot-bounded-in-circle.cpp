class Solution {
public:
    bool isRobotBounded(string s) {
        s=(s+s+s+s);
        int n=s.size();
        int dir =0;
        int x=0;
        int y=0;
        for(int i=0;i<n;i++){
            if(s[i]=='L'){
                dir=((dir+1)%4);

            }
            else if (s[i]=='R'){
                dir=((dir+3)%4);
            }
            else{
                    {
                        if(dir==0)y++;
                        if(dir==1)x++;
                        if(dir==2)y--;
                        if(dir==3)x--;
                        }
                    
            }
            
            // cout<<x<<" "<<y<<endl;
        }


        return(x==0&&y==0);
    }
};