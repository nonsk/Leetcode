class Solution {
public:
    string add(vector<string>& ans) {
        int carry = 0;
        string answer = "";
        int num =0;
        for (int j = 200; j >= 0; j--) {
            for (int i = 0; i < ans.size(); i++) {
                num = num + (ans[i][j] - '0');
            }
            cout << num << endl;
            cout << carry<< endl;
            if (j == 0) {
                answer = to_string(carry + num) + answer;
            } else {
                answer = to_string((carry + num) % 10) + answer;
            }
            carry = (carry + num) / 10;
            num = 0;
            cout<<answer<<endl<<endl;
        }
        while(answer[0]=='0'){
            answer = answer.substr(1,answer.size()-1);
        }
        return answer;
    }
    string multiply(string num1, string num2) {
        string temp = "";
        int carry = 0;
        vector<string> ans;
        for (int i = num1.size() - 1; i >= 0; i--) {
            for (int j = num2.size() - 1; j >= 0; j--) {
                char one = num1[i];
                char two = num2[j];
                int x = (one - '0') * (two - '0');
                cout << x << endl;
                if (j == 0) {
                    temp = to_string(carry + x) + temp;
                } else {
                    temp = to_string((carry + x) % 10) + temp;
                }
                carry = (carry + x) / 10;
                cout << temp << endl;
                cout << carry << endl << endl;
            }
            string zeros(num1.size() - 1 - i, '0');
            temp = temp + zeros;
            string front(201 - temp.size(), '0');
            ans.push_back(front + temp);
            temp = "";
            carry = 0;
        }
        for (auto it : ans) {
            cout << it << endl;
        }
        string final1 = add(ans);
        return (final1=="")?"0":final1;
        
    }
};