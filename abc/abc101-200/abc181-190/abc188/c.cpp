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
  int n2 = 1 << n;
  vector<int> a(n2);
  rep(i, 0, n2) cin >> a[i];
  vector<int> head = vector(a.begin(), a.begin() + n2 / 2);
  vector<int> tail = vector(a.begin() + n2 / 2, a.end());
  cout << find(all(a), min(*max_element(all(head)), *max_element(all(tail)))) - a.begin() + 1 << endl;
}