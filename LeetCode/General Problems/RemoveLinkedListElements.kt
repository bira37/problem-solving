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
    fun removeElements(head: ListNode?, `val`: Int): ListNode? {
        var aux = ListNode(-1)
        var cur = head
        
        var headAux = aux
        
        while(cur != null){
            if(cur.`val` != `val`){
                headAux.next = ListNode(cur.`val`)
                headAux = headAux.next
                headAux.next = null
            }
            cur = cur.next
        }
        return aux.next
    }
}
