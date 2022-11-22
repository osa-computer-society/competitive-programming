use std::io;

fn find_max_crossing_subarray(arr: &Vec<i64>, left: usize, mid: usize, right: usize) -> (usize, usize, i64) {
    let mut left_sum: i64 = i64::MIN;
    let mut max_left: usize = 0;
    let mut sum: i64 = 0;
    for i in (left..mid+1).rev() {
        sum += arr[i];
        if sum > left_sum {
            left_sum = sum;
            max_left = i;
        }
    }

    let mut right_sum: i64 = i64::MIN;
    let mut max_right: usize = 0;
    let mut sum: i64 = 0;
    for i in mid+1..right+1 {
        sum += arr[i];
        if sum > right_sum {
            right_sum = sum;
            max_right = i;
        }
    }

    (max_left, max_right, left_sum + right_sum)
}

fn find_max_subarray(arr: &Vec<i64>, left: usize, right: usize) -> (usize, usize, i64) {
    if left == right {
        (left, right, arr[left])
    } else {
        let mid = (left + right) / 2;
        let (left_low, left_high, left_sum) = find_max_subarray(arr, left, mid);
        let (right_low, right_high, right_sum) = find_max_subarray(arr, mid+1, right);
        let (cross_low, cross_high, cross_sum) = find_max_crossing_subarray(arr, left, mid, right);
        if left_sum >= right_sum && left_sum >= cross_sum {
            (left_low, left_high, left_sum)
        } else if right_sum >= left_sum && right_sum >= cross_sum {
            (right_low, right_high, right_sum)
        } else {
            (cross_low, cross_high, cross_sum)
        }
    }
}

fn main() -> io::Result<()> {
    let arr = vec![0, 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7];
    let len = arr.len() - 1; // index at 1
    let (left, right, sum) = find_max_subarray(&arr, 1, len);
    println!("left: {}\nright: {}\nsum: {}\n", left, right, sum);
    Ok(())
}