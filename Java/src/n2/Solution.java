package n2;

public class Solution {
	
	public static void main(String[]grgv){
		System.out.print("OK");
	}
	
	
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        /*
         * You are given two linked lists representing 
         * two non-negative numbers. The digits are stored 
         * in reverse order and each of their nodes contain 
         * a single digit. Add the two numbers and return it 
         * as a linked list.
         * */
    	if(l1 == null  && l2 == null ) return null;
    	
    	ListNode head = null,tail = null, p = null;
    	
    	int n1,n2, carry = 0, sum;
    	while(l1 != null || l2 != null){
    		n1 = n2 = 0;
    		if(l1 != null){
    			n1 = l1.val;
    			l1 = l1.next;
    		}
    		
    		if(l2 != null){
    			n2 = l2.val;
    			l2 = l2.next;
    		}
    		sum = n1 + n2 + carry;
    		carry = sum/10;
    		System.out.println(sum + " " + carry);
    		
    		p = new ListNode(sum % 10);
    		
    		if(head == null){
    			head = tail = p;
    		}else{
    			tail = tail.next = p;
    		}
    		
    	}
    	
    	System.out.println(carry);
    	if(carry != 0){
    		tail.next = new ListNode(carry);
    	}
    	return head;
    }
}