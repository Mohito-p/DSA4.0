#include<bits/stdc++.h>
using namespace std;
string solve(string val1,string val2,char st){
        string s="";
        s+=val1;
        s.push_back(st);
        s+=val2;
      return s;
    }
int main(){
    string s;
    cin>>s;
    int n=s.length();
        stack<string>val;
        for(int i=n-1;i>=0;i--){
            if(s[i]>=48 && s[i]<=57){
                val.push(to_string(s[i]-48));
            }
            else{
                string val1=val.top();
                val.pop();
                string val2=val.top();
                val.pop();
                string ans=solve(val1,val2,s[i]);
                val.push(ans);
            }
        }
        cout<<val.top()<<endl;
return 0;
}