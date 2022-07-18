use std::error::Error;
use std::fs;

mod config;
pub use config::Config; // re-exporting

pub fn run(config: Config) -> Result<(), Box<dyn Error>> {
    let contents = fs::read_to_string(config.filename)?;

    let matches = if config.case_sensitive {
        search(&config.query, &contents)
    } else {
        search_case_insensitive(&config.query, &contents)
    };

    for line in matches {
        println!("{}", line);
    }

    Ok(())
}

pub fn search<'a>(query: &str, contents: &'a str) -> Vec<&'a str> {
    contents
        .lines()
        .filter(|line| line.contains(query))
        .collect()
}

pub fn search_case_insensitive<'a>(query: &str, contents: &'a str) -> Vec<&'a str> {
    let query = query.to_lowercase();

    contents
        .lines()
        .filter(|line| line.to_lowercase().contains(&query))
        .collect()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_failure_run() {
        let config = Config {
            query: "abab".to_string(),
            filename: "nonexistent.txt".to_string(),
            case_sensitive: false,
        };

        assert!(run(config).is_err());
    }

    #[test]
    fn test_success_run() {
        let config = Config {
            query: "abab".to_string(),
            filename: "poem.txt".to_string(),
            case_sensitive: false,
        };

        assert!(run(config).is_ok());
    }

    #[test]
    fn test_search_case_sensitive() {
        let query = "duct";
        let contents = "\
	Rust:
safe, fast, productive.
Pick three.
Duct tape.";

        assert_eq!(vec!["safe, fast, productive."], search(query, contents));
    }

    #[test]
    fn test_search_case_insenstive() {
        let query = "rUsT";
        let contents = "\
Rust:
safe, fast, productive.
Pick three.
Trust me.";

        assert_eq!(
            vec!["Rust:", "Trust me."],
            search_case_insensitive(query, contents)
        );
    }
}
