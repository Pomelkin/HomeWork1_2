#include <iostream>
#include <cstring>


void recursive_out(int *operators, int index) {
    if (index == 0) {
        std::cout << index+1;
        return;
    }
    std::cout << "(";
    recursive_out(operators, index-1);
    switch (operators[index-1])
    {
    case 0:
        std::cout << "+";
        break;
    case 1:
        std::cout << "-";
        break;
    case 2:
        std::cout << "*";
        break;
    case 3:
        std::cout << "/";
        break;
    }
    std::cout << index+1 << ")";
}


int main() {
    bool flag = true, results = false;
    int k, n, *operators;
    std::cin >> k >> n;
    operators = new int[k-1];
    for (int i = 0; i < k-1; ++i) {
        operators[i] = 0;
    }
    while (flag) {
        int subresult = 1;
        for (int i = 1; i < k; ++i) {
            switch (operators[i-1])
            {
            case 0:
                subresult += i+1;
                break;
            case 1:
                subresult -= i+1;
                break;
            case 2:
                subresult *= i+1;
                break;
            case 3:
                subresult /= i+1;
                break;
            }
        }
        if (subresult == n) {
            results = true;
            recursive_out(operators, k-1);
            std::cout << std::endl;
        }
        for (int i = 0; i < k-1; ++i) {
            operators[i]++;
            if (operators[i] > 3) {
                flag = i != k - 2;
                operators[i] = 0;
            } else
                break;
        }
    }
    if (!results) {
        std::cout << "Нет решений" << std::endl;
    }
    return 0;
}