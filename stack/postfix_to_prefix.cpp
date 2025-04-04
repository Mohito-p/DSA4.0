#include<bits/stdc++.h>
using namespace std;
string solve(string val1,string val2,char st){
        string s="";
        s.push_back(st);
        s+=val1;
        s+=val2;
      return s;
    }
int main(){
    string s;
    cin>>s;
    int n=s.length();
        stack<string>val;
        for(int i=0;i<n;i++){
            if(s[i]>=48 && s[i]<=57){
                val.push(to_string(s[i]-48));
            }
            else{
                string val2=val.top();
                val.pop();
                string val1=val.top();
                val.pop();
                string ans=solve(val1,val2,s[i]);
                val.push(ans);
            }
        }
        cout<<val.top()<<endl;
return 0;
}