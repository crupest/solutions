use super::Solution;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        for (i, v1) in nums.iter().enumerate() {
            for (j, v2) in nums.iter().enumerate().skip(i + 1) {
                if v1 + v2 == target {
                    return vec![i as i32, j as i32];
                }
            }
        }
        panic!();
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    pub fn test() {
        assert_eq!(Solution::two_sum(vec![2, 7, 11, 15], 9), vec![0, 1])
    }
}