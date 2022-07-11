// fn main() {
//     let width = 30;
//     let height = 50;

//     println!(
//         "The area of the rectangle is {} square pixels!",
//         area(width, height)
//     );
// }

// fn area(width: i32, height: i32) -> i32 {
//     width * height
// }

// fn main() {
//     let rect = (30, 50);

//     println!("The area of the rectangle is {} square pixels!", area(rect));
// }

// fn area(rectangle: (i32, i32)) -> i32 {
//     rectangle.0 * rectangle.1
// }

// struct Rectangle(i32, i32);

// fn main() {
//     let rect = Rectangle(30, 50);

//     println!("The area of the rectangle is {} square pixels!", area(rect));
// }

// fn area(r: Rectangle) -> i32 {
//     r.0 * r.1
// }

// #[derive(Debug)]
// struct Rectangle {
//     width: i32,
//     height: i32,
// }

// fn main() {
//     let rect = Rectangle {
//         width: 30,
//         height: 50,
//     };

//     println!("The rectangle is... {:#?}", rect);
//     println!("The area of the rectangle is {} square pixels", area(&rect));
// }

// fn area(rect: &Rectangle) -> i32 {
//     rect.width * rect.height
// }

// #[derive(Debug)]
// struct Rectangle {
//     width: u32,
//     height: u32,
// }

// impl Rectangle {
//     fn area(&self) -> u32 {
//         self.width * self.height
//     }
// }

// fn main() {
//     let rect = Rectangle {
//         width: 30,
//         height: 50,
//     };

//     println!("The rectangle is... {:#?}", rect);
//     println!(
//         "The area of the rectangle is {} square pixels!",
//         rect.area()
//     );
// }

#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    fn area(&self) -> u32 {
        self.width * self.height
    }

    fn can_hold(&self, other: &Rectangle) -> bool {
        self.width > other.width && self.height > other.height
    }
}

impl Rectangle {
    fn square(size: u32) -> Rectangle {
        Rectangle {
            width: size,
            height: size,
        }
    }
}

fn main() {
    let rects: [Rectangle; 3] = [
        Rectangle {
            width: 30,
            height: 50,
        },
        Rectangle {
            width: 10,
            height: 40,
        },
        Rectangle {
            width: 60,
            height: 45,
        },
    ];

    println!("The area of rects[0] is {}", rects[0].area());
    println!("The area of rects[1] is {}", rects[1].area());
    println!("The area of rects[2] is {}", rects[2].area());

    println!(
        "Can rects[0] hold rects[1]? {}",
        rects[0].can_hold(&rects[1])
    );
    println!(
        "Can rects[0] hold rects[2]? {}",
        rects[0].can_hold(&rects[2])
    );

    let sq = Rectangle::square(12);
    println!("The area of the square is {}", sq.area());
}
