Pythagorean Triplet

class Solution {
public:
    bool pythagoreanTriplet(vector<int>& arr) {
        const int MAX = 1000;
        vector<int> freq(MAX + 1, 0);

        // Count frequencies
        for (int val : arr) {
            freq[val]++;
        }

        // Check all combinations of a and b
        for (int a = 1; a <= MAX; ++a) {
            if (freq[a] == 0) continue;
            for (int b = a; b <= MAX; ++b) {
                if (freq[b] == 0) continue;

                int c2 = a * a + b * b;
                int c = (int)sqrt(c2);

                if (c > MAX) continue;
                if (c * c != c2) continue;

                if (freq[c]) {
                    // Ensure all elements are from different indexes
                    if ((a == b && b == c && freq[a] >= 3) ||
                        (a == b && freq[a] >= 2 && freq[c] >= 1) ||
                        (a == c && freq[a] >= 2 && freq[b] >= 1) ||
                        (b == c && freq[b] >= 2 && freq[a] >= 1) ||
                        (a != b && b != c && a != c)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
