#[allow(unused_imports)]
// idiomatic use of `use`
use std::collections::HashMap; // if a struct, enum, constant, etc., bring in full item

mod clients;

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
