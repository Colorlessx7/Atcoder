#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> b(n,vector<int>(m));
    rep(i,n){
        rep(j,m){
            cin >> b[i][j];
        }
    }
    //カレンダーの列を配列的に0123456で管理したいので全て-1する
    rep(i,n){
        rep(j,m){
            b[i][j]--;
        }
    }
    //bの行列の先頭の行をsi,列をsjとして計算する
    int si = b[0][0] / 7;
    int sj = b[0][0] % 7;
    //先頭の列からb行列の列の数を追加した値が7以上だったら
    //0123456からなる列をはみ出していることになるのでNo
    if(sj + m - 1 >= 7){
        cout << "No" << endl;
        return 0;
    }
    rep(i,n){
        rep(j,m){
            //nb:b行列の任意の場所の値が計算通りか判定する値
            int nb = (si+i)*7 + (sj+j);
            if(b[i][j] != nb){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
