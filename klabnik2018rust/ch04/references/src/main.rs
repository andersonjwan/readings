fn main() {
    let mut s = String::from("Hello, References!");
    println!("(\"{}\", {})", s, strlen(&s));

    println!(
        "(\"{}\", {})",
        String::from("Testing"),
        strlen(&String::from("Testing"))
    );

    modify_str(&mut s);
    println!("(\"{}\", {})", s, strlen(&s));

    // failure
    // let r1 = &mut s;
    // let r2 = &mut s; // cannot borrow and use mutable `s` more than once

    // modify_str(r1);
    // modify_str(r2);

    println!("{}", dangle_fixed());
}

fn strlen(s: &String) -> usize {
    s.len()
}

fn modify_str(s: &mut String) {
    s.push_str("_modified_2");
}

// fn dangle() -> &String {
//     let s = String::from("This is dangling?");
//     &s
// }

fn dangle_fixed() -> String {
    let s = String::from("This is dangling?");
    s
}
