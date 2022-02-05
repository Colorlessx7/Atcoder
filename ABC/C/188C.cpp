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
    map<int,int> mp;//レート、選手番号のmapをとる
    rep(i,n2){
        mp[a[i]] = i + 1;//mapに格納
    }
    while(a.size() > 2){
        vector<int> na;//1回線が終わった後の選手のリスト
        for(int i = 0; i < a.size(); i += 2){
            na.push_back(max(a[i],a[i + 1]));//トーナメント処理
        }
        swap(a,na);//aを1回線が終わった後に
    }//ループが終わると選手が2人残る
    int ans = min(a[0],a[1]);//負けたほう
    cout << mp[ans] << endl;
    return 0;
}
