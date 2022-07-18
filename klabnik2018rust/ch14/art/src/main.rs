use art::kinds::{PrimaryColor, SecondaryColor};
use art::utils;

// Note: This is also valid (assuming re-export is valid in lib)...
//
// use art::PrimaryColor;
// use art::SecondaryColor;
// use art::mix;

fn main() {
    let mixture: SecondaryColor = utils::mix(PrimaryColor::Blue, PrimaryColor::Red);
    println!("{:?}", mixture);
}
