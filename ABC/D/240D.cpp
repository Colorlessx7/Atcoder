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
int main() {
    int n;
    cin >> n;
    //筒の中のボールの個数
    int count = 0;
    //ボールの書かれた数字・その個数のpairの配列
    vector<P> ball;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        count += 1;
        if (ball.empty() or ball.back().first != a) {
            ball.emplace_back(a, 1);
        } else {
            ball.back().second += 1;
            if (ball.back().second == a) {
                count -= a;
                ball.pop_back();
            }
        }
        cout << count << '\n';
    }
    return 0;
}
