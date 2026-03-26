#include <iostream>
#include <string>

const int SIZE = 1e4; 


int main() {

    int t, x;
    std::cin >> t;
    std::string arr[SIZE];
    
    for (int i = 0; i < t; i++) {
        std::cin >> x;
        arr[i] = "1 " + std::to_string(x - 1);
    }

    for (int i = 0; i < t; i++) 
        std::cout << arr[i] << "\n";

    return 0;
}
