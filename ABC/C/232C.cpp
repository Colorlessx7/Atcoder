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
    int n, m;
    cin >> n >> m;
    //無向グラフ
    vector ga(n,vector<int>(n));
    vector gb(n,vector<int>(n));
    rep(i,m){
        int a, b;
        cin >> a >> b;
        //配列を0indexで管理したいので-1
        --a, --b;
        //無向グラフの連結設定
        ga[a][b] = ga[b][a] = 1;
    }
    rep(i,m){
        int a, b;
        cin >> a >> b;
        --a, --b;
        gb[a][b] = gb[b][a] = 1;
    }
    //順列用配列
    vector<int> p(n);
    //順列要素の設定
    rep(i,n){
        p[i] = i;
    }
    //順列全探索
    do{
        //gは下の説明のGBPi,Pjにあたる二次配列
        vector g(n, vector<int>(n));
        rep(i,n){
            rep(j,n){
                //gaの各頂点をpの順列に沿って並べ替えたものをgとする
                g[i][j] = ga[p[i]][p[j]];
            }
        }
        //順列の全パターンの中から一つでも
        //グラフの形が同じものがあるならYesで終了
        if(g == gb){
            cout << "Yes" << endl;
            return 0;
        }
    }while(next_permutation(all(p)));
    //どの順列パターンでも同じ形にならないならNoで終了
    cout << "No" << endl;
    return 0;
}
//グラフの同型判定問題
//nの制約(n<=8)からnext_permutationで順列全探索を行う
//無向グラフがどう連結しているかは二次元配列で管理
//整数GAi,jを、高橋君のおもちゃにおいてボールi,jを結ぶ
//ひもが存在するなら1、そうでないなら0と定めます。
//同様に、整数GBi,jを、青木君のおもちゃにおいてボールi,jを結ぶ
//ひもが存在するなら1、そうでないなら0と定めます。
//順列Pを全探索することを考えます。Pが条件をみたすことは、次が成り立つことと同値である
//1≤i≤N,1≤j≤N に対しGBi,j=GAPi,Pj
//これが成り立つかどうかはO(N^2)で判定
//Pとしては N!通りあるので、全体の計算量はO(N^2×N!)となり、実行時間制限に間に合う
