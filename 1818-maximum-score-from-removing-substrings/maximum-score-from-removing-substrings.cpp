class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n=s.size();
        vector<int>v(n,0);

        int seena=0;
        stack<int>sa;
        int total=0;


    if(x>y){

        for(int i=0;i<n;i++){
            if(s[i]=='a'&& v[i]!=1){
                seena++;
                sa.push(i);
            }
            else if(s[i]=='b'&&seena>0&& v[i]!=1){
                total+=x;
                seena--;
                int t=sa.top();
                sa.pop();
                v[t]=1;
                v[i]=1;
            }
            else if(v[i]!=1){
                seena=0;
                sa = stack<int>();
            }

        }
        sa=stack<int>();
        seena=0;


        for(int i=0;i<n;i++){
            if(s[i]=='b'&& v[i]!=1){
                seena++;
                sa.push(i);
            }
            else if(s[i]=='a'&&seena>0&& v[i]!=1){
                total+=y;
                seena--;
                int t=sa.top();
                sa.pop();
                v[t]=1;
                v[i]=1;
            }
            else if (v[i]!=1){
                seena=0;
                sa = stack<int>();
            }

        }


    }
    else{
                for(int i=0;i<n;i++){
            if(s[i]=='b'&& v[i]!=1){
                seena++;
                sa.push(i);
            }
            else if(s[i]=='a'&&seena>0&& v[i]!=1){
                total+=y;
                seena--;
                int t=sa.top();
                sa.pop();
                v[t]=1;
                v[i]=1;
            }
            else if (v[i]!=1){
                seena=0;
                sa = stack<int>();
            }


        }
                sa=stack<int>();
        seena=0;

          for(int i=0;i<n;i++){
            if(s[i]=='a'&& v[i]!=1){
                seena++;
                sa.push(i);
            }
            else if(s[i]=='b'&&seena>0&& v[i]!=1){
                total+=x;
                seena--;
                int t=sa.top();
                sa.pop();
                v[t]=1;
                v[i]=1;
            }
            else if(v[i]!=1){
                seena=0;
                sa = stack<int>();
            }

        }
        
    }

        return total;



        
        
    }
};