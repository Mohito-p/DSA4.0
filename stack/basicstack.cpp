#include<bits/stdc++.h>
using namespace std;
int main(){
    stack <int> st;
    cout<<st.size()<<endl;
    st.push(3);
    st.push(4);
    cout<<st.size()<<endl;
    st.push(5);
    //st.pop();
    cout<<st.size()<<endl;
    cout<<st.top()<<endl;
    st.push(8);
    st.push(9);
    st.push(1);
    // this making the stack empty
    //while(st.size()>0){
      //  cout<<st.top()<<" ";
        //st.pop();
    //}
    // we will use extra stack
    stack <int> temp;
     while(st.size()>0){
        cout<<st.top()<<" ";
        int x=st.top();
        st.pop();
        temp.push(x);
     }
     //puuting back in the stack
     while(temp.size()>0){
        int x=temp.top();
        temp.pop();
        st.push(x);
     }
     cout<<endl<<st.top();
    return 0;
}