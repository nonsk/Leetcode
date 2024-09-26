class Solution {
public:
    string intToRoman(int num) {
        string s = "";
            while (num >= 1000) {
                num = num - 1000;
                s = s + "M";
            }
            if (num >= 400) {
                if (num >= 500) {
                    if (num >= 900) {
                        s = s + "CM";
                        num = num - 900;
                    } else {
                        s = s + "D";
                        num = num - 500;
                    }
                } else {
                    s = s + "CD";
                    num = num-400;
                }
            }
            while (num >= 100) {
                num = num - 100;
                s = s + "C";
            }
            if (num >= 40) {
                if (num >= 50) {
                    if (num >= 90) {
                        s = s + "XC";
                        num = num - 90;
                    } else {
                        s = s + "L";
                        num = num - 50;
                    }
                } else {
                    s = s + "XL";
                    num = num-40;
                }
            }

            while (num >= 10) {
                num = num - 10;
                s = s + "X";
            }



            if (num >= 4) {
                if (num >= 5) {
                    if (num >= 9) {
                        s = s + "IX";
                        num = num - 9;
                    } else {
                        s = s + "V";
                        num = num - 5;
                    }
                } else {
                    s = s + "IV";
                    num = num-4;
                }
            }
            while (num >= 1) {
                num = num - 1;
                s = s + "I";
            }
        return s;
    }
};