/*
1. Two Sum

Given an array of integers nums and an integer target, 
return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, 
and you may not use the same element twice.
You can return the answer in any order.

給定一個整數數組 nums 和一個整數 target，
傳回兩個數字的索引，
使得它們加起來等於 target。
您可以假設每個輸入只有一個解決方案，
並且可能不會兩次使用相同的元素。
您可以按任意順序返回答案。

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 
Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

後續問題：你能想出一個時間複雜度小於 O(n2) 的演算法嗎？

*/

//時間複雜度小於 O(n2) 的演算法
/*
1. 归并排序（Merge Sort）

    时间复杂度: O(nlog⁡n)O(nlogn)
    归并排序是一个分治算法，将数组分成两半，递归排序每个半部分，然后合并排序后的半部分。
	归并排序的时间复杂度为 O(nlog⁡n)O(nlogn)，比 O(n2)O(n2) 快。

2. 快速排序（Quick Sort）

    时间复杂度: 最优 O(nlog⁡n)O(nlogn)，最坏 O(n2)O(n2)
    快速排序通过选取一个"枢轴"元素，将数组分成两个子数组，分别递归排序，然后将子数组合并。
	虽然最坏情况是 O(n2)O(n2)，但平均情况下时间复杂度是 O(nlog⁡n)O(nlogn)，
	因此通常认为它是一个 O(nlog⁡n)O(nlogn) 的算法。

3. 堆排序（Heap Sort）

    时间复杂度: O(nlog⁡n)O(nlogn)
    堆排序是通过堆这种数据结构来完成排序的。它先将数组构建成一个堆结构，
	然后将堆的根元素与数组的最后一个元素交换，调整堆结构，并重复此过程，直到整个数组排序完成。

4. 二分查找（Binary Search）

    时间复杂度: O(log⁡n)O(logn)
    二分查找是一种高效的查找算法，适用于已经排好序的数组。
	它每次将查找范围减半，因此时间复杂度是 O(log⁡n)O(logn)。

5. 线性查找（Linear Search）

    时间复杂度: O(n)O(n)
    线性查找是在数组中逐一遍历每个元素，直到找到目标元素。
	尽管它是 O(n)O(n)，但是对于某些情况（如找不到元素时），它仍然是最有效的算法。

6. Dijkstra 算法（Dijkstra's Algorithm）

    时间复杂度: O(E+Vlog⁡V)O(E+VlogV)
    Dijkstra 算法用于寻找图中的最短路径。使用堆优化后，时间复杂度可以达到 O(E+Vlog⁡V)O(E+VlogV)，
	其中 EE 是边的数量，VV 是顶点的数量。

7. KMP 字符串匹配算法（Knuth-Morris-Pratt Algorithm）

    时间复杂度: O(n+m)O(n+m)
    KMP 算法是一个高效的字符串匹配算法，它通过构建部分匹配表来避免不必要的比较，
	从而在匹配过程中避免回溯，时间复杂度为 O(n+m)O(n+m)，其中 nn 是文本长度，mm 是模式长度。

8. Floyd-Warshall 算法（Floyd-Warshall Algorithm）

    时间复杂度: O(n3)O(n3)
    尽管它的时间复杂度是 O(n3)O(n3)，但它也适用于某些特殊问题，尤其是在小规模图中计算所有节点对之间的最短路径时，
	比其他算法更有效。

*/

//vector  自動配置陣列的數目所以很更方便易用   連續的記憶體位址，取什麽元素都很快
//        元素不是保存在曡上(stack)而是在堆上(heap)，比較慢      因為是連續的所以要在中間加入或移除元素很難
//unordered_map  提供了一种基于哈希表的键值对容器   不保证元素的排序，但通常提供更快的查找速度   
//               存储了键值对（key-value pairs），其中每个键（key）都是唯一的
//

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> repeat;
        vector<int> ans;
        for(int i = 0;i < nums.size();++i){
            if(repeat.count(nums[i])){
                ans.push_back(repeat[nums[i]]);
                ans.push_back(i);
                break;
            }
            repeat[target - nums[i]] = i;
        }
        
        return ans;
    }
};

