use std::ops::Deref;

struct MyBox<T>(T);

impl<T> MyBox<T> {
    fn new(x: T) -> MyBox<T> {
        MyBox(x)
    }
}

impl<T> Deref for MyBox<T> {
    type Target = T;

    fn deref(&self) -> &T {
        &self.0
    }
}

#[derive(Debug)]
struct MySmartPointer<T>
where
    T: std::fmt::Debug,
{
    data: T,
}

impl<T: std::fmt::Debug> Drop for MySmartPointer<T> {
    fn drop(&mut self) {
        println!("Dropping... {:?}", self);
    }
}

fn main() {
    let x = 5;
    let y = MyBox::new(x);

    assert_eq!(5, x);
    assert_eq!(5, *y);

    hello("Jacob");

    let m = MyBox::new(String::from("Rust"));
    hello(&m);

    let sp1 = MySmartPointer {
        data: String::from("testing..."),
    };
    let sp2 = MySmartPointer { data: 25.0 };

    // drop a variable early
    drop(sp1);

    println!("Smart pointers created...");
}

fn hello(s: &str) {
    println!("Hello, {}", s);
}
