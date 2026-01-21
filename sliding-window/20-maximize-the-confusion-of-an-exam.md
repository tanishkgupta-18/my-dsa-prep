## Solution-1
### NOTE: Here we use the same concept or pattern used in problem 09
```cpp
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        unordered_map<char, int> freq;
        int n = answerKey.size(), left = 0, maxFreq = 0, count = 0;
        for(int right = 0 ; right < n ; ++right){
            char c = answerKey[right];
            freq[c]++;
            maxFreq = max(maxFreq, freq[c]);

            while((right-left+1) - maxFreq > k){
                freq[answerKey[left]]--;
                left++;
            }

            count = max(count, right-left+1);
        }

        return count;
    }
};
```

## Solution-2
```cpp
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int countT = 0, countF = 0;
        int left = 0, ans = 0;

        for (int right = 0; right < answerKey.size(); right++) {
            if (answerKey[right] == 'T') countT++;
            else countF++;

            /* here are only two types of characters in the window (T and F), so one of them will be the minority.
            To make the window all the same, we must flip the minority characters.
            If the minority count is greater than k, the window is invalid. */
            while (min(countT, countF) > k) { 
                if (answerKey[left] == 'T') countT--;
                else countF--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
```