#include<bits/stdc++.h>
using namespace std;
vector<int>stock_span(vector<int>nums){
    int n=nums.size();
    vector<int>pgi(n);
    stack<int>st;
    pgi[0]=-1;
    st.push(0);
    for(int i=1;i<n;i++){
        while(st.size()>0&&nums[st.top()]<=nums[i]){
            st.pop();
        }
        if(st.size()==0) pgi[i]=-1;
        else pgi[i]=st.top();
        st.push(i);
    }
    vector<int>span(n);
    for(int i=0;i<n;i++){
        span[i]=i-pgi[i];
    }
    return span; 
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int>span=stock_span(nums);
    for(int i=0;i<n;i++){
        cout<<span[i]<<" ";
    }
    return 0;
}