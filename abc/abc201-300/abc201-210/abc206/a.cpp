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
  int val = (108 * n) / 100;
  if (val < 206)
    cout << "Yay!" << endl;
  else if (val == 206)
    cout << "so-so" << endl;
  else
    cout << ":(" << endl;
}