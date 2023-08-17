/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start

//这个题目的思路是双指针，从两边开始，每次移动较小的那个指针，因为如果移动较大的那个指针，那么面积一定会变小
//因为移动较小的那个指针，有可能会找到更大的面积
//这个题目的时间复杂度是O(n)，空间复杂度是O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        // 定义左右指针，初始值为容器的左右两端
        int left = 0;
        int right = height.size() - 1;
        // 定义最大面积，初始值为容器左右两端组成的面积
        int max_area = min(height[left], height[right]) * (right - left);
        // 双指针法，每次移动较小的那个指针，直到两个指针相遇
        while (left != right) {
            // 计算当前指针所指位置的容器面积
            int area = min(height[left], height[right]) * (right - left);
            // 更新最大面积
            max_area = max(max_area, area);
            // 移动较小的那个指针
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        // 返回最大面积
        return max_area;
    }
};
// @lc code=end

