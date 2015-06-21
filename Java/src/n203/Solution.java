package n203;

import common.ListNode;


public class Solution {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ListNode *
	}

public ListNode removeElements(ListNode head, int val) {
        
	ListNode m = null,p=null;
	
	while(head != null && head.val == val) head = head.next; 
	
	if(head == null) return null;
	
	p = head;
	m = p.next;
	while( m!= null){
		if(m.val == val) p.next = m = m.next; 
	}
	return head;
    }

}
