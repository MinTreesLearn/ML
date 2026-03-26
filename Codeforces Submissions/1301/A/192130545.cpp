#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;

    cin >> t; // Taking the number of test case

    while (t--) {
        // Declaring and taking input in three string variable
        string str1, str2, str3;

        cin >> str1 >> str2 >> str3;

        // looping through all strings and compareing their words in same position
        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] == str3[i]) {
                str2[i] = str3[i]; // if string1[i] == string3[i] then string2[i] = string3[i]
            } else if (str2[i] == str3[i]) {
                str1[i] = str3[i]; // if string2[i] == string3[i] then string1[i] = string3[i]
            } else {
                str1[i] = str3[i]; // If none of them are true then just do string1[i] = string3[i]
            }
        }

        if (str1 == str2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
