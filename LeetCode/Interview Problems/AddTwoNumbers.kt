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
    fun addTwoNumbers(l1: ListNode?, l2: ListNode?): ListNode? {
        var head : ListNode? = null
        var p1 = l1
        var p2 = l2
        var acc = 0
        var cur = head
        while(p1 != null || p2 != null || acc > 0){
            var sum = 0
            if(p1 != null){
                sum += p1.`val`
                p1 = p1.next
            }
            if(p2 != null){
                sum += p2.`val`
                p2 = p2.next
            }
            if(head != null) {
                head.next = ListNode((sum + acc)%10)
                head = head.next
            }
            else {
                head = ListNode((sum + acc)%10)
                cur = head
            }
            acc = (sum+acc)/10
        }
        return cur
    }
}
