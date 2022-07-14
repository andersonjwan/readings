use std::collections::HashMap;

fn main() {
    let mut registrar: HashMap<String, Vec<String>> = HashMap::new();

    loop {
        let mut line = String::new();

        std::io::stdin()
            .read_line(&mut line)
            .expect("failed to read line");

        let words: Vec<&str> = line.split_whitespace().collect();
        let command = match words.get(0) {
            Some(w) => *w,
            None => {
                println!("Please supply a command. Try again!");
                continue;
            }
        };

        match command {
            "help" => display_help(),
            "add" => add_employee(&mut registrar, words),
            "show" => show_department(&registrar, words),
            "quit" => break,
            _ => {
                println!(
                    "Unrecognized command `{}`. Type `help` to get started.",
                    command
                );
                continue;
            }
        }
    }
}

fn display_help() {
    println!("Welcome to your company's Registrar!");
    println!("---------------------------------------");
    println!("Commands (Case-Sensitive):");
    println!("add  \tAdd a new employee to the registrar.");
    println!("     \t\tExample: \"add Jacob to Engineering\"");
    println!();
    println!("show \tShow the current set of employees for a department.");
    println!("     \tIf no department is specified, then all departments are shown.");
    println!("     \t\tExample: \"show Engineering\"");
    println!();
    println!("quit \tQuit the interface.")
}

fn add_employee(map: &mut HashMap<String, Vec<String>>, words: Vec<&str>) {
    let employee = match words.get(1) {
        Some(name) => *name,
        None => {
            println!("Please provide an employee's name. Try again!");
            return;
        }
    };

    let department = match words.get(3) {
        Some(name) => *name,
        None => {
            println!("Please provide an department's name. Try again!");
            return;
        }
    };

    loop {
        println!(
            "Add \"{}\" to \"{}\". Is this correct? (y/n) ",
            employee, department
        );

        let mut response = String::new();
        std::io::stdin()
            .read_line(&mut response)
            .expect("unable to read line");

        match response.trim() {
            "y" => {
                let employees = map
                    .entry(String::from(department))
                    .or_insert(Vec::<String>::new());
                employees.push(String::from(employee));

                println!("Added successfully!");
                return;
            }
            "n" => {
                println!("Aborted. Please re-enter the command. Try again!");
                return;
            }
            _ => continue,
        }
    }
}

fn show_department(map: &HashMap<String, Vec<String>>, words: Vec<&str>) {
    let department = match words.get(1) {
        Some(name) => *name,
        None => {
            for (department, employees) in map.iter() {
                println!("{}: {:?}", department, employees);
            }

            return;
        }
    };

    let employees = match map.get(&String::from(department)) {
        Some(people) => people,
        None => {
            println!("Department doesn't exist. Please add an employee to create the department.");
            return;
        }
    };

    println!("{}: {:?}", department, employees);
}
