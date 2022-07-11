struct User {
    email: String,
    username: String,
    login_count: u64,
    active: bool,
}

struct Point(i32, i32, i32);
struct Color(i32, i32, i32);

fn main() {
    let mut user1 = User {
        email: String::from("andersonjwan@gmail.com"),
        username: String::from("andersonjwan"),
        active: true,
        login_count: 1,
    };

    user1.email = String::from("andersonjwan@outlook.com");
    user1.login_count += 1;
    user1.active = false;

    let new_user = user_factory(
        String::from("andersonjwan@hotmail.com"),
        String::from("andersonjwan"),
    );

    println!(
        "new_user: ({}, {}, {}, {})",
        new_user.email, new_user.username, new_user.active, new_user.login_count
    );

    let user2 = User {
        email: String::from("someone@example.com"),
        username: String::from("someone"),
        active: user1.active,
        login_count: user1.login_count,
    };

    // shorthand notation for creating a new instance from existing instance
    let user3 = User {
        email: String::from("someoneelse@example.com"),
        username: String::from("someoneelse"),
        ..user1
    };

    let p1 = Point(0, 0, 0); // origin
    let c1 = Color(0, 0, 0); // black
}

fn user_factory(email: String, username: String) -> User {
    User {
        email,
        username,
        active: true,
        login_count: 1,
    }
}
