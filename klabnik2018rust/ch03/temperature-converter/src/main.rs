fn main() {
    let temperature: f64 = 50.0;
    println!("{} F == {} C", temperature, convert(temperature, 0, 1));

    let temperature: f64 = 30.0;
    println!("{} C == {} F", temperature, convert(temperature, 1, 0));

    let temperature: f64 = 75.0;
    println!("{} F == {} F", temperature, convert(temperature, 0, 0));

    let temperature: f64 = 86.0;
    println!("{} C == {} C", temperature, convert(temperature, 1, 1));
}

/// Convert between Fahrenheit and Celsius.
/// Fahrenheit: 0, Celsius: 1
fn convert(temperature: f64, from: i8, to: i8) -> f64 {
    if from == to {
        println!("no conversion necessary...");
        temperature
    } else if from == 0 && to == 1 {
        // fahrenheit to celsius
        println!("converting from F to C...");
        (temperature - 32.0) * (5.0 / 9.0)
    } else if from == 1 && to == 0 {
        // celsius to fahrenheit
        println!("converting from C to F...");
        (temperature * (9.0 / 5.0)) + 32.0
    } else {
        println!("unknown conversion request");
        temperature
    }
}
