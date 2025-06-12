class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> output;
        vector<string> tmp;
        int count = 0;
        int currentSize = 0;

        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            int newSize = currentSize + count + word.size(); // count is #spaces

            if (newSize <= maxWidth) {
                tmp.push_back(word);
                count++;
                currentSize += word.size();
            } else {
                // Justify current line (not including current word)
                output.push_back(justify(tmp, maxWidth, false));
                tmp = {word};
                count = 1;
                currentSize = word.size();
            }
        }

        // Last line (left-justified)
        output.push_back(justify(tmp, maxWidth, true));
        return output;
    }

private:
    string justify(vector<string>& words, int maxWidth, bool isLastLine) {
        if (words.size() == 1 || isLastLine) {
            string line = words[0];
            for (int i = 1; i < words.size(); i++) {
                line += " " + words[i];
            }
            line += string(maxWidth - line.size(), ' ');
            return line;
        }

        int totalChars = 0;
        for (string& w : words) totalChars += w.size();

        int totalSpaces = maxWidth - totalChars;
        int gaps = words.size() - 1;
        int spacePerGap = totalSpaces / gaps;
        int extraSpaces = totalSpaces % gaps;

        string line;
        for (int i = 0; i < words.size(); i++) {
            line += words[i];
            if (i < gaps) {
                line += string(spacePerGap + (i < extraSpaces ? 1 : 0), ' ');
            }
        }

        return line;
    }
};
