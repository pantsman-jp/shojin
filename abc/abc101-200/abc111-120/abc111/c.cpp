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
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  vector<int> odd_hist(1e5 + 1, 0), even_hist(1e5 + 1, 0);
  rep(i, 0, n)
  {
    if (i & 1)
      odd_hist[a[i]]++;
    else
      even_hist[a[i]]++;
  }
  vector<P> odd, even;
  for (int i = 0; i < 1e5 + 1; ++i)
  {
    odd.push_back(P(odd_hist[i], i));
    even.push_back(P(even_hist[i], i));
  }
  sort(all(odd), greater<P>());
  sort(all(even), greater<P>());
  if (odd[0].second != even[0].second)
    cout << n - (odd[0].first + even[0].first) << endl;
  else
    cout << n - max(odd[0].first + even[1].first,
                    odd[1].first + even[0].first)
         << endl;
}