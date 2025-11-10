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
  if (n < 42)
  {
    if (n < 10)
      cout << "AGC00" << n << endl;
    else
      cout << "AGC0" << n << endl;
    return 0;
  }
  n++;
  if (n < 100)
    cout << "AGC0" << n << endl;
  else
    cout << "AGC" << n << endl;
}