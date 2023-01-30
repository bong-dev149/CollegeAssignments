#include <bits/stdc++.h>
using namespace std;

class BigNumMul
{
    int *num1, *num2, *result, m, n;

public:
    BigNumMul(string &num1, string &num2)
    {
        m = num1.size();
        n = num2.size();
        // cout << m <<" " << n << endl;
        this->num1 = new int[m];
        this->num2 = new int[n];
        this->result = new int[m + n + 1];
        for (int i = 0; i < m; i++)
        {
            this->num1[i] = num1[i] - '0';
        }

        for (int i = 0; i < n; i++)
        {
            this->num2[i] = num2[i] - '0';
        }

        for (int i = 0; i < m + n + 1; i++)
        {
            result[i] = 0;
        }
    }

    ~BigNumMul()
    {
        int x = m + n;
        // cout << m << n << endl;
        for (int i = n - 1; i >= 0; i--)
        {
            int tmp = num2[i];
            // cout << "hello" << endl;
            for (int j = m - 1; j >= 0; j--)
            {
                int mul = num1[j] * tmp;
                result[i + j + 1] += mul % 10;
                result[i+j] += result[i+j+1] / 10;
                result[i+j+1] %= 10;
                result[i+j] += mul/10;

                // for (int i = 0; i < x; i++)
                // {
                //     cout << result[i];
                // }
                // cout << endl;
            }
        }
        cout << "Result is : " << endl;
        for (int i = 0; i < x; i++)
        {
            cout << result[i];
        }
        cout << endl;
    }
};

int main()
{
    string num1, num2;
    cout << "Enter the first number  : ";
    cin >> num1;
    cout << "Enter the second number  : ";
    cin >> num2;
    BigNumMul bg(num1, num2);
    return 0;
}

