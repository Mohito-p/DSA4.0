#include <bits/stdc++.h>
using namespace std;
class Stack{
public:
    int arr[5];
    int idx;
    Stack(){
        idx=-1;
    }
    void push(int val){
        if(idx==sizeof(arr)/sizeof(arr[0])){
            cout<<"stack is FULL";
        }
        arr[++idx]=val;
    }
    int size(){
      return idx+1;
    }
    void pop(){
      idx--;
    }
    int top(){
        if(idx==-1){
            cout<<"Stack is Empty";
            return -1;
        }
        return arr[idx];
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