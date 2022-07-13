#[allow(dead_code)]
fn upgrade() {
    crate::clients::business::register(); // valid since `silver` is a child of `business`
}
