#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
const int MaxA = 200;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }
    //nの制約に対しAの絶対値の制約が極端に低いので
    //-200 ~ 200 の登場個数を格納する配列
    //カウント用 -200で添字が0になるように下駄を履かせている 0で初期化
    vector<int> d(MaxA * 2 + 1);
    ll ans = 0;
    rep(i,n){
        //例n=3,a={2,8,4}の時　ループ内の計算は最初0で回数ごとに1回ずつ増える
        //例i=0,1回目for空ループd[201]=1
        //  i=1,aj=2,c=1,x=8-2=6,ans+=36,d[208]=1
        //  i=2,aj=2,c=1,x=4-2=2,ans+=4
        //      aj=8,c=1,x=4-8=-4,ans+=16,d[204]=1,ループ終了
        for(int aj = -MaxA; aj <= MaxA; aj++){
            //c:個数　x:Ai-Ajで差分
            int c = d[MaxA + aj];
            int x = a[i] - aj;
            ans += (ll)x * x * c;
        }
        d[MaxA + a[i]]++;
    }
    cout << ans << endl;
    return 0;
}
