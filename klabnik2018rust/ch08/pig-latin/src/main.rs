fn main() {
    let text = String::from("Hello Amazing Pig Latin World");

    println!("Original: {}", text);
    println!("Pigified: {}", pigify(&text));
}

fn pigify(text: &str) -> String {
    let vowels = ['a', 'e', 'i', 'o', 'u'];
    let mut pigified = String::new();

    for word in text.split_whitespace() {
        let mut chars = word.chars();

        let word = if vowels.contains(&chars.next().unwrap().to_ascii_lowercase()) {
            format!("{}-hay", word)
        } else {
            let mut s = String::new();
            for char in chars {
                s.push(char);
            }

            format!("{}-{}ay", s, word.chars().next().unwrap())
        };

        pigified.push_str(&word);
        pigified.push(' ');
    }

    pigified
}
