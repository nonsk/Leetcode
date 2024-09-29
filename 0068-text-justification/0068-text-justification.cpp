class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> resTotal;
        for (int i = 0; i < words.size(); i++) {
            vector<string> tempRow;
            int currentSize = 0;
            int j = i;
            for (j = i; j < words.size(); j++) {
                if (currentSize + words[j].size() <= maxWidth) {
                    tempRow.push_back(words[j]);
                    currentSize += (words[j].size() + 1);
                } else
                    break;
            }

            string res = "";
            int leftOverSpace = maxWidth - currentSize + 1;
            int distribute = 0, left = 0;

            if (tempRow.size() > 1) {
                distribute = leftOverSpace / (tempRow.size() - 1);
                left = leftOverSpace % (tempRow.size() - 1);
            } else {
                distribute = leftOverSpace;
            }
            if (j == words.size() || tempRow.size() == 1) {
                for (int i = 0; i < tempRow.size() - 1; i++) {
                    res += tempRow[i];
                    res += " ";
                }
                res += tempRow.back();
                for (int i = 0; i < leftOverSpace; i++) {
                    res += " ";
                }
            } else {
                for (int i = 0; i < tempRow.size(); i++) {
                    res += tempRow[i];
                    if (i != tempRow.size() - 1) {
                        res += " ";
                        for (int j = 0; j < distribute; j++) {
                            res += " ";
                        }

                        if (left > 0) {
                            res += " ";
                            left--;
                        }
                    }
                }
                cout << res << endl;
            }

            resTotal.push_back(res);
            i = j - 1;
        }
        return resTotal;
    }
};