#include<bits/stdc++.h>
using namespace std;
int priority(char ch){
    if(ch=='+'|| ch=='-')return 1;
     return 2;
}
string solve(string val1,string val2,char ch){
    string s="";
    s+=val1;
    s+=val2;
    s.push_back(ch);
    return s;
}
int main(){
    string s;
    cin>>s;
    int n=s.length();
    stack<string>val;
    stack<char>op;
    for(int i=0;i<n;i++){
        //check if s[i] is a digit{0-9}
        if(s[i]>=48 && s[i]<=57){
            val.push(to_string(s[i]-48));
        }
        
        else{
            //s[i]----->operator
            if(op.size()==0)op.push(s[i]);
            else if(s[i]=='(')op.push(s[i]);
            else if(op.top()=='(') op.push(s[i]);
            else if(s[i]==')'){
                while(op.top()!='('){
                char ch=op.top();
                op.pop();
                string val2=val.top();
                val.pop();
                string val1=val.top();
                val.pop();
                string ans= solve(val1,val2,ch);
                val.push(ans);
                }
                op.pop();
            }
            else if(priority(s[i])>priority(op.top())) op.push(s[i]);
            else{//work karo
              while(op.size()>0 && priority(s[i])<=priority(op.top())){
                char ch=op.top();
                op.pop();
                string val2=val.top();
                val.pop();
                string val1=val.top();
                val.pop();
                string ans= solve(val1,val2,ch);
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
                string val2=val.top();
                val.pop();
                string val1=val.top();
                val.pop();
                string ans= solve(val1,val2,ch);
                val.push(ans);
    }
    cout<<val.top()<<endl;
    return 0;
}