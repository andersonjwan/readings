fn main() {
    let mut number: u32 = 0;

    while number <= 20 {
        println!("F({}) = {}", number, fibonacci(number));
        number += 1;
    }
}

fn fibonacci(number: u32) -> u32 {
    if number == 0 || number == 1 {
        number
    } else {
        fibonacci(number - 1) + fibonacci(number - 2)
    }
}
