#include <iostream>
using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;
  int vacant = k, ans = 0;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    if (vacant < a)
    {
      ++ans;
      vacant = k;
    }
    vacant -= a;
  }
  cout << ++ans << endl;
}
