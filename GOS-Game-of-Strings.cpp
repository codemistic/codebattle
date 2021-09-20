#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        int count = 0;
        for (int i = 0; i < s.length() - 1;)
        {
            if (s[i] != s[i + 1])
            {
                count++;
                i += 2;
            }
            else
            {
                i++;
            }
        }
        cout << count << "\n";
    }
    return 0;
}
