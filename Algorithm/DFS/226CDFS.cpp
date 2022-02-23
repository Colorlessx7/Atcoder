#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define all(x) x.begin(),x.end() 
typedef long long ll;
using P = pair<int,int>;
ll sum;
//DFS(深さ優先探索)
void dfs(ll i,vector<ll>& t,vector<ll>& k,vector<vector<ll>>& a,vector<bool>& c){
    //その技を訪問済にする
    c[i] = true;
    //その技を覚えるために習得する必要がある技がない場合
    //(再帰関数のベースケース)
    if(k[i] == 0){
        //その技の習得に必要な時間を足す
        //技1でsum=1,技4でsum=6+4=10
        sum += t[i];
        //グラフの先端部分はここでリターン
        return;
    }
    //計算処理部分
    //その技を覚えるのに必要な技a[i][j]の範囲をループ
    for(int j : a[i]){
        //一度訪れているなら二重計算になるのでスルー
        //技3の時に技1をスルー,技2の時技1をスルー
        if(c[j]){
            continue;
        }
        //その技を習得するのに必要な技に向かう
        dfs(j,t,k,a,c);
    }
    //その技の習得に必要な時間を足す
    //技2の時sum=1+2=3,技3の時sum=3+3=6,技5終了でsum=10+5=15
    sum += t[i];
    //グラフの途中部分はここでreturn
    return;
}
int main(){
    ll n;
    cin >> n;
    vector<ll> t(n);
    vector<ll> k(n);
    vector<vector<ll>> a(n);
    vector<bool> c(n,false);
    rep(i,n){
        cin >> t[i] >> k[i];
        //配列サイズが違うのでここで指定
        a[i] = vector<ll>(k[i]);
        rep(j,k[i]){
            cin >> a[i][j];
            //技が0indexなので-1する
            a[i][j]--;
        }
    }
    //最終的に覚えたい技からDFSを始める
    dfs(n-1,t,k,a,c);
    cout << sum << endl;
    return 0;
}
//DFSで実装したver
//5                
//1 0
//2 1 1
//3 2 1 2
//4 0
//5 3 1 3 4
//の場合はdfsの再帰関数で
//技5 - 技1
//　  - 技3 -x 技1
//          - 技2 -x 技1
//　  - 技4

