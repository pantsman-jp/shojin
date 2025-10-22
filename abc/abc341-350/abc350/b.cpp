#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n, q;
  cin >> n >> q;
  vector<int> teeth(n, 1);
  for (int i = 0; i < q; ++i)
  {
    int t;
    cin >> t;
    --t;
    teeth[t] = (teeth[t] + 1) % 2;
  }
  int ans = 0;
  for (int t : teeth)
    ans += t;
  cout << ans << endl;
}
