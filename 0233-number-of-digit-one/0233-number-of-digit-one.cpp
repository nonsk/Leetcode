class Solution {
public:
    int countDigitOne(int n) {
        if (n == 0) {
            return 0;
        }
        if (n < 10) {
            return 1;
        }
        int digit = n;
        int num = 0;
        while (digit != 0) {
            num++;
            digit /= 10;
        }
        int temp = n % (int)pow(10, num - 1);
        int front = n / (int)pow(10, num - 1);
        int ans;
        if (front == 1) {
            ans = countDigitOne(temp) +
                      front * countDigitOne((int)pow(10, num - 1) - 1) + temp+1;
        } else {
            ans = countDigitOne(temp) +
                      (front) * countDigitOne((int)pow(10, num - 1) - 1) + pow(10,num-1);
        }
        return ans;
    }
};