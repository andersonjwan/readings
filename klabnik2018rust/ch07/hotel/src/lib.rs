#[allow(unused_imports)]
// idiomatic use of `use`
use std::collections::HashMap; // if a struct, enum, constant, etc., bring in full item

#[allow(dead_code)]
mod clients {
    pub struct Contract {
        pub name: String,
        date: String,
        identifier: u16,
    }

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

    pub mod customer {
        pub fn check_in() {
            super::verify_status(); // call to parent module item
        }

        fn check_out() {}
    }

    mod business {
        fn register() {
            super::verify_status(); // call to parent module item
            add_member(); // call to sibling item
        }

        fn add_member() {}

        pub mod silver {
            fn upgrade() {
                crate::clients::business::register(); // valid since `silver` is a child of `business`
            }
        }
    }
}

pub use crate::clients::customer; // re-exporting
                                  // those using the code can now call `customer::check_in`

#[allow(unused_variables)]
pub fn book() {
    crate::clients::customer::check_in(); // absolute path
    clients::customer::check_in(); // relative path

    customer::check_in();

    // sign-in customer
    let mut contract = clients::Contract::sign("Jacob Anderson");
    contract.name = String::from("Jacob W. Anderson");

    println!(
        "You've signed the contract with the name: {}",
        contract.name
    );

    // invalid
    // contract.identifier = 9876; // `identifier` is not marked public

    let room1 = clients::Tier::Junior;
    let room2 = clients::Tier::Presidential;
}
