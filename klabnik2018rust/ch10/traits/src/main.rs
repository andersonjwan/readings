trait Summary {
    fn summarize(&self) -> String {
        // default implementation provided
        String::from("(Read more...)")
    }

    fn printout(&self) -> String; // no default implementation
}

struct Book {
    title: String,
    author: String,
    volume: u32,
    year: u32,
}

struct NewsArticle {
    headline: String,
    location: String,
    author: String,
    content: String,
}

struct Tweet {
    username: String,
    content: String,
    reply: bool,
    retweet: bool,
}

impl Summary for NewsArticle {
    fn summarize(&self) -> String {
        format!("{}, by {} ({})", self.headline, self.author, self.location)
    }

    fn printout(&self) -> String {
        format!(
            "{}, {}, {}, {}",
            self.headline, self.location, self.author, self.content
        )
    }
}

impl Summary for Tweet {
    fn summarize(&self) -> String {
        format!("{}: {}", self.username, self.content)
    }

    fn printout(&self) -> String {
        format!(
            "{}, {}, {}, {}",
            self.username, self.content, self.reply, self.retweet
        )
    }
}

impl Summary for Book {
    // use default implementation of `summarize`

    fn printout(&self) -> String {
        format!(
            "{}, {}, {}, {}",
            self.title, self.author, self.volume, self.year
        )
    }
}

fn main() {
    let tweet = Tweet {
        username: String::from("andersonjwan"),
        content: String::from("This is my first Tweet. Hello, Twitter!"),
        reply: false,
        retweet: false,
    };

    let book = Book {
        title: String::from("The Rust Programming Language"),
        author: String::from("Steve K. and Carol N."),
        volume: 2,
        year: 2018,
    };

    println!("Tweet: {}", tweet.summarize());
    println!("Book: {}", book.summarize());

    notify(tweet);
    notify(book);
}

fn notify(item: impl Summary) {
    println!("The summary is... {}", item.summarize());
}

// `where` clause
fn overview<T, U>(item1: T, item2: U) -> String
where
    T: std::fmt::Display + Clone,
    U: Clone + std::fmt::Debug + Summary,
{
    println!("This is just an overview test...");
    println!("{}... {}...", item1, item2.summarize());

    String::from("ret")
}

fn summaryable() -> impl Summary {
    Tweet {
        username: String::from("default"),
        content: String::from("..."),
        reply: false,
        retweet: false,
    }
}
