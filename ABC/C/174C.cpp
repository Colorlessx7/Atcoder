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
    ll k;
    cin >> k;
    //最初の7の時にmodKを持っておく(k=7の時にバグるので回避用)
    ll x = 7 % k;
    //重複確認用
    set<ll> st;
    //7のみで作られる数の項数,カウンタとして機能
    ll i = 1;
    //重複が発見されるまで処理(鳩の巣原理によりk項目まで処理するのも正解)
    //(鳩の巣原理:modKの値は0=k-1までだからk回回せばmodKが0になるものがあるなら見つかる)
    while(st.count(x) == 0){
        //a[i]が0 modKとなったのでiを出力して終了
        if(x == 0){
            cout << i << endl;
            return 0;
        }
        //重複判定用のsetにmodKの結果xを格納
        st.insert(x);
        //次の項を調べるためにxを変更(数列a[i]の漸化式(i>=2)部分)
        x = (x*10+7) % k;
        //カウンタを進める
        ++i;
    }
    //ループで0 modKになるiが見つからなかったので-1を出力
    cout << -1 << endl;
    return 0;
}
//modを有効活用する問題
//与えられた数列をa[i]とすると問題はa[i]が0 modKとなる最小のiを求めよとなる
//数列はa[i] = 7 modK (i=1), = 10*a[i-1]+7 modK (i>=2)となる
//modKをとった値に対してx=(x*10+7)の遷移をしてmodKをとるのと
//元の値777...の次の項に対してmodKを取るのでは値が変わらないため
//modKをとったもので計算を続けていく
//オーバーキルな手法として
//xの遷移をグラフの辺として0~k-1までのグラフを作り
//頂点7から何回で頂点0に辿り着けるか探索するというものがある
