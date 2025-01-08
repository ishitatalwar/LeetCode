class Solution {
public:
    void swapIfGreater(vector<int>& nums1, vector<int>& nums2, int ind1, int ind2) {
        if (nums1[ind1] > nums2[ind2]) {
            swap(nums1[ind1], nums2[ind2]);
        }
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Length of the combined array
        int len = m + n;

        // Initial gap
        int gap = (len / 2) + (len % 2);

        while (gap > 0) {
            // Place two pointers
            int left = 0;
            int right = left + gap;
            while (right < len) {
                // Case 1: left in nums1[] and right in nums2[]
                if (left < m && right >= m) {
                    swapIfGreater(nums1, nums2, left, right - m);
                }
                // Case 2: both pointers in nums2[]
                else if (left >= m) {
                    swapIfGreater(nums2, nums2, left - m, right - m);
                }
                // Case 3: both pointers in nums1[]
                else {
                    swapIfGreater(nums1, nums1, left, right);
                }
                left++, right++;
            }

            // Break if iteration with gap = 1 is completed
            if (gap == 1) break;

            // Otherwise, calculate new gap
            gap = (gap / 2) + (gap % 2);
        }

        // Finally, copy nums2 into the remaining part of nums1
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
    }
};
