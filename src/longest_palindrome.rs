use super::Solution;

impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        let bytes = s.as_bytes();
        let len = bytes.len();

        return match len {
            0 => "".to_string(),
            1 => s,
            _ => {
                let mut max_length = 1;
                let mut result = &bytes[0..1];

                for i in 1..len {
                    let mut left_iter = bytes[..i].iter().enumerate().rev();
                    let mut odd_right_iter = bytes.iter().enumerate().skip(i + 1);
                    let mut even_right_iter = bytes.iter().enumerate().skip(i);
                    let mut count_odd = true;
                    let mut count_even = true;
                    while count_odd || count_even {
                        match left_iter.next() {
                            Some((index_left, left)) => {
                                if count_odd {
                                    match odd_right_iter.next() {
                                        Some((index_right, right)) => {
                                            if right == left {
                                                let length = index_right - index_left + 1;
                                                if length > max_length {
                                                    max_length = length;
                                                    result = &bytes[index_left..index_right + 1];
                                                }
                                            } else {
                                                count_odd = false;
                                            }
                                        }
                                        None => count_odd = false,
                                    }
                                }
                                if count_even {
                                    match even_right_iter.next() {
                                        Some((index_right, right)) => {
                                            if right == left {
                                                let length = index_right - index_left + 1;
                                                if length > max_length {
                                                    max_length = length;
                                                    result = &bytes[index_left..index_right + 1];
                                                }
                                            } else {
                                                count_even = false;
                                            }
                                        }
                                        None => count_even = false,
                                    }
                                }
                            }
                            None => break,
                        }
                    }
                }
                String::from_utf8(Vec::from(result)).unwrap()
            }
        };
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn test() {
        assert_eq!(
            Solution::longest_palindrome("bb".to_string()),
            "bb".to_string()
        );
        assert_eq!(
            Solution::longest_palindrome("abb".to_string()),
            "bb".to_string()
        );
        assert_eq!(
            Solution::longest_palindrome("abbc".to_string()),
            "bb".to_string()
        );
        assert_eq!(
            Solution::longest_palindrome("abccb".to_string()),
            "bccb".to_string()
        );
        assert_eq!(
            Solution::longest_palindrome("abcdcbd".to_string()),
            "bcdcb".to_string()
        );
        assert_eq!(
            Solution::longest_palindrome("aaaabaaa".to_string()),
            "aaabaaa".to_string()
        );
    }
}
