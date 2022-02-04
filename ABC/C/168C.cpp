#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    double a, b, h, m;
    cin >> a >> b >> h >> m;
    double pi = 3.141592653589793238;
    double rad;
    double rad1 = m * pi / 30;
    double rad2 = (h * pi / 6) + (m * pi / 360);
    if(rad1 > rad2){
        rad = rad1 - rad2;
    }else if(rad1 < rad2){
        rad = rad2 - rad1;
    }else {
        rad = 0;
    }
    double c = a * a + b * b - 2 * a * b * cos(rad); 
    double ans = sqrt(c);
    printf("%.10f\n",ans);
    return 0;
}
