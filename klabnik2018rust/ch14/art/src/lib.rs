//! # Art
//!
//! A library for modeling artistic concepts.

pub use crate::kinds::PrimaryColor;
pub use crate::kinds::SecondaryColor;
pub use crate::utils::mix;

pub mod kinds {
    /// The primary colors according to the RYB color model.
    #[derive(Debug)]
    pub enum PrimaryColor {
        Red,
        Yellow,
        Blue,
    }

    /// The secondary colors according to the RYB color model.
    #[derive(Debug)]
    pub enum SecondaryColor {
        Orange,
        Green,
        Purple,
    }
}

pub mod utils {
    use crate::kinds::PrimaryColor;
    use crate::kinds::SecondaryColor;

    /// Combines two primary colors in equal amounts to create
    /// a secondary color.
    #[allow(unused_variables)]
    pub fn mix(color1: PrimaryColor, color2: PrimaryColor) -> SecondaryColor {
        SecondaryColor::Green
    }
}

#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        let result = 2 + 2;
        assert_eq!(result, 4);
    }
}
