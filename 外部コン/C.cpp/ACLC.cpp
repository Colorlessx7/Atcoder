#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    //n:要素数,m:連結数
    int n,m;
    cin >> n >> m;
    //ACLのdsuを呼び出す
    //dsuはunion_findの祖集合データ構造
    //dsuを使うとunion_findが呼び出される
    //無向グラフに対して辺の追加と二頂点が連結かの判定が高速でできる
    dsu d(n);
    //辺の追加
    rep(i,m){
        //辺の2頂点
        int a, b;
        cin >> a >> b;
        --a; --b;
        //mergeで辺になる
        d.merge(a,b);
    }
    //cnt:連結成分の個数
    //groups:連結成分の外側のリストが返ってくる
    //sizeで外側のリストの個数を確認できる
    int cnt = d.groups().size();
    //連結させたい外側のリストの個数を−１したものが必要な連結数
    int ans = cnt - 1;
    cout << ans << endl;
    return 0;
}
