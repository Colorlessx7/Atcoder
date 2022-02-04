#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
int main(){
    string s;
    cin >> s;
    int ans = s.size();
    //iが白か黒かを0,1に　最初を規定
    rep(i,2){
        int cnt = 0;
        rep(j,s.size()){
            //0+2n個目のどれかであること・文字列のj番目が白か黒かのXORをとって正ならカウントアップ
            if((j % 2 == 0) ^ (s[j] == (char)('0' + i))){
                cnt++;
            }
        }
        ans = min(ans,cnt);//少ない方
    }
    cout << ans << endl;
    return 0;
}
