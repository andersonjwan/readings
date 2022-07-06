fn main() {
    let x: i8 = -128;
    println!("The value of `x` is: {}", x);

    let x: i16 = 2346;
    println!("The value of `x` is: {}", x);

    let x: i32 = -23438293;
    println!("The value of `x` is: {}", x);

    let x: i64 = -828288234324;
    println!("The value of `x` is: {}", x);

    let x: i128 = 2143214321423423;
    println!("The value of `x` is: {}", x);

    let x: i32 = 0xF;
    println!("The value of `x` is: {}", x);

    let x: i64 = -0o77;
    println!("The value of `x` is: {}", x);

    let x: i8 = -0b10000000;
    println!("The value of `x` is: {}", x);

    // floating-point numbers
    let x = 2.0;
    let y: f32 = 3.0;

    // numeric operations
    let x = x + 5.0; // addition
    let y = y - x; // subtraction
    let y = 7.0 * y; // multiplication
    let x = y / 2.0; // division
    let y = y % 3.0; // modulo (remainder)

    println!("The value of `x` is: {}", x);
    println!("The value of `x` is: {}", y);

    // booleans
    let xflag: bool = false;
    let yflag = true;

    println!("The `xflag` is: {}", xflag);
    println!("The `yflag` is: {}", yflag);

    // characters
    let c = 'z';
    let z = 'Ƶ';
    let rust_crab_char = '🦀';

    println!(
        "The following letters have been defined: {}, {}, {}",
        c, z, rust_crab_char
    );

    // tuples
    let tup: (i32, f64, u8) = (500, 6.4, 2);
    let (x, y, z) = tup; // destructuring

    println!("The value of the tuple is: ({}, {}, {})", x, y, z);
    println!(
        "The value of the second member in the tuple, `tup`, is: {}",
        tup.1
    );

    // arrays
    let arr = [1, 2, 3, 4];
    let months = [
        "Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec",
    ];

    let type_hinted_arr: [i8; 3] = [1, 3, 5];
    let initialized_arr = [5; 3];

    println!("arr[0]: {}", arr[0]);
    println!("months[10]: {}", months[10]);
    println!("type_hinted_arr[2]: {}", type_hinted_arr[2]);
    println!("initialized_arr[1]: {}", initialized_arr[1]);

    // println!("Out-of-bounds access... {}", arr[5]);
}
