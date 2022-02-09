#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<int> s(n),t(n);
    rep(i,n){
        cin >> s[i];
    }
    rep(i,n){
        cin >> t[i];
    }
    //2周回せば全ての初めての宝石をカバーできるため2周回す
    rep(i,n * 2){
        //配列の範囲を超えるためnで割ったあまりである必要がある
        t[(i + 1)%n] = min(t[(i + 1)%n],t[i%n] + s[i%n]);
    }
    rep(i,n){
        cout << t[i] << endl;
    }
    return 0;
}
//2つめ以降の宝石は無視できる 
//1つ目の宝石が渡される時間はその前の人が受け取ってから渡すまでの時間t[i]+s[i]と
//その人が高橋から受け取る時間t[(i + 1)]の小さい方となる

//円環構造の累積和のような問題
