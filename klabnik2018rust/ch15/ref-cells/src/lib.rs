pub trait Messenger {
    fn send(&self, msg: &str);
}

pub struct LimitTracker<'a, T: 'a + Messenger> {
    messenger: &'a T,
    value: usize,
    max: usize,
}

impl<'a, T> LimitTracker<'a, T>
where
    T: Messenger,
{
    pub fn new(messenger: &T, max: usize) -> LimitTracker<T> {
        LimitTracker {
            messenger,
            value: 0,
            max,
        }
    }

    pub fn value(&mut self, value: usize) {
        self.value = value;

        let percent = self.value as f64 / self.max as f64;

        if percent >= 1.0 {
            self.messenger.send(&format!(
                "Error: You are over your quota! ({}/{})",
                self.value, self.max
            ));
        } else if percent >= 0.9 {
            self.messenger.send(&format!(
                "Urgent: You are reaching your quota! ({}/{})",
                self.value, self.max
            ));
        } else if percent >= 0.75 {
            self.messenger.send(&format!(
                "Warning: You have used over 75% of your quota! ({}/{})",
                self.value, self.max
            ));
        }
    }
}

#[cfg(test)]
mod tests {
    use std::cell::RefCell;

    use super::LimitTracker;
    use super::Messenger;

    struct MockMessenger {
        msg_history: RefCell<Vec<String>>,
    }

    impl MockMessenger {
        fn new() -> MockMessenger {
            MockMessenger {
                msg_history: RefCell::new(Vec::new()),
            }
        }
    }

    impl Messenger for MockMessenger {
        fn send(&self, msg: &str) {
            self.msg_history.borrow_mut().push(String::from(msg));
        }
    }

    #[test]
    fn over_75() {
        let msgr = MockMessenger::new();
        let mut trckr = LimitTracker::new(&msgr, 100);

        trckr.value(80);
        assert_eq!(msgr.msg_history.borrow().len(), 1);
    }
}
