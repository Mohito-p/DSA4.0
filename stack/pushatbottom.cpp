#include<bits/stdc++.h>
using namespace std;

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
void pushAtBottom_rec(stack<int>& st, int val){
    if(st.size()==0){
        st.push(val); 
        return;
    } 
    int x=st.top();
    st.pop();
    pushAtBottom_rec(st,val);
     st.push(x);
}
void push_any_index(stack<int>& st,int index,int val){
    stack<int>temp;
    while(st.size()>index-1){
        temp.push(st.top());
        st.pop();
    }
    st.push(val);
      while(temp.size()>0){
        st.push(temp.top());
        temp.pop();
    }
}

int main(){
    stack <int> st;
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(8);
    st.push(9);
    st.push(1);
    print(st);
    pushAtBottom(st,80);
    print(st);
    push_any_index(st,2,11);
    print(st);
     pushAtBottom_rec(st,77);
    print(st);
    
    
    
    return 0;}