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
  int r;
  cin >> r;
  if (r < 1200)
    cout << "ABC" << endl;
  else if (r < 2800)
    cout << "ARC" << endl;
  else
    cout << "AGC" << endl;
}