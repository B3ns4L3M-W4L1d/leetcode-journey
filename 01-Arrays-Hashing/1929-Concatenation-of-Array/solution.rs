impl Solution {
    pub fn get_concatenation(nums: Vec<i32>) -> Vec<i32> {
        let mut numbers: Vec<i32> = vec![];
        let n = nums.len();

        for i in 0..n {
            numbers.push(nums[i])
        }
        for i in 0..n {
            numbers.push(nums[i])
        }
        numbers
    }
}