#include<bits/stdc++.h>
using namespace std;
int priority(char ch){
    if(ch=='+'|| ch=='-')return 1;
     return 2;
}
int solve(int val1,int val2,char ch){
if(ch=='+') return val1+val2;
else if(ch=='-') return val1-val2;
else if(ch=='*') return val1*val2;
return val1/val2;
}
int main(){
    string s;
    cin>>s;
    int n=s.length();
    stack<int>val;
    stack<char>op;
    for(int i=0;i<n;i++){
        //check if s[i] is a digit{0-9}
        if(s[i]>=48 && s[i]<=57){
            val.push(s[i]-48);
        }
        else{
            //s[i]----->operator
            if(op.size()==0 || priority(s[i])>priority(op.top())) op.push(s[i]);
            else{//work karo
              while(op.size()>0 && priority(s[i])<=priority(op.top())){
                char ch=op.top();
                op.pop();
                int val2=val.top();
                val.pop();
                int val1=val.top();
                val.pop();
                int ans= solve(val1,val2,ch);
                val.push(ans);
              }
              op.push(s[i]);
            }
    
        }
    }
    //the operator stack can have val;
    while(op.size()>0){
        char ch=op.top();
                op.pop();
                int val2=val.top();
                val.pop();
                int val1=val.top();
                val.pop();
                int ans= solve(val1,val2,ch);
                val.push(ans);
    }
    cout<<val.top()<<endl;
     return 0;
}