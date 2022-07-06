const DAYS_OF_CHRISTMAS: usize = 12;

fn main() {
    let gifts = [
        "A partridge in a pear tree",
        "Two turtledoves",
        "Three French hens",
        "Four calling birds",
        "Five gold rings (five golden rings)",
        "Six geese a-laying",
        "Seven swans a-swimming",
        "Eight maids a-milking",
        "Nine ladies dancing",
        "Ten lords a-leaping",
        "Eleven pipers piping",
        "Twelve drummers drumming",
    ];

    let days = [
        "first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth", "ninth",
        "tenth", "eleventh", "twelfth",
    ];

    let mut day = 0;

    while day < DAYS_OF_CHRISTMAS {
        transition_lyric(days[day]);

        for counter in (0..(day + 1)).rev() {
            if counter == 0 && day > 0 {
                println!("And {}", gifts[counter].to_lowercase());
            } else {
                println!("{}", gifts[counter]);
            }
        }

        println!();
        day += 1;
    }

    println!("And {}", gifts[0].to_lowercase());
}

fn transition_lyric(day: &str) {
    println!("On the {} of Christmas, my true love sent to me", day);
}
