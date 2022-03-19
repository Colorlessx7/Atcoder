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
    vector<int> x(n),y(n);
    //y座標の値、同じy座標の人の番号iの連想配列
    map<int,vector<int>> mp;
    rep(i,n){
        cin >> x[i] >> y[i];
        //入力後、同じy座標の人の集合にi番目の人を増やす
        mp[y[i]].push_back(i);
    }
    string s;
    cin >> s;
    //mapの全要素に対しループ
    for(auto p : mp){
        //参照渡しでコピーを避ける
        //fは同じy座標の人の番号iを格納
        vector<int>& f = p.second;
        int m = f.size();
        //left:右向きに移動する人の一番小さいx座標
        //right:左向きに移動する人の一番大きいx座標
        //min,maxに邪魔しない普通にやったらとりようのない数字で初期化
        int left = INT_MAX, right = -1;
        //同じy座標の人でleftとrightの値を決定 
        for(int i = 0; i < m; i++){
            //Rならleftの最小か判定し格納
            //Lならrightの最大か判定し格納
            //f[i]で元の番号iであることに注意
            if(s[f[i]] == 'R'){
                left = min(left,x[f[i]]);
            }else {
                right = max(right,x[f[i]]);
            }
        }
        //同じy座標の人が1人しかいないパターン
        if(left == INT_MAX || right == -1){
            continue;
        }else {
            //右向きに移動する人の一番小さいx座標が
            //左向きに移動する人の一番大きいx座標より小さい(左側)ならば衝突
            if(left < right){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    //右向きに移動する人の一番小さいx座標が
    //左向きに移動する人の一番大きいx座標より小さい(左側)パターンが存在しない
    //ので衝突はなかった
    cout << "No" << endl;
    return 0;
}
//考察問題
//y座標が一致、右向きに移動する人の一番小さいx座標が
//左向きに移動する人の一番大きいx座標より小さい(左側)ならば衝突する(Yes)
//y座標が同じ人をmapのvalueの配列で固めて
