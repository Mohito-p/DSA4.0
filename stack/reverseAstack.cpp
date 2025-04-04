 #include <bits/stdc++.h>
using namespace std;
void pushAtBottom(stack<int>& st, int val){
    stack<int>temp;
    while(st.size()>0){
        temp.push(st.top());
        st.pop();
    }
    st.push(val);
      while(temp.size()>0){
        st.push(temp.top());
        temp.pop();
    }

}
void reverse_rec(stack<int>& st){
   if(st.size()==1) return ; 
   int x=st.top();
   st.pop();
   reverse_rec(st);
   pushAtBottom(st,x);
}

void print(stack<int>& st){
    stack<int> temp;
    while(st.size()>0){
        temp.push(st.top());
        st.pop();
    }
    while(temp.size()>0){
        cout<<temp.top()<<" ";
        st.push(temp.top());
        temp.pop();
    }
    cout<<endl;
}
int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(89);
    st.push(70);
    reverse_rec(st);
    print(st);
    return 0;
}