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
map<pair<ll,ll>,bool> mp; 
//aとsが与えられた時にx&y=a,x+y=sを満たす組み合わせがあるかを返す関数
bool f(ll a, ll s){
    //再帰関数のベースケース
    //sは再帰の過程で単調減少する
    //sが0になった時aが0ならtrueとしてaが0出ないならfalseとして再帰元に返り続ける
    //aが0でないということはx,yに1がまだ必ず存在し
    //これまでのx,yの合計がすでに最初のsと等しくなっているため
    //x&y=a,x+y=sを今までに決めたx,yでは満たさないためfalse
    //aが0ならこれ以上x,yが増えず、x&y=a,x+y=sを満たすためtrue
    if(!s){
        return a == 0;
    }
    //メモ化再帰ですでに見たことがあるa,sの組み合わせかどうかを識別するタグ
    auto p = make_pair(a,s);
    //すでに試されている(a,s)の組み合わせならその時の結果のboolを返す
    if(mp.count(p)){
        return mp[p];
    }
    //1の位についてx,yが(0,0),(0,1),(1,0),(1,1)の全パターンを試す
    rep(x,2){
        rep(y,2){
            //xの1桁目とyの1桁目のANDがaの1桁目と一致していないならコンティニュー
            if((x&y) != (a&1)){
                continue;
            }
            //sからx,yを引いた値が0未満(x,yが過剰で問題の条件を満たさない)ならスルー
            if(s-x-y < 0){
                continue;
            }
            //x,yの1桁目を決めた時のx,yの和の1桁目とsの1桁目が一致していないならスルー
            //s=3(2進0011),x=1,y=1ならx+y=10となってsの1桁目と違ってしまう(%2=1)
            //s=3(2進0011),x=0,y=1ならx+y=1となってsの1桁目と一致する(%2=0)
            if((s-x-y)%2 != 0){
                continue;
            }
            //上の条件をくぐり抜けるx,yの組み合わせにx,yを確定した場合に処理
            //次の桁を試すために再帰する、最初のa,sが1,8でx,yを1,1とした時、
            //sの残りの値は8-1-1で6になるため
            //最初の下一桁は2^0=1なので
            //bit演算のためにもa,s両方とも1ビット右シフトする
            if(f(a>>1,(s-x-y)>>1)){
                //mp[p]をtrueにしつつ再帰元にtrueを返す
                //一つYesのパターンが見つかったらベースケースを経てここから再帰元に返り続ける
                return mp[p] = true;
            }
        }
    }
    //ある桁においてx,yの4パターン全てが当てはまらないようなa,sの組み合わせなら
    //mp[p]をfalseにしつつ再帰元にfalseを返す
    //ある桁でx,yの4パターン全て当てはまらずここを通っても前の桁のx,yを
    //変えて試すため1度ここを通ったからといってfalseになるわけではない
    return mp[p] = false;
}
void solve(){
    ll a, s;
    cin >> a >> s;
    //メモ化再帰の定数倍処理が重くなるのを回避するためにmapをリセット(map内の探索にlogかかる)
    mp = map<pair<ll,ll>,bool>();
    if(f(a,s)){
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }
}
int main(){
    int t;
    cin >> t;
    rep(i,t){
        solve();
    }
    return 0;
}
//桁DPをメモ化再帰でとく
//x,yをa,sの条件に従うように下の桁からそれぞれ決めていくイメージ
//
