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
    if(a.first != b.first){
        return a.first > b.first;
    }else{
        return a.second < b.second;
    }
}
int main(){
    int n;
    cin >> n;
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
    int x = an.size();
    int h = 0, w = 0; 
    rep(i,x){
        //2以上あったら辺が作れるのでそのpairのfirstを1辺に
        if(an[i].second >= 2){
            h = an[i].first;
            //もう一つの辺を決めるために使った2本を消去
            an[i].second -= 2;
            break;
        }
    }
    rep(i,x){
        if(an[i].second >= 2){
            w = an[i].first;
            break;
        }
    }
    cout << (ll)h * w << endl;
    return 0;
}
//map, mapをpair配列に移しfirst降順second適当にsort 数学的考察少し
