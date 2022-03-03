#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define all(x) x.begin(),x.end() 
typedef long long ll;
using P = pair<int,int>;
bool compare_pair(pair<ll,ll> a, pair<ll,ll> b){
    if(a.second != b.second){
        return a.second < b.second;
    }
    return 0;
}
int main(){
    ll n;
    cin >> n;
    vector<pair<ll,ll>> ab(n);
    rep(i,n){
        cin >> ab[i].first >> ab[i].second;
    }
    sort(ab.begin(),ab.end(), compare_pair);
    ll sum = 0;
    rep(i,n){
        sum += ab[i].first;
        ab[i].first = sum;
    }
    rep(i,n){
        if(ab[i].first > ab[i].second){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
