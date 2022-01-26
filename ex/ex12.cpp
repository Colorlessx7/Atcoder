#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int y = 1;
  // ここにプログラムを追記
  int N = S.size();
  for  (int i = 1; i < N; i = i + 2)
  {
      if (S.at(i) == '+'){
          y++;
      }else if (S.at(i) == '-'){
          y--;
      }
  }
  cout << y << endl;  
}
