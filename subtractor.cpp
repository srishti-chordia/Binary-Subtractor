#include <iostream>
#include <chrono>
#include <string>

// Function to perform binary subtraction
std::string binarySubtraction(const std::string& binary1, const std::string& binary2) {
    std::string result;
    int borrow = 0;
    int length = binary1.length();

    for (int i = length - 1; i >= 0; i--) {
        int bit1 = binary1[i] - '0';
        int bit2 = binary2[i] - '0';

        int diff = (bit1 - bit2 - borrow + 2) % 2;
        borrow = (bit1 < bit2 + borrow) ? 1 : 0;

        result = std::to_string(diff) + result;
    }

    return result;
}

int main() {
    std::string binary1, binary2;
    
    std::cout << "Enter the first binary number: ";
    std::cin >> binary1;
    
    std::cout << "Enter the second binary number: ";
    std::cin >> binary2;

    // Ensure both binary strings have the same length
    if (binary1.length() != binary2.length()) {
        std::cerr << "Binary numbers must have the same length." << std::endl;
        return 1;
    }

    // Record the start time
    auto start = std::chrono::high_resolution_clock::now();

    // Perform binary subtraction
    std::string result = binarySubtraction(binary1, binary2);

    // Record the end time
    auto end = std::chrono::high_resolution_clock::now();
    
    // Calculate the time taken (latency) in microseconds
    std::chrono::microseconds latency = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    // Output the result
    std::cout << "Result: " << result << std::endl;

    // Output the execution time (speed) in microseconds
    std::cout << "Execution time (speed): " << latency.count() << " microseconds" << std::endl;

    return 0;
}
