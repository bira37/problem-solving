/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode MergeKLists(ListNode[] lists) {
        ListNode head = new ListNode(-1);
        ListNode cur = head;
        while(true){
            int mn = -1;
            for(int i=0; i<lists.Length; i++){
                if(lists[i] == null) continue;
                if(mn == -1) mn = i;
                else if(lists[mn].val > lists[i].val){
                    mn = i;
                }
            }
            if(mn == -1) break;
            cur.next = new ListNode(lists[mn].val);
            lists[mn] = lists[mn].next;
            cur = cur.next;
        }
        return head.next;
    }
}
