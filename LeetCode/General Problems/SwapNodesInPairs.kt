/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */
class Solution {
    fun swapPairs(head: ListNode?): ListNode? {
        if(head == null) return null
        var newHead = head
        if(newHead != null && newHead.next != null){
            var ax : ListNode = newHead.next
            var bx : ListNode = newHead
            newHead = ax
            bx.next = newHead.next
            newHead.next = bx
        }
        var cur = newHead!!.next
        while(cur != null && cur.next != null && cur.next.next != null){

            var ax : ListNode = cur.next
            var axnxt : ListNode = ax.next
            cur.next = axnxt
            ax.next = cur.next.next
            cur.next.next = ax

            cur = cur.next.next
        }
        return newHead
    }
}
