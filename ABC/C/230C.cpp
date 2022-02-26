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
    ll n, a, b, p, q, r, s;
    cin >> n >> a >> b >> p >> q >> r >> s;
    //高さq-p+q,幅s-r+1の答え用の文字配列
    vector<vector<char>> ans(q-p+1,vector<char>(s-r+1,'.'));
    rep(i,q-p+1){
        rep(j,s-r+1){
            //答えの配列は(p,r)から始まるので
            //その座標がn*nの元の座標のどこに対応するかは
            //(x,y)=(p+i,r+j)となりこれに対応する
            ll x = p+i, y = r+j;
            if(x-y == a-b || x+y == a+b){
                ans[i][j] = '#';
            }
        }
    }
    rep(i,q-p+1){
        rep(j,s-r+1){
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}
//普通に数学的考察して解く問題
//愚直にn*nの範囲の図を作り切り抜こうとしたら間に合わない
//座標(x,y)のx,yからそこの色.or#が欲しい
//最終的に(x,y)が(a+k,b+k)または(a+k,b-k)になれば#になる
//この時xとyについてそれぞれ
//x-y=(a+k)-(b+k)=a-b
//x+y=a+k+b-k=a+b
//が成り立ち、x,yとa,bの関係にkが絡まなくなる
//よって上記の2式のどちらかが成り立てば#成り立たないなら.となるように
//p,q,r,sで決められた範囲を全探索すれば良い
