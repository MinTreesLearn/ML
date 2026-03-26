#include <iostream>
#include <map>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    int a, b, c, a1, b1, c1;
    for (int i = 0; i < t; i++){
        std::cin >> a >> b >> c;
        int N = 3, res = 0;
        std::vector<int> sets = {1, 2, 3, 4, 5, 6, 7};
        do {
            a1 = a;
            b1 = b;
            c1 = c;
            int counter = 0;
            for (auto set: sets){
                bool flag = false;
                std::vector<bool> bits;
                for (int j = 0; j < N; j++)
                    bits.push_back(set & 1 << j);
                if(a1 < bits[0])flag = true;
                if(b1 < bits[1])flag = true;
                if(c1 < bits[2])flag = true;
                if (!flag){a1 -= bits[0];b1 -= bits[1];c1 -= bits[2];counter++;}
            }
            if (counter > res){
                res = counter;
            }
            res = std::max(counter, res);
        }
        while (std::next_permutation(sets.begin(), sets.end()));

        std::cout << res << std::endl;
    }
    return 0;
}