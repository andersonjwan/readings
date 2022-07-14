use std::ops::Add;

#[allow(unused_variables)]
fn main() {
    let s = String::new();

    let data = "string literal";
    let s = data.to_string();
    let mut s = String::from("string literal");

    s += " are cool";

    let mut s = String::from("foo");
    s.push_str("bar");

    println!("The resulting string is {}", s);

    let mut msg = String::from("LO");
    msg.push('L');

    println!("The resulting message is {}", msg);

    let s1 = String::from("Hello");
    let s2 = String::from(", World!");

    let s3 = s1 + &s2; // `s3` takes ownership of `s1` but not `s2`
    println!("s1: {{}}, s2: {}, s3: {}", s2, s3);

    let s3 = s3.add(" Hello, Again!");
    println!("s3: {}", s3);

    let s1 = String::from("tic");
    let s2 = String::from("tac");
    let s3 = String::from("toe");

    let s = format!("{}-{}-{}", s1, s2, s3);
    println!("s: {}, s1: {}, s2: {}, s3: {}", s, s1, s2, s3);
}
