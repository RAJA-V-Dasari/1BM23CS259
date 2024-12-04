/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
     
    if (head == NULL || head->next == NULL) {
    return true;
}

    int size = 0;
    struct ListNode* temp = head;
    while (temp) {
        size++;
        temp = temp->next;
    }

    int* values = (int*)malloc(size * sizeof(int));
    temp = head;
    for (int i = 0; i < size; i++) {
        values[i] = temp->val;
        temp = temp->next;
    }

    int start = 0, end = size - 1;
    while (start < end) {
        if (values[start] != values[end]) {
            free(values); 
            return false;
        }
        start++;
        end--;
    }

    free(values); // Clean up memory.
    return true;
}
