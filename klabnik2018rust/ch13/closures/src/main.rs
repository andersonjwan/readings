use std::thread;
use std::time::Duration;

struct Cache<T>
where
    T: Fn(u32) -> u32,
{
    calculation: T,
    value: Option<u32>,
}

impl<T> Cache<T>
where
    T: Fn(u32) -> u32,
{
    fn new(calculation: T) -> Cache<T> {
        Cache {
            calculation,
            value: None,
        }
    }

    fn value(&mut self, arg: u32) -> u32 {
        match self.value {
            Some(v) => v,
            None => {
                let v = (self.calculation)(arg);
                self.value = Some(v);
                v
            }
        }
    }
}

fn main() {
    let sim_user_value = 10;
    let sim_rand_value = 7;

    generate_workout_routine(sim_user_value, sim_rand_value);

    // simulated_expensive_calculation(20);
}

fn generate_workout_routine(intensity: u32, random_num: u32) {
    let mut expensive_closure = Cache::new(|num| {
        println!("caching value...");
        thread::sleep(Duration::from_secs(2));
        num
    });

    if intensity < 25 {
        println!(
            "Do workout routine #1 for {} minutes...",
            expensive_closure.value(intensity)
        );
        println!(
            "Next, do workout routine #3 for {} minutes...",
            expensive_closure.value(intensity)
        );
    } else {
        if random_num == 3 {
            println!("Take a break...");
        } else {
            println!(
                "Do workout routine #2 for {} minutes...",
                expensive_closure.value(intensity)
            );
        }
    }
}

#[allow(unused)]
fn simulated_expensive_calculation(intensity: u32) -> u32 {
    println!("calculating slowly...");
    thread::sleep(Duration::from_secs(2));

    intensity
}
