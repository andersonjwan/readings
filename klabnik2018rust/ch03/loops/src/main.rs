fn main() {
    let mut counter = 0;

    let result = loop {
        // expression (loop {...})
        println!("Hello, world!");
        counter += 1;

        if counter == 10 {
            break counter * 2;
        }
    }; // statement (let result = ...;)

    println!("The result is... {}", result);

    // while loop
    let mut number = 3;

    while number != 0 {
        println!("The number is: {}", number);
        number -= 1;
    }

    println!("Lift Off 1!");

    // equivalent to while loop
    number = 3;
    loop {
        if number == 0 {
            break;
        } else {
            println!("The number is: {}", number);
            number -= 1;
        }
    }

    println!("Lift Off 2!");

    // looping through a collection
    // inefficient: a check is performed for each iteration
    let arr = [10, 20, 30, 40, 50];
    let mut index = 0;

    while index < 5 {
        println!("The value of arr[{}] is: {}", index, arr[index]);
        index += 1;
    }

    // for-each looping
    for element in arr.iter() {
        println!("The value of the element is: {}", element);
    }

    // countdown using `rev`
    for number in (1..4).rev() {
        println!("The countdown value is: {}", number);
    }
}
