enum Cell {
    Int(i32),
    Float(f64),
    Text(String),
}

#[allow(unused_variables)]
fn main() {
    let v: Vec<i32> = Vec::new();
    let v = vec![1, 2, 3];

    let mut v = Vec::new();
    v.push(1);
    v.push(2);
    v.push(3);
    v.push(4);
    v.push(5);

    let third = &v[2];
    println!("The third element is: {}", third);

    match v.get(2) {
        Some(third) => println!("The third element is definitely: {}", third),
        None => println!("A third element does not exist."),
    }

    let first = &v[0];
    v.push(6);

    // println!("The first element is {}", first); // invalid because we modify the contents of `v` after

    // iterating through vectors
    for i in &v {
        println!("{}", i);
    }

    for i in &mut v {
        *i += 10;
        println!("{}", i);
    }

    for i in &v {
        println!("{}", i);
    }

    let row = vec![
        Cell::Int(31),
        Cell::Float(7.0),
        Cell::Text(String::from("message...")),
        Cell::Float(45.0),
    ];
}
