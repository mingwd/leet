class Solution {
   public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        int str1Length = str1.length();
        int str2Length = str2.length();

        int GCD = findGCD(str1Length, str2Length);
        return str1.substr(0, GCD);
    }

   private:
    int findGCD(int a, int b) {  // 最大公约数
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};