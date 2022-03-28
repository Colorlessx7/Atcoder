#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(ll i = 0; i < N; i++)
#define rep2(i,N) for(ll i = 1; i <= N; i++)
#define rep3(i,N) for(ll i = N - 1; i >= 0; i--)
#define rep4(i,N) for(ll i = N; i > 0; i--)
#define replr(i,l,r) for(ll i = l; i < r; i++)
#define reprl(i,l,r) for(ll i = l; i > r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
typedef long long ll;
using P = pair<ll,ll>;
int main(){
    int n;
    string s;
    cin >> n >> s;
    //文字列RGBを012の集合に直す配列
    vector<int> a(n);
    //文字列RGBを012の集合に直す
    rep(i,n){
        if(s[i] == 'R'){
            a[i] = 0;
        }else if(s[i] == 'G'){
            a[i] = 1;
        }else if(s[i] == 'B'){
            a[i] = 2;
        }
    }
    //0,1,2の個数を計上する配列
    vector<ll> cnt(3);
    //0,1,2の個数を計上
    rep(i,n){
        cnt[a[i]]++;
    }
    ll ans = 1;
    //この計算で条件2のj-i!=k-jを無視した
    //全部異なる文字の組み合わせの総数が求まる
    rep(i,3){
        ans *= cnt[i];
    }
    rep(j,n){
        rep(i,j){
            //j-i=k-jの変形でkを求めた形
            //i,j,kの文字が全部違うならj-i=k-jを満たす組み合わせになる
            int k = j + (j - i);
            if(k < n){
                //kを決めたら今見ている３文字がRGBで全て異なっているか判定
                //異なっていない場合はスルー
                if(a[i] == a[j]){
                    continue;
                }
                if(a[i] == a[k]){
                    continue;
                }
                if(a[j] == a[k]){
                    continue;
                }
                //条件1と条件2のNotが満たされているので答えから-
                ans--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
//包除原理で全体の総数(全部異なる文字の組み合わせ)を求めてから
//条件2を満たさない(j-i=k-jを満たす)組み合わせを引いて求める
