use super::Solution;

impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let (len_a, len_b) = (nums1.len(), nums2.len());
        let (a, len_a, b, len_b) = if len_a <= len_b {
            (nums1, len_a, nums2, len_b)
        } else {
            (nums2, len_b, nums1, len_a)
        };
        let index_sum = (a.len() + b.len() + 1) / 2;
        let (mut i_min, mut i_max) = (0, len_a);

        while i_min != i_max {
            let i = (i_min + i_max) / 2;
            let j = index_sum - i;
            if j != 0 && a[i] < b[j - 1] {
                i_min = i + 1;
            } else {
                i_max = i;
            }
        }

        let i = i_min;
        let j = index_sum - i;

        let mut v = vec![];
        if i != 0 {
            v.push(a[i - 1]);
        }
        if j != 0 {
            v.push(b[j - 1]);
        }
        if i != len_a {
            v.push(a[i]);
        }
        if j != len_b {
            v.push(b[j]);
        }
        v.sort_unstable();

        if (len_a + len_b) % 2 == 0 {
            match v.len() {
                2 => (v[0] as f64 + v[1] as f64) / 2.0,
                3 => {
                    if i == 0 {
                        (v[0] as f64 + v[1] as f64) / 2.0
                    } else {
                        (v[1] as f64 + v[2] as f64) / 2.0
                    }
                }
                4 => (v[1] as f64 + v[2] as f64) / 2.0,
                _ => panic!(),
            }
        } else {
            match v.len() {
                1 | 2 => v[0] as f64,
                3 => {
                    if i == 0 {
                        v[0] as f64
                    } else {
                        v[1] as f64
                    }
                }
                4 => v[1] as f64,
                _ => panic!(),
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn test() {
        assert_eq!(Solution::find_median_sorted_arrays(vec![3], vec![]), 3.0);
        assert_eq!(Solution::find_median_sorted_arrays(vec![3], vec![4]), 3.5);
        assert_eq!(
            Solution::find_median_sorted_arrays(vec![3, 4, 5], vec![1, 2, 6]),
            3.5
        );
        assert_eq!(
            Solution::find_median_sorted_arrays(vec![3, 4], vec![1, 2, 6]),
            3.0
        );
        assert_eq!(
            Solution::find_median_sorted_arrays(vec![1], vec![2, 3, 4]),
            2.5
        );
        assert_eq!(
            Solution::find_median_sorted_arrays(vec![4], vec![1, 2, 3, 5]),
            3.0
        );
        assert_eq!(
            Solution::find_median_sorted_arrays(vec![1, 2, 3], vec![4, 5, 6]),
            3.5
        );
    }
}
