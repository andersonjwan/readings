fn main() {
    let mut s = String::from("slices are cool");

    let word = first_word(&s);
    s.clear();

    // word still retains the index of the first word
    println!("word: {}", word);

    // introduction of slices
    let s = String::from("Hello, Slice"); // shadowing

    let hello = &s[0..5];
    let slice = &s[7..12];

    println!("({}, {})", hello, slice);

    let hello = &s[..5];
    let slice = &s[7..];
    println!("({}, {})", hello, slice);

    let s = String::from("slices are cool");

    let word = first_word_fixed(&s);
    println!("word: {}", word);

    let word = second_word(&s);
    println!("word: {}", word);

    let s = String::from("String String");
    let ss = "Literal String";

    println!("{}", first_word_fixed_fixed(&s[..]));
    println!("{}", first_word_fixed_fixed(&ss[..]));
    println!("{}", first_word_fixed_fixed(ss));
}

fn first_word(s: &String) -> usize {
    let bytes = s.as_bytes();

    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return i;
        }
    }

    s.len()
}

fn first_word_fixed(s: &String) -> &str {
    let bytes = s.as_bytes();

    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[..i];
        }
    }

    &s[..]
}

fn second_word(s: &String) -> &str {
    let bytes = s.as_bytes();

    let mut counter: usize = 0;
    let mut start: usize = 0;

    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            if counter == 0 {
                start = i + 1;
                counter += 1;
            } else if counter == 1 {
                return &s[start..i];
            }
        }
    }

    &s[..]
}

fn first_word_fixed_fixed(s: &str) -> &str {
    let bytes = s.as_bytes();

    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[..i];
        }
    }

    s
}
