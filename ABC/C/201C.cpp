#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    string s;
    cin >> s;
    int ans = 0;
    //0000~9999の1万回回す
    rep(num,10000){
        //それぞれの値が出たか確認する配列
        vector<int> a(10);
        int x = num;
        rep(i,4){
            //下一桁を取り出す
            int d = x%10;
            //確認用配列の下一桁の数字の部分にフラグを立てる
            a[d] = 1;
            //取る桁をズラすための操作
            x /= 10;
        }
        //条件に沿うか判定するboolの値
        bool ok = true;
        rep(i,10){
            //暗証番号に入ってるはずの数字が抜けている時の処理
            if(s[i] == 'o' && a[i] != 1){
                ok = false;
            }
            //暗証番号にないはずの数字が入っている時の処理
            if(s[i] == 'x' && a[i] != 0){
                ok = false;
            }
        }
        if(ok){
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
//法則性を考えずとりあえず全探索する問題
