// URL = "https://cses.fi/problemset/task/1660"


#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    
    ll n,x;
    cin>>n>>x;
    vector<ll> arr(n);
    for(auto &i : arr)cin>>i;
    
    ll ans = 0;
    int i=0, j=1;
    ll curr = arr[i];
    while(i<=j && j<n){
        // cout<<"i : "<<i<<" j: "<<j<<" curr: "<<curr<<endl;
        if(curr<x){
            curr += arr[j];
            j++;
        }else if(curr==x){
            ans++;
            curr += arr[j];
            j++;
        }
        // cout<<curr<<endl;
        while(curr>x && i<n){
            curr -= arr[i];
            i++;
        }
        // cout<<curr<<endl;
    }
    if(curr==x){
        ans++;
    }

    cout<<ans<<endl;
    

    return 0;
}