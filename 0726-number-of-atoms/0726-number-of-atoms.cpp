class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> stk;
        map<string, int> atomCount;
        int n = formula.size();
        int i = 0;
        while (i < n) {
            if (formula[i] == '(') {

                stk.push(atomCount);
                atomCount.clear();
                i++;
            } else if (formula[i] == ')') {

                i++;
                int start = i;
                while (i < n && isdigit(formula[i]))
                    i++;
                int multiplier =
                    (start < i) ? stoi(formula.substr(start, i - start)) : 1;

                map<string, int> temp = atomCount;
                atomCount = stk.top();
                stk.pop();
                for (auto& [atom, count] : temp) {
                    atomCount[atom] += count * multiplier;
                }
            } else {

                int start = i++;
                while (i < n && islower(formula[i]))
                    i++;
                string atom = formula.substr(start, i - start);

                start = i;
                while (i < n && isdigit(formula[i]))
                    i++;
                int count =
                    (start < i) ? stoi(formula.substr(start, i - start)) : 1;

                atomCount[atom] += count;
            }
        }
        string result;
        for (auto& [atom, count] : atomCount) {
            result += atom;
            if (count > 1)
                result += to_string(count);
        }
        return result;
    }
};