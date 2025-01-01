class Solution {
public:
    int maxScore(string s) {
        int max_score = 0;
        int n = s.length();

        // Loop through all possible split points
        for (int i = 1; i < n; i++) {
            // Count the number of 0's in the left substring (from 0 to i-1)
            int left_zeros = 0;
            for (int j = 0; j < i; j++) {
                if (s[j] == '0') {
                    left_zeros++;
                }
            }
            // Count the number of 1's in the right substring (from i to n-1)
            int right_ones = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == '1') {
                    right_ones++;
                }
            }
            // Calculate the score for this split
            int current_score = left_zeros + right_ones;

            // Update max_score if the current score is higher
            if (current_score > max_score) {
                max_score = current_score;
            }
        }

        return max_score;
    }
};