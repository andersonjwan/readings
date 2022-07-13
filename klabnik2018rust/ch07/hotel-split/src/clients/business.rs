#[allow(dead_code)]
fn register() {
    super::verify_status(); // call to parent module item
    add_member(); // call to sibling item
}

#[allow(dead_code)]
fn add_member() {}

pub mod silver;
