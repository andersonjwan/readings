use std::rc::Rc;

#[derive(Debug)]
enum List<T> {
    Cons(T, Rc<List<T>>),
    Nil,
}

#[allow(unused_variables)]
fn main() {
    let a = Rc::new(List::Cons(5, Rc::new(List::Cons(10, Rc::new(List::Nil)))));
    println!("Count of `a` is: {}", Rc::strong_count(&a));

    let b = Rc::new(List::Cons(3, Rc::clone(&a)));
    println!("Count of `a` is: {}", Rc::strong_count(&a));

    {
        let c = Rc::new(List::Cons(4, Rc::clone(&a)));
        println!("Count of `a` is: {}", Rc::strong_count(&a));
    }

    println!("a: {:?}", a);
    println!("b: {:?}", b);
    println!("Count of `a` is: {}", Rc::strong_count(&a));
}
