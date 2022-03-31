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
//2項演算:要素数の合計(0~7の木で木のデータが1,3,4,5なら
//0~1=1,2~3=1,4~5=2,6~7=0,0~3=2,4~7=2,0~7=4となる)
int op(int a, int b){
    return a+b; 
}
//bool関数fで登場するため仕方なくグローバルに
int k;
//segtreeの初期状態
int e(){ 
    return 0; 
}
//
bool f(int x){
    if(x < k){
        return true;
    }else {
        return false;
    }
}
int main(){
    int n;
    cin >> n >> k;
    //2^19 near= 5*10^5(制約範囲)の完全二分木の宣言
    segtree<int, op, e> seg(524288);
    //segtreeに要素が何個追加されたかのカウント
    int cnt = 0;
    rep(i,n){
        int p;
        cin >> p;
        //
        p--;
        cnt++;
        //segtreeの末端に新たな順列pの要素
        seg.set(p,seg.get(p)+1);
        //segtreeの要素がk個以上なら都度k番目に大きい要素を出力
        if(cnt >= k){    
            cout << seg.min_left<f>(524287) << endl;
        }
    }
    return 0;
}
//segtreeを使用して解いたver
