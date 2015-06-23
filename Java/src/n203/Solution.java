package n203;

import common.ListNode;


public class Solution {

	public static void main(String[] args) {
	}

public ListNode removeElements(ListNode head, int val) {
        
	ListNode m = null,p=null;
	ListNode tmp;
	while(head != null && head.val == val) {
		tmp = head;
		head = head.next; 
		tmp.next = null;
	}
	
	if(head == null) return null;
	
	p = head;
	m = p.next;
	while( m!= null){
		if(m.val == val){
			p.next = m.next;
			tmp = m;
			m = m.next;
			tmp.next = null;
		}else{
			p = m;
			m = m.next;
		}
	}
	return head;
    }

}
