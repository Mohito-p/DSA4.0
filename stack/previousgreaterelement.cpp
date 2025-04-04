#include <bits/stdc++.h>
using namespace std;
vector<int> previousgreater(vector<int>& arr){
    int n=arr.size();
    vector<int>pge(n);
    stack<int>st;
    pge[0]=-1;
    st.push(arr[0]);
    for(int i=1;i<=n-1;i++){
    while(st.size()>0&&st.top()<=arr[i]){
        st.pop();
    }
    if(st.size()==0) pge[i]=-1;
    else pge[i]=st.top();
    st.push(arr[i]);
    }
    return pge;
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int>pge=previousgreater(nums);
    for(int i=0;i<n;i++){
        cout<<pge[i]<<" ";
    }
    return 0;
}