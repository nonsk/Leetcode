class Solution {
public:
        int b2n(const string& binary) {
        int ans = 0;
        int power = 0;
        for (int i = binary.size() - 1; i >= 0; i--) {
            if (binary[i] == '1') {
                ans += (1 << power);
            }
            power++;
        }
        return ans;
    }

    string comp(int num) {
        string binaryComplement = "";
        if (num == 0) return "1";

        while (num != 0) {
            int bit = num % 2;
            binaryComplement = (bit ? '0' : '1') + binaryComplement; 
            num /= 2;
        }
        return binaryComplement;
    }

    int bitwiseComplement(int num) {
        string binaryCompStr = comp(num);  
        return b2n(binaryCompStr);         
    }
};
