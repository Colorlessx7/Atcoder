#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    int n2 = 1 << n;//2倍
    vector<int> a(n2);
    rep(i,n2){
        cin >> a[i];
    }
    map<int,int> mp;//レートがkey、選手番号がvalueのmapをとる
    rep(i,n2){
        mp[a[i]] = i + 1;//mapに格納
    }
    queue<int> q;
    rep(i,n2){
        q.push(a[i]);//キューに追加
    }
    int ans = 0;
    while(q.size() > 1){
        int x = q.front(); q.pop();//先頭のキューをxに格納　その後キューを進める
        int y = q.front(); q.pop();//先頭のキューをxに格納　その後キューを進める
        q.push(max(x,y));//キューに勝者を追加
        ans = min(x,y);//敗者を登録するとループ終了時に準優勝のレートが格納される
    }
    cout << mp[ans] << endl;
    return 0;
}
