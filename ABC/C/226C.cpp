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
int main(){
    int n;
    cin >> n;
    vector<int> t(n);
    vector<vector<int>> a(n);
    rep(i,n){
        int k;
        cin >> t[i] >> k;
        //配列サイズがそれぞれ違うのでここで指定
        a[i] = vector<int>(k);
        rep(j,k){
            //頂点番号が1スタートなのでやりやすいように-1
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    //n-1の技を習得するのに必要ならフラグを立てる
    vector<bool> need(n);
    //最終的に習得したい技なのでtrue
    need[n-1] = true;
    //右から見るためiをn-1~0まで回す
    rep3(i,n){
        //need[i]がtrueなら伝播するので見る
        if(need[i]){
            //伝播した技(有向グラフの先)をtrueにする
            for(int j : a[i]){
                need[j] = true;
            }
        }
    }
    ll ans = 0;
    rep(i,n){
        //必要な技の習得にかかる時間を足し合わせる
        if(need[i]){
            ans += t[i];
        }
    }
    cout << ans << endl;
    return 0;
}
//有向グラフ(DAG)の問題
//DAG:サイクルがなくトポロジカルソートされているグラフ
//右(n-1)から順番に習得すべき技(最終的にn-1の技を得るのに必要)かをbool配列でとる
