use std::env;
use std::process;

use mgrep::Config;

fn main() {
    let config = Config::new(env::args()).unwrap_or_else(|e| {
        eprintln!("There was a problem parsing the arguments. See: {}", e);
        process::exit(1);
    });

    if let Err(e) = mgrep::run(config) {
        eprintln!("Application error: {}", e);
        process::exit(1);
    }
}
