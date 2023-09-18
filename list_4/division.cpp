#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int t = 0;
    while (cin >> n, n)
    {
        if(t++)
			printf("\n");

        bool found = false;

        for (int second_num = 1234; second_num <= 98765 / n; ++second_num)
        {
            int first_num = second_num * n;

            // Convert first_num and second_num to strings with 5 digits
            string first_str = to_string(first_num);
            string second_str = to_string(second_num);

            // Pad with leading zeros if necessary
            while (first_str.length() < 5)
            {
                first_str = "0" + first_str;
            }

            while (second_str.length() < 5)
            {
                second_str = "0" + second_str;
            }

            string nums = first_str + second_str;

            if (nums.size() == 10 && is_permutation(nums.begin(), nums.end(), "0123456789"))
            {
                found = true;
                cout << first_str << " / " << second_str << " = " << n << '\n';
            }
        }

        if (!found)
        {
            cout << "There are no solutions for " << n << ".\n";
        }
    }
    return 0;
}
