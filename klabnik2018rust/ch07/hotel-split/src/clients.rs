#[allow(dead_code)]
pub struct Contract {
    pub name: String,
    date: String,
    identifier: u16,
}

#[allow(dead_code)]
pub enum Tier {
    Standard,
    Junior,
    Presidential,
    Penthouse,
}

impl Contract {
    pub fn sign(name: &str) -> Contract {
        Contract {
            name: String::from(name),
            date: String::from("07/13/2022"),
            identifier: 1234,
        }
    }
}

fn verify_status() {}

mod business;
pub mod customer;
