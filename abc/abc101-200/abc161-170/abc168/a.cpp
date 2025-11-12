#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int m = n % 10;
  if (m == 3)
    cout << "bon" << endl;
  else if (m == 0 or m == 1 or m == 6 or m == 8)
    cout << "pon" << endl;
  else
    cout << "hon" << endl;
}