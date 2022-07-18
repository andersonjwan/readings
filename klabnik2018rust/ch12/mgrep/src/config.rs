use std::env;

#[derive(PartialEq, Debug)]
pub struct Config {
    pub query: String,
    pub filename: String,
    pub case_sensitive: bool,
}

impl Config {
    pub fn new<T: Iterator<Item = String>>(mut args: T) -> Result<Config, &'static str> {
        args.next();

        let query = match args.next() {
            Some(q) => q,
            None => return Err("A query was not provided."),
        };

        let filename = match args.next() {
            Some(f) => f,
            None => return Err("An input file was not provided."),
        };

        let case_sensitive = env::var("CASE_INSENSITIVE").is_err();

        Ok(Config {
            query,
            filename,
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
        assert_eq!(
            Err("A query was not provided."),
            Config::new(args.into_iter())
        );
    }

    #[test]
    fn test_with_one_arg() {
        let args: [String; 1] = ["mgrep".to_string()];
        assert_eq!(
            Err("A query was not provided."),
            Config::new(args.into_iter())
        );
    }

    #[test]
    fn test_with_two_args() {
        let args: [String; 2] = ["mgrep".to_string(), "aaaa".to_string()];
        assert_eq!(
            Err("An input file was not provided."),
            Config::new(args.into_iter())
        );
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
            case_sensitive: true,
        };

        assert_eq!(Ok(expected), Config::new(args.into_iter()));
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
            case_sensitive: true,
        };

        assert_eq!(Ok(expected), Config::new(args.into_iter()));
    }
}
