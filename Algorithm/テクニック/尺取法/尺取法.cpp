//ABC229Dより

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
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    //Xを0に.を1にして配列に格納
    vector<int> a(n);
    rep(i,n){
        //比較演算子==でsのi番目の文字が.ならa[i]が1になる
        a[i] = s[i] =='.'; 
    }
    int ans = 0;
    //r:尺取法の右端 尺取法の見る範囲は半開区間で
    //lからrの一つ手前の部分までが.をXにしてXを連続させられる区間
    //sum:現在尺取法で見ている区間の.の総数
    int r = 0, sum = 0;
    //全体でO(n)の計算量でできる
    //左端lを一つずつ伸ばす
    rep(l,n){
        //計算量rがループ終わりに+1されていくのでO(n)
        //右端rを文字列の最大nまで伸ばすからr < n
        //尺取法で見ている範囲の.の総数がk以内だったらループ続行
        //(rの一つ手前までが尺取法の見る範囲なのでa[r]=1でsum+a[r]が
        //kの値を超えたらその一つ前までが尺取法で見るべき範囲になる)そこまでループ
        while(r < n && sum + a[r] <= k){
            //a[r]を足す
            sum += a[r];
            //rを進める
            ++r;
        }
        //l番目からk個.をXに変えた時のXの連続している範囲r-lが
        //それ以前のlからの連続しているXの範囲より大きいならansに格納
        ans = max(ans,r-l);
        //lを1個進める前にl番目の要素を引いておく
        sum -= a[l];
    }
    cout << ans << endl;
    return 0;
}
//尺取法で解く問題
//半開区間で持っておく理由はk=0の時に同じ文字の部分だけで可能ということにしてしまうため
