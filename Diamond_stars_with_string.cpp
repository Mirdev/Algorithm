#include <iostream>
#include <string>

int main() {
    int height;
    while (true) {
        std::cout << "Enter the height of the diamond (odd number only): ";
        std::cin >> height;

        if (height <= 0)
            std::cout << "ERROR: Height must be greater than 0!" << std::endl;
        else if (height % 2)
            break;
        else
            std::cout << "ERROR: Only odd numbers are allowed!" << std::endl;
    }

    std::cout << std::endl;

    for (int i = 0; i < height; i++) {
        if (i < height / 2) {
            std::cout 
                << std::string(height / 2 - i, ' ')
                << std::string(1 + i * 2, '*')
                << std::endl;
        } else {
            std::cout 
                << std::string(i - height / 2, ' ')
                << std::string((height - i) * 2 - 1, '*')
                << std::endl;
        }
    }

    std::cout << std::endl;
    return 0;
}
