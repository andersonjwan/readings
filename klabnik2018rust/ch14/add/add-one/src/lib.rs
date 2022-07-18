#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        let result = 2 + 2;
        assert_eq!(result, 4);
    }

    #[test]
    fn add_one_to_three() {
        assert_eq!(4, super::add_one(3));
    }
}

pub fn add_one(x: i32) -> i32 {
    x + 1
}
