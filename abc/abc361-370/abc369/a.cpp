#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int a, b;
  cin >> a >> b;
  set<int> ans;
  ans.insert(2 * a - b);
  ans.insert(2 * b - a);
  if ((a + b) % 2 == 0)
    ans.insert((a + b) / 2);
  cout << ans.size() << endl;
}
