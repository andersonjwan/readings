struct ImportantExcerpt<'a> {
    part: &'a str,
}

fn main() {
    let s1 = String::from("abcd");
    let s2 = "xy1";

    let result = longest(s1.as_str(), s2);
    println!("The longest string is: {}", result);

    let s1 = String::from("long string is long");

    {
        let s2 = String::from("xyz");

        let result = longest(s1.as_str(), s2.as_str());
        println!("The longest string is... {}", result);
    }

    // Note: Invalid because `s2` does not live long enough.
    //
    // let s1 = String::from("long string is long");
    // let result;

    // {
    //     let s2 = String::from("xyz");

    //     result = longest(s1.as_str(), s2.as_str());
    // }

    // println!("The longest string is... {}", result);

    let novel = String::from("Call me Ishmael. Some years ago...");
    let first_sentence = novel.split('.').next().expect("could not find a '.'");

    let i = ImportantExcerpt {
        part: first_sentence,
    };

    longest_with_announcement("test", "testing", "this is my announcement");
}

fn longest<'a>(x: &'a str, y: &'a str) -> &'a str {
    if x.len() > y.len() {
        x
    } else {
        y
    }
}

use std::fmt::Display;

fn longest_with_announcement<'a, T>(x: &'a str, y: &'a str, announcement: T) -> &'a str
where
    T: Display,
{
    println!("Announcment: {}", announcement);

    if x.len() > y.len() {
        x
    } else {
        y
    }
}
