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
  vector<int> d1(n), d2(n);
  rep(i, 0, n) cin >> d1[i] >> d2[i];
  rep(i, 0, n - 2)
  {
    if (d1[i] == d2[i] and d1[i + 1] == d2[i + 1] and d1[i + 2] == d2[i + 2])
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}