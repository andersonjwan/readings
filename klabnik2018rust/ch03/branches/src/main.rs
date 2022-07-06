fn main() {
    let number = 3;

    if number < 5 {
        println!("Condition is True!");
    } else {
        println!("Condition is False!");
    }

    // multiple conditions (if-elseif-else); lazy evaluation
    if number % 5 == 0 {
        println!("The number is divisible by 5!"); // arm 1
    } else if number % 4 == 0 {
        println!("The number is divisible by 4!"); // arm 2
    } else {
        println!("The number is not divisible by 5 or 4!"); // arm 3
    }

    // if as an expression
    let condition = true;
    let number = if condition { 5 * 6 * 7 } else { 6 * 7 * 8 };

    println!("The value of `number` is: {}", number);

    // illegal if as expression
    // let condition = if condition { 6 + 10 } else { "True" };
    // println!("The value of `number` is: {}", number);
}
