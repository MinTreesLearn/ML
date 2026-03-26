#include <iostream>
#include <string>


int main() {

    int n, left = 0, right = 0;
    std::string s;
    std::cin >> n >> s;

    for (auto x : s) {
        if (x == 'L') {
            left++;
        } else {
            right++;
        }
    }

    std::cout << left + right + 1;

    return 0;
}
