class Solution {
public:
    bool backspaceCompare(string s1, string s2) {
        
stack<char>st1;
stack<char>st2;

    for(int i=0;i<s1.size();i++){
        
        if(st1.size()>0 && s1[i]=='#'){
                st1.pop();
        }
      else if(s1[i]!='#')st1.push(s1[i]);
        
    }

    for(int i=0;i<s2.size();i++){
        
        if(st2.size()>0 && s2[i]=='#'){
                st2.pop();
        }
      else if(s2[i]!='#') st2.push(s2[i]);
        
    }
string f1;
string f2;
while (!st1.empty())
{
    f1+=st1.top();
    st1.pop();
    
}

while (!st2.empty())
{
    f2+=st2.top();
    st2.pop();
    
}

if(f1==f2){
return 1;
}
else return 0;
    }
};