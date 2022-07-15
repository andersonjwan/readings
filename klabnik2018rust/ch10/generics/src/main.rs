// Note: This allows for a generic type that both `x` and `y` have to be.
//
// struct Point<T> {
//     x: T,
//     y: T,
// }

#[derive(Debug)]
struct Point<T, U> {
    x: T,
    y: U,
}

impl<T, U> Point<T, U> {
    fn x(&self) -> &T {
        &self.x
    }

    fn y(&self) -> &U {
        &self.y
    }
}

impl<T, U> Point<T, U> {
    fn mixup<V, W>(self, other: Point<V, W>) -> Point<T, W> {
        Point {
            x: self.x,
            y: other.y,
        }
    }
}

impl Point<f32, f32> {
    fn dist_from_origin(&self) -> f32 {
        (self.x.powi(2) + self.y.powi(2)).sqrt()
    }
}

impl<T, U> Point<T, U> {
    fn test(&self) {
        println!("test has been called...");
    }
}

fn main() {
    let numbers = vec![34, 50, 25, 100, 65];
    println!("The largest number is: {}", largest(&numbers));

    let characters = vec!['y', 'm', 'a', 'q'];
    println!("The largest character is: {}", largest(&characters));

    let integer = Point { x: 5, y: 10 };
    let float = Point { x: 5.0, y: 7.0 };

    let mix = Point { x: 5.0, y: 11 };

    let p1 = Point { x: "Hello", y: 5.0 };
    let p2 = Point { x: 7, y: 'm' };

    println!("Mixture: {:?}", p1.mixup(p2));
}

fn largest<T: std::cmp::PartialOrd + std::marker::Copy>(list: &[T]) -> T {
    let mut largest = list[0];

    for &item in list.iter() {
        if item > largest {
            largest = item;
        }
    }

    largest
}

// Note: Alternative definition of function with generic type Trait constraints
//
// fn largest<T>(list: &[T]) -> T
// where
//     T: std::cmp::PartialOrd + std::marker::Copy,
// {
//     let mut largest = list[0];

//     for &item in list.iter() {
//         if item > largest {
//             largest = item;
//         }
//     }

//     largest
// }

// Note: Alternative definition where list must implement clone.
//       This will now work with Strings, Vectors, etc.
//
// fn largest<T>(list: &[T]) -> T
// where
//     T: std::cmp::PartialOrd + std::clone::Clone,
// {
//     let mut largest = list[0].clone();

//     for &item in list.iter() {
//         if item > largest {
//             largest = item;
//         }
//     }

//     largest
// }

// Note: Alternative definition where list does not need to be cloned.
//       A reference to the item is now returned instead of a value.
//
// fn largest<T: std::cmp::PartialOrd>(list: &[T]) -> &T {
//     let mut largest = &list[0];

//     for &item in list.iter() {
//         if item > *largest {
//             largest = &item;
//         }
//     }

//     largest
// }
