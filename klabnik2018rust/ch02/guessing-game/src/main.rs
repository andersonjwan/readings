use rand::Rng;
use std::cmp::Ordering;
use std::io;

fn main() {
    println!("Guess the number!");

    let answer = rand::thread_rng().gen_range(1..=100);

    loop {
        // guess prompting
        println!("Please input your guess...");

        let mut guess = String::new();
        io::stdin()
            .read_line(&mut guess) // returns an `std::io::Result`
            .expect("Failed to read line"); // will panic if the return type is `Err`

        let guess: u32 = match guess.trim().parse::<u32>() {
            // `parse(...)` returns a `Result` type that needs to be matched
            Ok(num) => num,
            Err(_) => continue,
        };

        println!("You guessed: {}", guess);

        // match guess against answer
        match guess.cmp(&answer) {
            Ordering::Less => println!("Too small. Try again!"),
            Ordering::Greater => println!("Too big. Try again!"),
            Ordering::Equal => {
                println!("Congrats. You win!");
                break;
            }
        }
    }
}
