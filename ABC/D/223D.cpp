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
    ll n, m;
    cin >> n >> m;
    //有向グラフ
    vector<vector<ll>> to(n);
    //グラフの各頂点毎の入次数を格納
    vector<ll> deg(n);
    rep(i,m){
        //辺の入力
        ll a, b;
        cin >> a >> b;
        //0indexedで処理するために-1
        --a; --b;
        //aはbよりも先に現れるのでaからbへの辺を張る
        to[a].push_back(b);
        //bの入次数を+1する
        deg[b]++;
    }
    //入次数が0のものだけをpushする優先度付きqueue
    //昇順で並び頂点番号の小さいものから順に取り出される
    priority_queue<ll,vector<ll>,greater<ll>> q;
    //優先度付きqueueの初期設定
    //最初から入次数が0のものだけをpush
    rep(i,n){
        if(deg[i] == 0){
            q.push(i);
        }
    }
    //問題文の条件通りに頂点番号を並べる配列
    vector<ll> ans;
    //トポロジカルソート
    //queueが空になるまで処理
    while(q.size()){
        //入次数が0で頂点番号が小さい順に取り出す
        ll v = q.top(); q.pop();
        //順列Pを作るためにvを選んだのでansに格納
        ans.push_back(v);
        //頂点vを消す処理
        for(ll u : to[v]){
            //vから行ける各頂点の入次数を-1してvからの辺を消す
            deg[u]--;
            //その時入次数が0になったら自由に選べる頂点になったことを意味するのでpush
            if(deg[u] == 0){
                q.push(u);
            }
        }
    }
    //上記の処理を行うとサイクル部分以外の全ての頂点がansに格納される
    //もしansのsizeがnに満たないのならサイクルがあり、
    //順列Pを生成できないので-1を出力する
    if(ans.size() != n){
        cout << -1 << endl;
    }else {
        //サイクルがなかったのでansを順に出力する
        for(ll v : ans){
            //0indexedで処理していたので+1しながら出力
            cout << v+1 << endl;
        }
    }
    return 0;
}
//有向グラフ問題
//この問題はトポロジカルソートをできるか判定し、
//できるならトポロジカルソートする問題である
//トポロジカルソートができるかの判定は与えられたグラフがDAGであるかを判定すれば良い
//DAGとはサイクルのない有向グラフのことである
//サイクルはグラフにあるかもしれない閉路のこと
//トポロジカルソートの方法としては
//グラフの頂点の入次数(その頂点に入ってくる辺の数)が0のものでかつ
//頂点番号が一番小さいものを選び、その頂点とそこから繋がる辺を削除する
//という動作を繰り返すことでできる
//
