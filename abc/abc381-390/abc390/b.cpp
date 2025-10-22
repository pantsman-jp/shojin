#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  long long r_num = a[1], r_den = a[0];
  for (int i = 1; i < n - 1; i++)
  {
    if (a[i + 1] * r_den != a[i] * r_num)
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
