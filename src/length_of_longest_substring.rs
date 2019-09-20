use super::Solution;

use std::collections::HashMap;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut map = HashMap::new();
        let mut last_index = 0;
        let mut result = 0;
        let bytes = s.as_bytes();
        for (i, c) in bytes.iter().enumerate() {
            match map.get(&c) {
                Some(vi) if *vi >= last_index => {
                    last_index = *vi + 1;
                    map.insert(c, i);
                }
                _ => {
                    map.insert(c, i);
                    let length = i - last_index + 1;
                    if length > result {
                        result = length;
                    }
                }
            }
        }
        result as i32
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn test() {
        assert_eq!(
            Solution::length_of_longest_substring("abcabcbb".to_string()),
            3
        );
        assert_eq!(
            Solution::length_of_longest_substring("bbbbb".to_string()),
            1
        );
        assert_eq!(
            Solution::length_of_longest_substring("pwwkew".to_string()),
            3
        );
    }
}
