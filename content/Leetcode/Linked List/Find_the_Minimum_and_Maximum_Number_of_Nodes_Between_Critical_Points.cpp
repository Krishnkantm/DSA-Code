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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // base case
        if (head == NULL || head->next == NULL) {
            return {-1, -1};
        }

        if (head->next->next == NULL) {
            return {-1, -1};
        }

      //Time => o(n)
      //space => O(1)
        ListNode* start = head;
        ListNode* mid = head->next;
        ListNode* end = head->next->next;

        int index = 2;

        int pre = -1;

        int mini = INT_MAX;

        int minIndex = INT_MAX;
        int maxIndex = INT_MIN;

        while (end != NULL) {
            if (mid->val < start->val && mid->val < end->val) {
                if (pre == -1) {
                    pre = index;
                } else {
                    mini = min(mini, index - pre);
                    pre = index;
                }

                minIndex = min(minIndex, index);
                maxIndex = max(maxIndex, index);
            }

            if (mid->val > start->val && mid->val > end->val) {
                if (pre == -1) {
                    pre = index;
                } else {
                    mini = min(mini, index - pre);
                    pre = index;
                }

                minIndex = min(minIndex, index);
                maxIndex = max(maxIndex, index);
            }

            index++;
            start = mid;
            mid = end;
            end = end->next;
        }

        if (mini == INT_MAX)
            return {-1, -1};

        int maxi = maxIndex - minIndex;
        return {mini, maxi};
    }
};
