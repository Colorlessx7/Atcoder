#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m),b(m);
    rep(i,m){
        cin >> a[i] >> b[i];
    }
    int k;
    cin >> k;
    vector<int> c(k),d(k);
    rep(i,k){
        cin >> c[i] >> d[i];
    }
    int k2 = 1 << k; 
    int ans = 0;
    rep(s_,k2){
        vector<int> dish(n+1);
        //今回は2進数は16桁が最大なので
        //この16の部分に変数は使えない
        bitset<16> s(s_);
        rep(i,k){
            //i桁目が1ならdの皿
            if(s[i]){
                dish[d[i]]++;
            }else {
                dish[c[i]]++;
            }
        }
        int now = 0;
        rep(i,m){
            if(dish[a[i]] == 0){
                continue;
            }
            if(dish[b[i]] == 0){
                continue;
            }
            now++;
        }
        ans = max(ans,now);
    }
    cout << ans << endl;
    return 0;
}
//bit全探索のbitsetバージョン
//bitsetは固定長なのが問題
