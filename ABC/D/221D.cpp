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
    cin >> n;
    //累積和を取るための先頭の+1と末尾(範囲外の最初の位置)の-1のイベントを格納
    //+1のイベントはkey:a,value:1
    //-1のイベントはkey:a+b,value:-1
    //範囲が被って+1,-1でなくなる可能性がある
    map<int,int> mp;
    rep(i,n){
        int a, b;
        cin >> a >> b;
        //+1のイベント設定
        mp[a]++;
        //-1のイベント設定
        mp[a+b]--;
    }
    //pre:前の日時,now:その時ログインしていた人数(累積和配列の値に対応)
    int pre = -1, now = 0;
    //ちょうどi人ログインしている人数を格納
    //ans[i]の添字は同時にログインしている人数
    vector<int> ans(n+1);
    //各イベントを順に処理
    //mapはkeyでsortされているのでイベントを昇順に最初から見れる
    //t:日時,x:増減の値 auto pでp.first:t,p.second:xに対応
    for(auto [t,x] : mp){
        //イベントの間隔がnow人が同時にログインしていた日数なのでそれを足す
        ans[now] += t - pre;
        //イベントを処理し次の日以降のログインしていた人数を変更
        now += x;
        //日時を一つ前の人数の変化があったタイミングに変更
        pre = t;
    }
    //答えを出力(atcoderなら改行出力も可)
    rep2(i,n){
        cout << ans[i] << endl;
    }
    return 0;
}
//累積和を使う問題
//累積和のテクニックとして[a,a+b-1]の空間全てに+1するときに
//aの場所に+1,a+bの場所に-1をするイベントを設置して
//最後に累積和を取ると[a,a+b-1]の空間全てに+1した状態となる
//今回は制約上イベントを配列で持てないのでこのイベントをmapで管理する
//
