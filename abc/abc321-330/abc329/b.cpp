#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  set<int> a;
  rep(_, n)
  {
    int m;
    cin >> m;
    a.insert(m);
  }
  int largest = *max_element(a.begin(), a.end()), ans = 0;
  for (int m : a)
  {
    if (m != largest)
      ans = max(ans, m);
  }
  cout << ans << endl;
}
