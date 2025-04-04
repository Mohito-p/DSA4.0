#include<bits/stdc++.h>
using namespace std;
vector<int> nextgreater(vector<int>& arr){
    int n=arr.size();
    stack<int>st;
    vector<int>nge(n);
    nge[n-1]=-1;
    st.push(arr[n-1]);
    for(int i=n-2;i>=0;i--){
        while(st.size()>0&&st.top()<=arr[i]){
            st.pop();
        }
        if(st.size()==0) nge[i]=-1;
        else nge[i]=st.top();
        st.push(arr[i]);
    }
return nge;
};
int main(){
    int n;
    cin>>n;
    vector<int>num(n);
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    vector<int>nge=nextgreater(num);
    for(int i=0;i<n;i++){
        cout<<nge[i]<<" ";
    }
    cout<<endl;
    return 0;
}