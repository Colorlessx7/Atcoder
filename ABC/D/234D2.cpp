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
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    rep(i,n){
        cin >> p[i];
    }
    //今見ているpの範囲にその数字が登場したら1のbool配列
    vector<bool> c(n+1);
    //K番目に大きいp配列の値の位置を示すカーソル
    int ans = 0;
    //一番最初のk番目に大きいp配列の値の位置を決めるために
    //i=0~k-1までのk個分のp配列の値の登録(bool配列のフラグ立て)
    rep(i,k){
        c[p[i]] = true;
    }
    //一番最初のk番目に大きいp配列の値の位置を決める
    while(!c[ans]){
        ++ans;
    }
    //1回目の出力
    cout << ans << endl;
    //p[k]からp[n-1]までのループ
    for(int i = k; i < n; i++){
        //新しいp配列の値の登録(bool配列のフラグ立て)
        c[p[i]] = true;
        //新しいp配列の値が今のk番目に大きい値より大きいなら処理
        if(p[i] > ans){
            //k番目に大きい値の位置からk+1番目に大きい値にずれたので
            //k番目に大きい値の位置までカーソルを動かしたいが
            //ここからwhileを回すとすでにフラグが立っているため一旦カーソルを+1して回す
            ++ans;
            while(!c[ans]){
                ++ans;
            }
        }
        //都度k番目に大きい値を出力
        cout << ans << endl;
    }
    return 0;
}
//線形探索(ならし計算)での解
//答えは単調増加になる
//pにその数字が登場するかをbool配列cで持っておいて
//ansをK番目に大きい値の位置を示すカーソルとして
//今のK番目に大きい値よりも小さい値が次のpで登場した場合はスルー
//今のK番目に大きい値よりも大きい値が次のpで登場した場合は
//ansのカーソルを次に大きいpの位置(c[ans]=true)の位置までずらす
//という処理を繰り返すことで実装できる
//一応この他にもsegtree、平衡二分探索木を使う方法がある
