#include <iostream>
using namespace std;

int main()
{
  int n, a, ans = 0;
  cin >> n >> a;
  for (int i = 0; i < n; i++)
  {
    int t;
    cin >> t;
    ans = max(t, ans) + a;
    cout << ans << endl;
  }
}
