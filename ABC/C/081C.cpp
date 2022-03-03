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
bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}
int main(){
    int n, k;
    cin >> n >> k;
    map<int,int> mp;
    rep(i,n){
        int a;
        cin >> a;
        mp[a]++;
    }
    vector<P> an;
    for(auto &p : mp){
        an.emplace_back(p);
    }
    sort(all(an),compare);
    int f = an.size() - k;
    int ans = 0;
    rep(i,f){
        ans += an[i].second;
    }
    cout << ans << endl;
    return 0;
}
//map, mapをpair配列に移しsecondを基準にsort, 少しの考察
