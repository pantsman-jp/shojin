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
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(k);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, k) cin >> b[i], b[i]--;
  int max = *max_element(all(a));
  rep(i, 0, n)
  {
    if (a[i] == max and find(all(b), i) != b.end())
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}