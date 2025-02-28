/*
9. Palindrome Number
9.回文數

Given an integer x, return true if x is a palindrome, and false otherwise.
給定一個整數 x，如果 x 是回文，則傳回 true，否則傳回 false。

Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

Constraints:
-231 <= x <= 231 - 1
 
Follow up: Could you solve it without converting the integer to a string?
跟進：如果不將整數轉換為字串，你能解決這個問題嗎？

*/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        
        vector<int> v;
        while(x!=0)
        {
            v.push_back(x%10);
            x/=10;
        }
        for(int i = 0;i<v.size()/2;i++)
        {
            if(v[i]!=v[v.size()-i-1])
                return false;
        }
        return true;
    }
};