#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, l;
  cin >> n >> l;
  if (l % 3 != 0)
  {
    cout << 0 << endl;
    return 0;
  }
  vector<int> d(n - 1);
  rep(i, 0, n - 1) cin >> d[i];
  vector<int> pos(n);
  pos[0] = 0;
  rep(i, 1, n) pos[i] = (pos[i - 1] + d[i - 1]) % l;
  vector<ll> freq(l);
  rep(i, 0, n) freq[pos[i]]++;
  int shift = l / 3;
  ll total = 0;
  rep(v, 0, l)
  {
    total += freq[v] * freq[(v + shift) % l] * freq[(v + 2 * shift) % l];
  }
  cout << total / 3 << endl;
}
