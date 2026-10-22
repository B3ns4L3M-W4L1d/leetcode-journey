function getConcatenation(nums: number[]): number[] {

    const array: number[] = [];
    let n = nums.length;

    for (let i = 0; i < n; i++){
        array[i] = nums[i];
    }
    for (let i = 0; i < n; i++){
        array[i + n] = nums[i];
    }
    return array;
};