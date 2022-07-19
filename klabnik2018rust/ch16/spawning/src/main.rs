use std::thread;
use std::time::Duration;

fn main() {
    let v = vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 0];

    let handle1 = thread::spawn(|| {
        for i in 1..10 {
            println!("[spawned_1] Count... {}", i);
            thread::sleep(Duration::from_millis(100));
        }
    });

    let handle2 = thread::spawn(move || {
        println!("[spawned_2] Here's a vector... {:?}", v);
    });

    for i in 1..5 {
        println!("[main] Count... {}", i);
        thread::sleep(Duration::from_millis(100));
    }

    handle1.join().unwrap();
    handle2.join().unwrap();

    // handle.join().unwrap();
}
