#[derive(Debug)]
enum IpAddrKind {
    V4(u8, u8, u8, u8),
    V6(String),
}

#[derive(Debug)]
enum Message {
    Quit,
    Move { x: i32, y: i32 },
    Write(String),
    ChangeColor(i32, i32, i32),
}

impl Message {
    fn call(&self) {
        println!("{:?}", self);
    }
}

fn main() {
    let four = IpAddrKind::V4(127, 0, 0, 1);
    let six = IpAddrKind::V6(String::from("198.0.0.1"));

    route(four);
    route(six);

    let m = Message::Write(String::from("writing a message..."));
    m.call();

    // Option
    let num = Some(5);
    let str = Some("String");

    let absent_num: Option<i32> = None;

    let x: i8 = 5;
    let y: Option<i8> = Some(5);

    let z = x + y; // invalid, x type does not equal y type
}

fn route(ip_kind: IpAddrKind) {
    println!("IP Address Kind: {:?}", ip_kind);
}
