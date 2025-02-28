/*
13. Roman to Integer
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

羅馬數字轉整數 
羅馬數字以七種不同的符號表示：I、V、X、L、C、D 和 M。

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, 2 is written as II in Roman numeral, just two ones added together. 
12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
Roman numerals are usually written largest to smallest from left to right. However, 
the numeral for four is not IIII. Instead, the number four is written as IV. 
Because the one is before the five we subtract it making four. 
The same principle applies to the number nine, which is written as IX. 

例如2在羅馬數字中寫為II，即兩個一相加。
12 寫成 XII，即 X + II。數字 27 寫作 XXVII，即 XX + V + II。
羅馬數字通常從左到右按從大到小的順序書寫。然而， 表示四的數字不是 IIII。相反，數字四寫為 IV。
因為一在五之前，所以我們減去一，得到四。
同樣的原理也適用於數字九，寫 IX。

There are six instances where subtraction is used:
I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

Example 1:
Input: s = "III"
Output: 3
Explanation: III = 3.

Example 2:
Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Example 3:
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 
Constraints:
1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].
*/
class Solution {
public:
    int romanToInt(string s) {
         unordered_map<char, int> c = {{'I', 1},{'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D',500},{'M',1000}};
        int result = 0;
        for(int i=0;i<s.size();i++){
            if(i==0||c[s[i]] <= c[s[i - 1]]) 
                result += c[s[i]];
            else
                result += c[s[i]]-2*c[s[i-1]];
        }
        return result;
    }
};