/*
21. Merge Two Sorted Lists
    合併兩個排序列表

You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. 
The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

給出了兩個已排序鍊錶 list1 和 list2 的頭。
將兩個清單合併為一個排序清單。
此清單應透過將前兩個清單的節點拼接在一起來製作。
傳回合併鍊錶的頭。

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:
The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

約束： 兩個清單中的節點數都在 [0, 50] 範圍內。
-100 <= Node.val <= 100 list1 和 list2 皆依非降序排序。

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = new ListNode(-1);
        ListNode *cur = head;
        
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val <= list2->val){
                cur->next = list1;
                list1 = list1->next;
            }else{
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        
        if(list1 != nullptr) cur->next = list1;
        else if(list2 != nullptr) cur->next = list2;
        
        return head->next;
    }
};