#include <iostream>
using namespace std;

// ListNode structure
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0); // Dummy node to simplify code
    ListNode* tail = &dummy;
    
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    
    tail->next = l1 ? l1 : l2;
    
    return dummy.next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* createList(const vector<int>& nums) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int num : nums) {
        tail->next = new ListNode(num);
        tail = tail->next;
    }
    return dummy.next;
}

int main() {
    // Create two sorted lists
    vector<int> nums1 = {1, 3, 5};
    vector<int> nums2 = {2, 4, 6};
    
    ListNode* l1 = createList(nums1);
    ListNode* l2 = createList(nums2);
    
    cout << "List 1: ";
    printList(l1);
    cout << "List 2: ";
    printList(l2);
    
    // Merge the lists
    ListNode* merged = mergeTwoLists(l1, l2);
    
    cout << "Merged List: ";
    printList(merged);
    
    return 0;
}