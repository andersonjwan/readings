use std::env;

#[derive(PartialEq, Debug)]
pub struct Config {
    pub query: String,
    pub filename: String,
    pub case_sensitive: bool,
}

impl Config {
    pub fn new(args: &[String]) -> Result<Config, &'static str> {
        if args.len() < 3 {
            return Err("not enough arguments provided");
        }

        let case_sensitive = env::var("CASE_INSENSITIVE").is_err();

        Ok(Config {
            query: args[1].clone(),
            filename: args[2].clone(),
            case_sensitive,
        })
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_with_zero_args() {
        let args: [String; 0] = [];
        assert_eq!(Err("not enough arguments provided"), Config::new(&args));
    }

    #[test]
    fn test_with_one_arg() {
        let args: [String; 1] = ["mgrep".to_string()];
        assert_eq!(Err("not enough arguments provided"), Config::new(&args));
    }

    #[test]
    fn test_with_two_args() {
        let args: [String; 2] = ["mgrep".to_string(), "aaaa".to_string()];
        assert_eq!(Err("not enough arguments provided"), Config::new(&args));
    }

    #[test]
    fn test_with_three_args() {
        let args: [String; 3] = [
            "mgrep".to_string(),
            "aaaa".to_string(),
            "filename.txt".to_string(),
        ];

        let expected = Config {
            query: "aaaa".to_string(),
            filename: "filename.txt".to_string(),
        };

        assert_eq!(Ok(expected), Config::new(&args));
    }

    #[test]
    fn test_with_four_args() {
        let args: [String; 4] = [
            "mgrep".to_string(),
            "aaaa".to_string(),
            "filename.txt".to_string(),
            "extra".to_string(),
        ];

        let expected = Config {
            query: "aaaa".to_string(),
            filename: "filename.txt".to_string(),
        };

        assert_eq!(Ok(expected), Config::new(&args));
    }
}
