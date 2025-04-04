#include <bits/stdc++.h>
using namespace std;
class Stack{
public:
    vector<int>v;
    Stack(){
       
    }
    void push(int val){
        v.push_back(val);
    }
    int size(){
      return v.size();
    }
    void pop(){
         if(v.size()==0){
            cout<<"Stack is Empty";
            return ;
        }
      v.pop_back();
    }
    int top(){
        if(v.size()==0){
            cout<<"Stack is Empty";
            return -1;
        }
        return v[v.size()-1];
    }
};
int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    cout<<st.size()<<endl;
    st.pop();
    cout<<st.size()<<endl;
    cout<<st.top()<<endl;
    st.push(40);
    st.push(50);
    st.push(60);
    return 0;
}