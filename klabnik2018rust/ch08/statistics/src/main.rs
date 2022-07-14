use std::collections::HashMap;

fn main() {
    let numbers: Vec<i32> = vec![10, 20, 20, 20, 30, 40, 50, 40];
    let numbers: Vec<i32> = Vec::new();

    match mean(&numbers) {
        Some(average) => println!("Mean: {}", average),
        None => println!("No numbers in list!"),
    }

    match median(&numbers) {
        Some(middle) => println!("Median: {}", middle),
        None => println!("No numbers in list!"),
    }

    match mode(&numbers) {
        Some(most) => println!("Most: {}", most),
        None => println!("No numbers in list!"),
    }
}

fn mean(nums: &Vec<i32>) -> Option<f64> {
    if nums.is_empty() {
        None
    } else {
        let mut sum: f64 = 0.0;

        for i in nums {
            sum += *i as f64;
        }

        Some(sum / (nums.len() as f64))
    }
}

fn median(nums: &Vec<i32>) -> Option<f64> {
    let mut nums = nums.clone();
    nums.sort();

    let size = nums.len();

    if size % 2 == 0 {
        match nums.get(size / 2) {
            Some(v1) => match nums.get((size / 2) - 1) {
                Some(v2) => Some(((*v1 + *v2) as f64) / 2.0),
                None => None,
            },
            None => None,
        }
    } else {
        match nums.get(size / 2) {
            Some(v) => Some(*v as f64),
            None => None,
        }
    }
}

fn mode(nums: &Vec<i32>) -> Option<i32> {
    let mut map = HashMap::new();

    for i in nums {
        let count = map.entry(*i).or_insert(0);
        *count += 1;
    }

    let mut max: Option<(i32, i32)> = None;

    for (num, count) in map.iter() {
        max = match max {
            None => Some((*num, *count)),
            Some(v) => {
                if v.1 < *count {
                    Some((*num, *count))
                } else {
                    Some(v)
                }
            }
        };
    }

    match max {
        Some(v) => Some(v.0),
        None => None,
    }
}
