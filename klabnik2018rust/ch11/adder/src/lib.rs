#[derive(Debug)]
pub struct Rectangle {
    length: u32,
    width: u32,
}

impl Rectangle {
    pub fn can_hold(&self, other: &Rectangle) -> bool {
        self.length > other.length && self.width > other.width
    }
}

pub fn add_two(x: i32) -> i32 {
    x + 2
}

pub fn greeting(name: &str) -> String {
    format!("Hello, {}", name)
}

pub struct Guess {
    value: i32,
}

impl Guess {
    pub fn new(value: i32) -> Guess {
        if value < 1 {
            panic!(
                "Guess value must be greater than or equal to 1. Received {}",
                value
            );
        } else if value > 100 {
            panic!(
                "Guess value must be less than or equal to 100. Received {}",
                value
            );
        }

        Guess { value }
    }
}

#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        let result = 2 + 2;
        assert_eq!(result, 4);
    }

    #[test]
    #[ignore]
    fn it_doesnt_work() {
        panic!("This test fails...");
    }

    #[test]
    fn larger_can_hold_smaller() {
        let larger = crate::Rectangle {
            length: 8,
            width: 7,
        };
        let smaller = crate::Rectangle {
            length: 4,
            width: 3,
        };

        assert!(larger.can_hold(&smaller));
    }

    #[test]
    fn smaller_cannot_hold_larger() {
        let larger = crate::Rectangle {
            length: 8,
            width: 7,
        };
        let smaller = crate::Rectangle {
            length: 4,
            width: 3,
        };

        assert!(!smaller.can_hold(&larger));
    }

    #[test]
    fn it_adds_two() {
        assert_eq!(4, crate::add_two(2));
    }

    #[test]
    fn greeting_contains_name() {
        let result = crate::greeting("Jacob");
        assert!(
            result.contains("Jacob"),
            "Greeting did not contain name. Value was: {}",
            result
        );
    }

    #[test]
    #[should_panic(expected = "Guess value must be less than or equal to 100.")]
    fn greater_than_100() {
        crate::Guess::new(200);
    }

    #[test]
    fn it_works_works() -> Result<(), String> {
        if 2 + 2 == 4 {
            Ok(())
        } else {
            Err(String::from("two plus two does not equal four"))
        }
    }
}
