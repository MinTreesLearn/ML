#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int output[t];
    for (int i = 0; i < t; i++)
    {
        int s[3];
        cin >> s[0] >> s[1] >> s[2];
        if (s[0] > 3)
        {
            s[0] = 4;
        }
        if (s[1] > 3)
        {
            s[1] = 4;
        }
        if (s[2] > 3)
        {
            s[2] = 4;
        }
        int M, m, mid;
        int iM, im;
        if ((s[0] <= s[1]) && (s[0] <= s[2]))
        {
            m = s[0];
            im = 0;
        }
        else if ((s[1] <= s[2]) && (s[1] <= s[0]))
        {
            m = s[1];
            im = 1;
        }
        else
        {
            m = s[2];
            im = 2;
        }
        if ((s[0] >= s[1]) && (s[0] >= s[2]))
        {
            M = s[0];
            iM = 0;
        }
        else if ((s[1] >= s[2]) && (s[1] >= s[0]))
        {
            M = s[1];
            iM = 1;
        }
        else
        {
            M = s[2];
            iM = 2;
        }
        if ((im != 0) && (iM != 0))
        {
            mid = s[0];
        }
        else if ((im != 1) && (iM != 1))
        {
            mid = s[1];
        }
        else
        {
            mid = s[2];
        }
        if (m > 3)
        {
            output[i] = 7;
        }
        else
        {
            if (m == M)
            {
                if (m == 0)
                {
                    output[i] = 0;
                }
                else if (m == 1)
                {
                    output[i] = 3;
                }
                else if (m == 2)
                {
                    output[i] = 4;
                }
                else
                {
                    output[i] = 6;
                }
            }

            else if (m == mid)
            {
                if (m == 0)
                {
                    output[i] = 1;
                }
                if (m == 1)
                {
                    output[i] = 3;
                }
                if (m == 2)
                {
                    output[i] = 5;
                }
                if (m == 3)
                {
                    output[i] = 6;
                }
            }
            else if (mid == M)
            {
                if (mid == 1)
                {
                    output[i] = 2;
                }
                else if (mid == 2)
                {
                    if (m == 0)
                    {
                        output[i] = 3;
                    }
                    else if (m == 1)
                    {
                        output[i] = 4;
                    }
                }
                else if (mid == 3)
                {
                    if (m == 0)
                    {
                        output[i] = 3;
                    }
                    else if (m == 1)
                    {
                        output[i] = 4;
                    }
                    else
                    {
                        output[i] = 5;
                    }
                }
                else
                {
                    if (m == 0)
                    {
                        output[i] = 3;
                    }
                    if (m == 1)
                    {
                        output[i] = 4;
                    }
                    if (m == 2)
                    {
                        output[i] = 5;
                    }
                    if (m == 3)
                    {
                        output[i] = 6;
                    }
                }
            }
            else
            {
                if (m == 0)
                {
                    if (mid == 1)
                    {
                        output[i] = 2;
                    }
                    else if (mid == 2)
                    {
                        output[i] = 3;
                    }
                    else
                    {
                        output[i] = 3;
                    }
                }
                else if (m == 1)
                {

                    output[i] = 4;
                }

                else if (m == 2)
                {
                    output[i] = 5;
                }
            }
        }
    }
    for (int i = 0; i < t; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}