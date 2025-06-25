Check if frequencies can be equal

class Solution {
  public:
    bool sameFreq(std::string& s) {
        std::unordered_map<char, int> freqMap;

        // Step 1: Count frequency of each character
        for (char ch : s) {
            freqMap[ch]++;
        }

        // Step 2: Count how many times each frequency occurs
        std::unordered_map<int, int> freqCount;
        for (auto& entry : freqMap) {
            freqCount[entry.second]++;
        }

        // If there's only one frequency, it's already valid
        if (freqCount.size() == 1) return true;

        // If more than 2 different frequencies, not possible with one removal
        if (freqCount.size() > 2) return false;

        // Now we have exactly 2 different frequencies
        auto it1 = freqCount.begin();
        auto it2 = std::next(it1);

        int freq1 = it1->first, count1 = it1->second;
        int freq2 = it2->first, count2 = it2->second;

        // Now check if one of the frequencies is 1 and it occurs only once
        if ((freq1 == 1 && count1 == 1) || (freq2 == 1 && count2 == 1)) {
            return true;
        }

        // Or one frequency is higher by 1 and occurs only once
        if ((abs(freq1 - freq2) == 1) && ((freq1 > freq2 && count1 == 1) || (freq2 > freq1 && count2 == 1))) {
            return true;
        }

        return false;
    }
};
