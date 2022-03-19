#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define replr(i,l,r) for(int i = l; i < r; i++)
#define reprl(i,l,r) for(int i = l; i > r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
typedef long long ll;
using P = pair<int,int>;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> c(n,vector<int>(n));
    int low = INT_MAX;
    int li = 0, lj = 0;
    rep(i,n){
        rep(j,n){
            cin >> c[i][j];
            if(low > c[i][j]){
                low = c[i][j];
                //Cijの最小座標決定
                li = i;
                lj = j;
            }
        }
    }
    //差分配列
    vector<int> hdiff(n-1),wdiff(n-1);
    //縦に隣接している数字の差分を取る
    rep(i,n-1){
        hdiff[i] = c[i+1][0] - c[i][0];
    }
    //横に隣接している数字の差分を取る
    rep(j,n-1){
        wdiff[j] = c[0][j+1] - c[0][j];
    }
    //横の差分が他の行でも一緒か確認
    replr(i,1,n){
        rep(j,n-1){
            if(wdiff[j] != c[i][j+1] - c[i][j]){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    //縦の差分が他の列でも一緒か確認
    replr(j,1,n){
        rep(i,n-1){
            if(hdiff[i] != c[i+1][j] - c[i][j]){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    int f = 0;
    //a,b配列最終出力
    vector<int> ansa(n),ansb(n);
    //a配列決定
    rep(i,n){
        //cの最小がある列で最小を0とした場合の数列を計算
        f = c[i][lj] - c[li][lj];
        //こちらは最小の値を数列の全要素に足すことで辻褄合わせ
        f += c[li][lj];
        ansa[i] = f;
    }
    //b配列決定
    rep(j,n){
        //cの最小がある行で最小を0とした場合の数列を計算
        f = c[li][j] - c[li][lj];
        ansb[j] = f;
    }
    //出力
    cout << "Yes" << endl;
    rep(i,n){
        cout << ansa[i] << " ";
    }
    cout << endl;
    rep(j,n){
        cout << ansb[j] << " ";
    }
    cout << endl;
    return 0;
}
//数学的考察問題
//Cij = Ai + Bjを満たす:隣接している数字の差分が
//どの行、列でも対応している場所なら同じ
//差分をwdiff,hdiffに格納して全行列に対して対応している場所の差分が同じか判定
//Yesならc二次元配列の最も小さい値の値と座標を記録して
//その値がある行・列でその値を0とした場合にそれに伴い数字を調整して
//答えのa,b配列を作成する
//ただしcの最も小さい値が0でないならa,b配列のどちらかの全要素に
//その最も小さい値をたす必要がある

//修正案として差分hdiff,wdiffを考えるのではなく各行列の最も小さい値を
//事前に把握しておいてa,b配列を決めるときと同じようにCijから小さい値を引いて
//全ての値を0に合わせた時の数列が一緒になるならYes,そうでないならNoとして
//diffの計算を省くことができたはず
