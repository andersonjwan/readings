// Note: Duplicate code raises the potential for error.
//
// fn main() {
//     let numbers = vec![34, 50, 25, 100, 65];

//     let mut largest = numbers[0];
//     for number in numbers {
//         if number > largest {
//             largest = number;
//         }
//     }

//     println!("The largest value is: {}", largest);

//     let numbers = vec![102, 34, 6000, 89, 54, 2, 43, 8];

//     let mut largest = numbers[0];
//     for number in numbers {
//         if number > largest {
//             largest = number;
//         }
//     }

//     println!("The largest value is: {}", largest);
// }

fn main() {
    let numbers = vec![34, 50, 25, 100, 65];
    println!("The largest value is: {}", largest(&numbers));

    let numbers = vec![102, 34, 6000, 89, 54, 2, 43, 8];
    println!("The largest value is: {}", largest(&numbers));
}

fn largest(nums: &[i32]) -> i32 {
    let mut largest = nums[0];

    for &item in nums.iter() {
        if item > largest {
            largest = item;
        }
    }

    largest
}
