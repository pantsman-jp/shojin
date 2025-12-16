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
  vector<int> h(n);
  rep(i, 0, n) cin >> h[i];
  for (int i = n - 2; i >= 0; i--)
  {
    if (h[i] > h[i + 1] + 1)
    {
      cout << "No" << endl;
      return 0;
    }
    else if (h[i] == h[i + 1] + 1)
      h[i]--;
  }
  cout << "Yes" << endl;
}