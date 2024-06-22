class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& g, int k) {
        int n=customers.size();
        vector<int>pre(n,0);
        if(g[0]==1)pre[0]=customers[0];
    cout<<pre[0]<<" ";
        for(int i=1;i<n;i++){
            if(g[i]==1){//cout<<i<<endl;
                pre[i]=pre[i-1]+customers[i];
            }   
            else pre[i]=pre[i-1];
            cout<<pre[i]<<" ";
        }cout<<endl;

        int sum=0;
        int maxi=pre[k-1];
        int ii=0;
        int jj=k-1;
        if(k==0)jj=0;
        for(int i=k;i<n;i++){
            if(k==0)break;
            if(pre[i]-pre[i-k]>maxi){
                maxi=pre[i]-pre[i-k];
                cout<<maxi<<endl;
                ii=i-k+1;
                jj=i;
            }
        }
        cout<<ii <<jj;

        int total=0;
        for(int i=0;i<n;i++){
            if(i>=ii && i<=jj && g[i]==1)total+=customers[i];
            else if(g[i]==0) total+=customers[i];
        }




         
    return total;
    }
};