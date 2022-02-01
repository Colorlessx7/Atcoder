int n, k, q;
    cin >> n >> k >> q;
    vector<int> p(n,k - q);
    rep(i,q){
        int a;
        cin >> a;
        a--;
        p[a]++;
    }
 
 /*ABC141Cから
 このようにvector a[q] を宣言したところで処理に影響はないので
 入力時に処理させてしまってもいい*/

//ABC151C かなり苦手なのでよく考える必要がある

#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
typedef long long ll;
int main(){
    int n,m;//問題数・回答数
    cin >> n >> m;
    vector<int> ac(n),pena(n);//問題ごとの正解フラグとペナルティ数
    rep(i,m){
        int p;//問題番号入力
        string s;//ACorWA
        cin >> p >> s;
        --p;
        if(ac[p]){
            continue;//すでにACしているならスルー
        }
        if(s == "AC"){
            ac[p] = 1;//正解フラグを立てる
        }else {
            pena[p]++;//ペナルティ数の計上
        }
    }
    int AC = 0, PENA = 0;
    rep(i,n){
        AC += ac[i];//正解数
        if(ac[i]){
            PENA += pena[i];//AC済の問題のペナルティの合計
        }  
    }
    printf("%d %d\n", AC, PENA);
    return 0;
}

