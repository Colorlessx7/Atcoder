#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n, k;
    cin >> n >> k;
    vector<ll> c(n);
    rep(i,n){
        cin >> c[i];
    }
    int ans = 0;
    map<int,int> mp;
    int now = 0;
    rep(i,n){
        //map内に存在する数が0の時にその値が出現したので今の種類数nowを+1
        //飴の種類が増えた
        if(mp[c[i]] == 0){
            now++;
        }
        //出現したので+1
        mp[c[i]]++;
        //取れる飴の最大値に達したら先頭を消去
        if(i >= k){
            mp[c[i - k]]--;
            //map内の飴の種類が減ったらnowを-1
            if(mp[c[i - k]] == 0){
                now--;
            }
        }
        //nowとansを比較し最大の更新
        ans = max(ans,now);
    }
    cout << ans << endl;
    return 0;
}
//c[0],[1],[2]とc[1],[2],[3]では種類は2しか変化しない
//種類は見る場所を1ずらしても大差ないので差分を計算する
//1個次を見るのにO(1)かO(logN)とかの小さい計算量でできる
//差分を見るために頻度を計算できるkey,value式のmapを使う
//プログラム簡略化のため例をc={1,2,1,2,3,3,1}とすると
//mapに{1},{1,2},{1,2,1},{2,1,2},{1,2,3},{2,3,3},{3,3,1}の順に格納
//{1},{1,2}は3つを見ている時よりも答えの値がよくなることはないため問題ない
            
                