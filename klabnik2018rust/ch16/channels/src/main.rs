use std::sync::mpsc;
use std::thread;
use std::time::Duration;

fn main() {
    let (tx, rx) = mpsc::channel();

    let handle1 = thread::spawn(move || {
        let val = String::from("Hello, thread!");
        println!("[spawned_1] Sending... {}", val);

        tx.send(val).unwrap();
    });

    let handle2 = thread::spawn(move || {
        let received = rx.recv().unwrap();
        println!("[spawned_2] Received... {}", received);
    });

    let (tx, rx) = mpsc::channel();

    let tx1 = mpsc::Sender::clone(&tx);
    let tx2 = mpsc::Sender::clone(&tx);

    let handle3 = thread::spawn(move || {
        let msgs = vec![
            String::from("[handle_3] More"),
            String::from("[handle_3] messages"),
            String::from("[handle_3] from"),
            String::from("[handle_3] second"),
            String::from("[handle_3] thead"),
        ];

        for msg in msgs {
            tx1.send(msg).unwrap();
            thread::sleep(Duration::from_secs(1));
        }
    });

    let handle4 = thread::spawn(move || {
        let msgs = vec![
            String::from("[handle_4] Yet"),
            String::from("[handle_4] again"),
            String::from("[handle_4] here"),
            String::from("[handle_4] is"),
            String::from("[handle_4] another"),
            String::from("[handle_4] thread"),
        ];

        for msg in msgs {
            tx2.send(msg).unwrap();
            thread::sleep(Duration::from_secs(2));
        }
    });

    let handle5 = thread::spawn(move || {
        let msgs = vec![
            String::from("[handle_5] Hello"),
            String::from("[handle_5] from"),
            String::from("[handle_5] the"),
            String::from("[handle_5] thread"),
        ];

        for msg in msgs {
            tx.send(msg).unwrap();
            thread::sleep(Duration::from_secs(1));
        }
    });

    for received in rx {
        println!("[main] Got... {}", received);
    }

    handle1.join().unwrap(); // wait for `handle1` to finish
    handle2.join().unwrap(); // wait for `handle2` to finish
}
