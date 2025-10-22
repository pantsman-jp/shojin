#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n;
  cin >> n;
  vector<string> s(n);
  vector<int> a(n);
  rep(i, n) { cin >> s[i] >> a[i]; }
  int start = distance(a.begin(), min_element(a.begin(), a.end()));
  rep(i, n) { cout << s[(start + i) % n] << endl; }
}
