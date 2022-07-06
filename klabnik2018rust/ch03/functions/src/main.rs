fn main() {
    println!("Hello, world!");
    another_fn(123);
    another_another_fn(1234, 12345);

    test_rust_expressions(10);

    println!("Calling `number_five` returns: {}", number_five());
    println!(
        "Calling `number_plus_one` on 10 returns: {}",
        number_plus_one(10)
    );
}

fn another_fn(x: i32) {
    println!("Another, function!");
    println!("The value of `x` is: {}", x);
}

fn another_another_fn(x: i32, y: i32) {
    println!("The value of `x` is: {}", x);
    println!("The value of `y` is: {}", y);
}

fn test_rust_expressions(x: i32) {
    let y = {
        let z = 5; // statement
        z + x // expression
    }; // statement (`let y = ...;`)

    println!("The value of `y` is: {}", y); // statement
}

fn number_five() -> i32 {
    5
}

fn number_plus_one(x: i32) -> i32 {
    x + 1
}
