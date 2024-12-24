class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        
        // Early exit for size 1, no next permutation possible
        if (n <= 1) {
            return;
        }
        
        int ind = -1;
        
        // Step 1: Find the break point
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] < arr[i + 1]) {
                ind = i;
                break;
            }
        }

        // Step 2: If the break point doesn't exist, reverse the entire array
        if (ind == -1) {
            reverse(arr.begin(), arr.end());
            return;  // Early return after reversing for the case of the largest permutation
        }

        // Step 3: Find the next greater element and swap
        for (int i = n - 1; i > ind; i--) {
            if (arr[i] > arr[ind]) {
                swap(arr[i], arr[ind]);
                break;
            }
        }

        // Step 4: Reverse the right part of the array after index `ind`
        reverse(arr.begin() + ind + 1, arr.end());
    }
};
