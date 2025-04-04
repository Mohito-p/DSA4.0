#include<bits/stdc++.h>
using namespace std;
int solve(int val1,int val2,char s){
        if(s=='+') return val1+val2;
        else if(s=='-') return val1-val2;
        else if(s=='*') return val1*val2;
        return val1/val2;
    }
int main(){
    string s;
    cin>>s;
    int n=s.length();
        stack<int>val;
        for(int i=0;i<n;i++){
            if(s[i]>=48 && s[i]<=57){
                val.push(s[i]-48);
            }
            else{
                int val2=val.top();
                val.pop();
                int val1=val.top();
                val.pop();
                int ans=solve(val1,val2,s[i]);
                val.push(ans);
            }
        }
        cout<<val.top()<<endl;
return 0;
}