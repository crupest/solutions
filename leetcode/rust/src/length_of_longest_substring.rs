use super::Solution;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut map: [i32; std::u8::MAX as usize] = [-1; std::u8::MAX as usize];
        let mut last_index: i32 = 0;
        let mut result: i32 = 0;
        let bytes = s.as_bytes();
        for (i, c) in bytes.iter().enumerate() {
            let i = i as i32;
            let c = *c as usize;
            let li = map[c];
            if li >= last_index {
                last_index = li + 1;
                map[c] = i;
            } else {
                map[c] = i;
                let length = i - last_index + 1;
                if length > result {
                    result = length;
                }
            }
        }
        result
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
