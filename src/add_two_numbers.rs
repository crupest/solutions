use super::Solution;

/******************** provided code ********************/
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

/******************** my code ********************/

use std::ptr::NonNull;

struct List {
    head: Option<Box<ListNode>>,
    tail: NonNull<Option<Box<ListNode>>>,
}

impl List {
    fn new() -> List {
        let mut result = List {
            head: None,
            tail: NonNull::dangling(),
        };
        result.tail = NonNull::from(&mut result.head);
        return result;
    }

    fn append(&mut self, val: i32) {
        let node = Some(Box::new(ListNode::new(val)));
        unsafe {
            match self.tail.as_mut() {
                None => {
                    self.head = node;
                    self.tail = NonNull::from(&mut self.head);
                }
                Some(t) => {
                    t.next = node;
                    self.tail = NonNull::from(&mut t.next);
                }
            }
        }
    }

    fn to_result(self) -> Option<Box<ListNode>> {
        self.head
    }
}

impl Solution {
    pub fn add_two_numbers(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut l1 = l1;
        let mut l2 = l2;
        let mut result = List::new();
        let mut carry = false;

        loop {
            match l1 {
                None => {
                    while let Some(v) = l2 {
                        let digit = v.val + if carry { 1 } else { 0 };
                        carry = digit > 9;
                        let digit = digit % 10;
                        result.append(digit);
                        l2 = v.next;
                    }
                    break;
                }
                Some(v1) => match l2 {
                    None => {
                        let digit = v1.val + if carry { 1 } else { 0 };
                        carry = digit > 9;
                        let digit = digit % 10;
                        result.append(digit);
                        l1 = v1.next;
                        while let Some(v) = l1 {
                            let digit = v.val + if carry { 1 } else { 0 };
                            carry = digit > 9;
                            let digit = digit % 10;
                            result.append(digit);
                            l1 = v.next;
                        }
                        break;
                    }
                    Some(v2) => {
                        let digit = v1.val + v2.val + if carry { 1 } else { 0 };
                        carry = digit > 9;
                        let digit = digit % 10;
                        result.append(digit);
                        l1 = v1.next;
                        l2 = v2.next;
                    }
                },
            }
        }

        if carry {
            result.append(1);
        }

        return result.to_result();
    }
}

#[cfg(test)]
mod test {
    use super::{List, ListNode, Solution};

    trait IntoList {
        fn into_list(self) -> Option<Box<ListNode>>;
    }

    trait IntoVec {
        fn into_vec(self) -> Vec<i32>;
    }

    impl IntoList for Vec<i32> {
        fn into_list(self) -> Option<Box<ListNode>> {
            let mut list = List::new();
            for i in self {
                list.append(i);
            }
            list.to_result()
        }
    }

    impl IntoVec for Option<Box<ListNode>> {
        fn into_vec(self) -> Vec<i32> {
            let mut result = Vec::new();
            let mut node = self;
            while let Some(v) = node {
                result.push(v.val);
                node = v.next;
            }
            result
        }
    }

    #[test]
    fn test() {
        assert_eq!(
            Solution::add_two_numbers(vec![2, 4, 3].into_list(), vec![5, 6, 4].into_list()).into_vec(),
            vec![7, 0, 8]
        );
        assert_eq!(
            Solution::add_two_numbers(vec![9, 9, 9].into_list(), vec![1].into_list()).into_vec(),
            vec![0, 0, 0, 1]
        );
    }
}
