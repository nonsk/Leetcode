class Solution {
public:
    string addBinary(string a, string b) {
            int i = a.size() - 1, j = b.size() - 1, carry = 0;
    string result = "";

    // Traverse both strings from the end
    while (i >= 0 || j >= 0 || carry) {
        // Get the binary digits or 0 if index is out of range
        int digitA = (i >= 0) ? a[i] - '0' : 0;
        int digitB = (j >= 0) ? b[j] - '0' : 0;

        // Calculate the sum of digits and carry
        int total = digitA + digitB + carry;
        carry = total / 2;           // Update carry
        result += (total % 2) + '0'; // Append the binary digit

        // Move the pointers
        i--;
        j--;
    }

    // Reverse the result string as it was built backwards
    reverse(result.begin(), result.end());
    return result;
    }
};