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
    int n,q;
    string s;
    cin >> n >> s >> q;
    //前半後半が入れ替わるかのフラグ
    bool f1 = 0;
    //全体の文字数
    int n2 = n * 2;
    rep(i,q){
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1){
            //string配列で扱いやすいようデクリメント
            --a; --b;
            //反転フラグが立っているならただしく入れ替えるため
            //インデックスを調整(aは+n,bは-nしてるのと一緒)
            if(f1){
                a = (a+n)%n2;
                b = (b+n)%n2;
            }
            //swap処理
            swap(s[a],s[b]);
        }else {
            //フラグ反転
            f1 = !f1;
        }
    }
    //出力前に反転フラグが立っている場合文字列の分割と結合を行う
    if(f1){
        string s1 = s.substr(0,n);
        string s2 = s.substr(n);
        s = s2 + s1;
    }
    cout << s << endl;
    return 0;
}
