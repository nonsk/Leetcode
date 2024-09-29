class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        string s;
        vector<string> answer;
        string line = "";
        int char_sum = 0;
        int num_of_words = 0;
        vector<string> temp_words;
        int i;
        for(i = 0; i < words.size(); i++) {
            temp_words.push_back(words[i]);
            num_of_words = temp_words.size();
            char_sum = char_sum + words[i].size();
            if (char_sum + num_of_words - 1 > maxWidth) {
                while (char_sum + num_of_words - 1 > maxWidth) {
                    temp_words.pop_back();
                    char_sum = char_sum - words[i].size();
                    i--;
                }
                line = "";
                for (int it = 0; it < temp_words.size(); it++) {
                    
                    if (it == temp_words.size() - 1) {
                            
                        if(line.size() + temp_words[it].size() < maxWidth) {
                            if (maxWidth - line.size() - temp_words[it].size()<
                                temp_words.size() - 1) {
                                line = "";
                                int diff = maxWidth - line.size() - temp_words[it].size();
                                           cout<<"initial : "<<diff<<endl;
                                for (int it1 = 0; it1 < temp_words.size()-1;
                                     it1++) {
                                    if (diff == 0) {
                                        line = line + temp_words[it1];
                                    } else {
                                        cout<<"for"<<line<<". "<<diff<<endl;
                                        line = line + temp_words[it1] + ' ';
                                        diff--;
                                    }
                                }
                                line += temp_words[it];

                                break;
                            }
                            line = "";
                            it = -1;
                        }
                        else if (line.size() + temp_words[it].size() == maxWidth) {
                            line = line + temp_words[it];
                            break;
                        }

                    } 
                    else {
                        temp_words[it] += ' ';
                        line += temp_words[it];
                    }
                }
                answer.push_back(line);
                line = "";
                temp_words.clear();
                char_sum = 0;
            }

        }
        cout<<temp_words[0]<<endl;
        string last_line = "";
        for(int next = 0; next<=temp_words.size(); next++){
            if(next==temp_words.size()){       
                string latest_space(maxWidth-last_line.size(), ' ');
                last_line += latest_space;
                break;
            }
            last_line += temp_words[next]+' ';
            cout<<next<<endl<<temp_words[next]<<endl<<last_line<<endl;

        }
        answer.push_back(last_line);

        return answer;
    }
};