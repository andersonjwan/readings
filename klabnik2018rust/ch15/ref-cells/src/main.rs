use ref_cells::LimitTracker;
use ref_cells::Messenger;

struct MyMessenger {}

impl MyMessenger {
    fn new() -> MyMessenger {
        MyMessenger {}
    }
}

impl Messenger for MyMessenger {
    fn send(&self, msg: &str) {
        println!("{}", msg);
    }
}

fn main() {
    let messenger = MyMessenger::new();
    let mut tracker = LimitTracker::new(&messenger, 100);

    tracker.value(50);
    tracker.value(80);
    tracker.value(95);
    tracker.value(105);
}
