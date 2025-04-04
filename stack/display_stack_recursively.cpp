#include <bits/stdc++.h>
using namespace std;
void displayrec(stack<int>& st){
    if(st.size()==0) return ;
    int x=st.top();
    st.pop();
    displayrec(st);
    cout<<x<<" ";
    st.push(x);
}
int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(89);
    st.push(70);
    displayrec(st);
    return 0;
}