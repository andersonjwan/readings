const MAX_POINTS: u32 = 100000;

fn main() {
    let mut x = 5;
    println!("The value of variable `x` is: {}", x);

    x = 6;
    println!("The value of variable `x` is: {}", x);
    println!("The constant value `MAX_POINTS` is: {}", MAX_POINTS);

    let y = "abc"; // shadowed
    println!("The value of variable `y` is: {}", y);

    let y = "xyz"; // shadowing, shadowed
    println!("The value of variable `y` is: {}", y);

    let y = 32; // shadowing, shadowed
    println!("The value of variable `y` is: {}", y);

    let y = y * 2; // shadowing
    println!("The value of variable `y` is: {}", y);

    // valid shadowing
    let spaces = "    ";
    let spaces = spaces.len();

    println!("The number of spaces is: {}", spaces);
    // invalid shadowing
    // let spaces = "    ";
    // spaces = spaces.len();
}
