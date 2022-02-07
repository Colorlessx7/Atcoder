#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<int> a(n),b(n),c(n);
    rep(i,n){
        cin >> a[i];
    }
    rep(i,n){
        cin >> b[i];
    }
    rep(i,n){
        cin >> c[i];
    }
    //i,jの組み合わせが10^10になり得るのでll
    ll ans = 0;
    //Aiの種類と個数のカウント配列 a={1,2,2}の時cnt={0,1,2,0},0~nなのでn+1サイズ必要
    vector<int> cnt(n + 1);
    rep(i,n){
        cnt[a[i]]++; 
    }
    //jを全部試す 片方の変数を固定する問題
    rep(j,n){
        //配列の先頭は0なので-1
        ans += cnt[b[c[j] - 1]];
    }
    cout << ans << endl;
    return 0;
}
