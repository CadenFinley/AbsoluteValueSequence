//
//  main32.cpp
//  absolutely different
//
//  Created by Caden Finley on 12/3/23.
//
#include <iostream>
#include <sstream>
int main() {
    const int MAX_SIZE = 50;
    int arr[MAX_SIZE];
    std::cout << "Enter list: ";
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    int n = 0;
    while (iss >> arr[n]) {
        ++n;
    }
    // Check if the input list meets the condition
    for (int i = 0; i < n - 1; ++i) {     //change number data to the difference of n - n+1
        arr[i] = std::abs(arr[i] - arr[i + 1]);
    }
    bool seen[MAX_SIZE] = {false};
    bool isGoodSequence = n>1 ? false : true;
    for (int i = 0; i < n - 1; ++i) {  //change number sequencing to t or f
        if (arr[i] >= 1 && arr[i] <= n - 1) {
            seen[arr[i] - 1] = true;
        } else {
            isGoodSequence = false;
            break;
        }
    }
    int missing=0;  //final check for number sequence
    for (int i = 0; i < n - 1; ++i) {
        if (!seen[i]) {
            missing = i + 1;
            break;
        }
    }
    if (isGoodSequence || missing==0) {
        std::cout << "Good sequence.\n";
    } else {
        std::cout << "Bad sequence: missing "<< missing << std::endl;
        
    }
    return 0;
}


