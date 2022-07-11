fn main() {
    string_literal();
    string_string();
    move_example();

    let s = String::from("Hello");
    take_ownership(s);

    // println!("main: s: {}", s);

    let s1 = gives_ownership();
    let s2 = String::from("main: hello");
    let s3 = takes_and_gives_ownership(s2);

    println!("main: s1: {}", s1);
    // println!("main: s2: {}", s2); // `s2` is invalidated at this point
    println!("main: s3: {}", s3);

    let x = 10;
    let y = copies_and_returns(x);

    println!("main: x: {}", x);
    println!("main: y: {}", y);

    let (s4, size) = str_len(s3);
    println!("main: s4: {}, len: {}", s4, size);
}

fn string_literal() {
    // `s` is not valid at this point
    let s = "Hello"; // `s` is valid from this point onwards
    println!("string_literal: s: {}", s);
} // `s` is not valid after this scope

fn string_string() {
    // `s` is not valid at this point
    let mut s = String::from("Hello"); // `s` is valid from this point onwards
    s.push_str(", World!");

    println!("string_string: s: {}", s);
} // `s` is not valid after this scope

fn move_example() {
    let x = 5;
    let y = x;

    let s1 = String::from("Hello");
    let s2 = s1;

    //println!("s1: {}", s1); // `s1` is considered invalid at this
    // point (i.e., its data has been moved)

    println!("move_example: x: {}", x);
    println!("move_example: y: {}", y);
    println!("move_example: s2: {}", s2);

    let s1 = String::from("Hello");
    let s2 = s1.clone();

    println!("move_example: s1: {}, s2: {}", s1, s2);
}

fn take_ownership(s: String) {
    println!("take_ownership: s: {}", s);
}

fn gives_ownership() -> String {
    String::from("Helloo")
}

fn takes_and_gives_ownership(a_string: String) -> String {
    a_string
}

fn copies_and_returns(num: i32) -> i32 {
    num
}

fn str_len(s: String) -> (String, usize) {
    let length = s.len();
    (s, length)
}
