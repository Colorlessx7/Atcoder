#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = n - 1; i >= 0; i--)
#define rep4(i,N) for(int i = n; i > 0; i--)
#define all(x) x.begin(),x.end() 
typedef long long ll;
using P = pair<int,int>;
//グローバル変数(乱用注意)
int n, ans;
ll x;
vector<vector<int>> a;
//深さ優先探索DFS(再帰関数)
//i:何個目の集合を選ぼうとしているのか
//s:現在の積がいくつか
void dfs(int i, ll s){
    //終了条件:i=nは袋の種類がa[0]~a[n-1]まであり、その積を計算し終わったら終了
    //(i=nはa配列の外であるため)
    if(i == n){
        //その時点の総積がxと等しいなら答えを+1
        if(s == x){
            ans++;
        }
        return;
    }
    //計算処理部分
    //選んでいる袋の中のボールを全て探索
    rep(j,a[i].size()){
        //s*a[i][j]がオーバーフローの可能性がある
        //移項して以下の判定で積がxを超えるならそれ以降は無意味なのでスルー
        if(s > x/a[i][j]){
            continue;
        }
        //次の袋へ向かう
        dfs(i+1, s*a[i][j]);
    }
}
int main(){
    cin >> n >> x;
    a = vector<vector<int>>(n);
    rep(i,n){
        int l;
        cin >> l;
        a[i] = vector<int>(l);
        rep(j,l){
            cin >> a[i][j];
        }
    }
    dfs(0,1);
    cout << ans << endl;
    return 0;
}
//深さ優先探索DFS問題
//3 1 8 4
//2 10 5ならば
//3*2,3*10,3*5,1*2,1*10,1*5,8*2,8*10,8*5,4*2,4*10,4*5の順に
//再起関数で探索していく 8*5,4*10で答えは2になる
