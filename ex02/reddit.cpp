// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <limits.h>

// struct Pair {
//     int first;
//     int second;
// };

// bool comparePairs(const Pair& a, const Pair& b) {
//     return a.second < b.second;
// }

// void fordJohnsonSort(std::vector<Pair>& pairs) {
//     if (pairs.size() <= 1) return; // Base case: nothing to sort

//     // Sort pairs based on the second element
//     std::stable_sort(pairs.begin(), pairs.end(), comparePairs);

//     // Prepare for the next level of recursion
//     std::vector<Pair> nextLevelPairs;
//     for (size_t i = 0; i < pairs.size(); i += 2) {
//         if (i + 1 < pairs.size()) {
//             // Combine pairs into a new pair for the next level
//             nextLevelPairs.push_back(Pair{pairs[i].second, pairs[i+1].second});
//         } else {
//             // Handle the last pair if the total number of pairs is odd
//             nextLevelPairs.push_back(Pair{pairs[i].second, INT_MAX}); // Use INT_MAX as a sentinel value
//         }
//     }

//     // Recurse on the next level
//     fordJohnsonSort(nextLevelPairs);

//     // At this point, nextLevelPairs is sorted. Now, we need to rearrange the first elements of the original pairs.
//     // This step is omitted for brevity but involves matching the sorted second elements with their corresponding first elements.
// }

// int main() {
//     std::vector<Pair> pairs = {{6, 7}, {5, 8}, {1, 3}, {2, 4}};
//     fordJohnsonSort(pairs);

//     // Output the sorted pairs
//     for (const auto& pair : pairs) {
//         std::cout << "(" << pair.first << ", " << pair.second << ")" << std::endl;
//     }

//     return 0;
// }



#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

// Helper function to print the contents of a vector
void printVector(const std::vector<int>& vec) {
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

// Function to perform the Ford-Johnson sorting algorithm
void fordJohnsonSort(std::vector<int>& nums) {
    if (nums.size() <= 1) return; // Base case: nothing to sort

    // Stage 1: Pair elements and sort them
    std::vector<std::pair<int, int>> pairs;
    for (size_t i = 0; i < nums.size(); i += 2) {
        if (i + 1 < nums.size()) {
            pairs.push_back(std::make_pair(nums[i], nums[i + 1]));
        } else {
            pairs.push_back(std::make_pair(nums[i], INT_MAX)); // Use INT_MAX as a placeholder for the last element if the list size is odd
        }
    }

    // Stage 2: Sort pairs based on the second element
    std::stable_sort(pairs.begin(), pairs.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second < b.second;
    });

    // Stage 3: Flatten the pairs back into a single list
    nums.clear();
    for (const auto& pair : pairs) {
        nums.push_back(pair.first);
        if (pair.second!= INT_MAX) {
            nums.push_back(pair.second); // Skip adding the placeholder if present
        }
    }

    // Recursively sort the flattened list
    fordJohnsonSort(nums);
}

int main() {
    std::vector<int> numbers = {6, 7, 8, 5, 3, 1, 2, 4};
    fordJohnsonSort(numbers);
    // printVector(numbers); // Should print: 1 2 3 4 5 6 7 8

    return 0;
}
