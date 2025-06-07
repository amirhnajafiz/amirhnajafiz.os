// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn rotate_right(mut head: Option<Box<ListNode>>, k: i32) -> Option<Box<ListNode>> {
        assert!(k >= 0);

        // find length of list
        let mut len = 0;

        let mut node_ref = head.as_ref();
        while let Some(node) = node_ref {
            len += 1;
            node_ref = node.next.as_ref();
        }

        if len == 0 {
            return head;
        }

        let k = k % len;
        if k == 0 {
            return head;
        }

        let mut node_ref = head.as_deref_mut().unwrap();
        for _ in 0..(len - k - 1) {
            node_ref = node_ref.next.as_deref_mut().unwrap();
        }

        let mut new_head = node_ref.next.take().unwrap();

        // find the end of new_head and connect it to old head
        node_ref = new_head.as_mut();
        while node_ref.next.is_some() {
            node_ref = node_ref.next.as_deref_mut().unwrap();
        }

        node_ref.next = head;

        Some(new_head)
    }
}
