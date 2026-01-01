// Problem-URL : "https://cses.fi/problemset/task/1662/"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(auto &i : arr)cin>>i;
    vector<ll> prefix(n, 0);
    prefix[0] = arr[0];
    for(ll i=1; i<n; i++){
        prefix[i] = prefix[i-1] + arr[i];
    }
    
    map<ll, ll> mp;
    mp[0] = 1;
    ll ans = 0;
    for(ll i=0; i<n; i++){
        ll val = ((prefix[i]%n)+n)%n;
        // cout<<val<<endl;
        if(mp.find(val) != mp.end()){
            ans += mp[val];
        }
        mp[val]++;
    }
   
    cout<<ans<<endl;

    

    return 0;
}