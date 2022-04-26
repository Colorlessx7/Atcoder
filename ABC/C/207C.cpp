#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(ll i = 0; i < N; i++)
#define rep2(i,N) for(ll i = 1; i <= N; i++)
#define rep3(i,N) for(ll i = N - 1; i >= 0; i--)
#define rep4(i,N) for(ll i = N; i > 0; i--)
#define replr(i,l,r) for(ll i = l; i < r; i++)
#define reprl(i,l,r) for(ll i = l; i >= r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
using ll = long long;
using P = pair<ll,ll>;
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
    int n;
    cin >> n;
    vector<ll> l(n),r(n);
    rep(i,n){
        int t;
        cin >> t >> l[i] >> r[i];
        //閉区間と開区間の4パターンを全て閉区間として考えたい
        //全てを2倍して、開区間の部分を1ずらすと全て閉区間として扱える
        l[i] *= 2;
        r[i] *= 2;
        //左端が開区間なら+1方向にずらす
        if(t >= 3){
            l[i]++;
        }
        //右端が開区間なら-1方向にずらす
        if(t % 2 == 0){
            r[i]--;
        }
    }
    int ans = 0;
    //同じペアを2回やらないように
    //rep(i,n)rep(j,i)でjは常にi未満を試すため重複なくできる
    rep(i,n){
        rep(j,i){
            //閉区間同士が被ってないか判定
            if(r[i] < l[j]){
                continue;
            }
            if(r[j] < l[i]){
                continue;
            }
            //被っている場合+
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
