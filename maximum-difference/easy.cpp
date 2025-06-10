class Solution {
public:
    int maxDifference(string s) {
        int maxOdds = 0, minEvens = 0;
        unordered_map<char, int> hashMap;

        for (int i = 0; i < s.length(); i++) {
            char key = s[i];

            auto it = hashMap.find(key);
            if (it != hashMap.end())
                hashMap[key] = it->second + 1;
            else
                hashMap[key] = 1;
        }

        for (const auto& pair : hashMap) {
            int value = pair.second;
            if (value % 2 == 1)
                maxOdds = maxOdds > value ? maxOdds : value;
            else
                minEvens = minEvens > value ? value : minEvens == 0 ? value : minEvens;
        }

        return maxOdds - minEvens;
    }
};
