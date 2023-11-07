use std::thread;

fn main() {
    let data = vec![1, 2, 3, 4, 5];
    
    // Clone the data to share between threads
    let data_reader = data.clone();
    let data_writer = data.clone();

    // Create a thread for reading
    let reader_handle = thread::spawn(move || {
        for item in data_reader {
            println!("Read: {}", item);
        }
    });

    // Create a thread for writing
    let writer_handle = thread::spawn(move || {
        for item in data_writer {
            println!("Write: {}", item * 2);
        }
    });

    // Wait for both threads to finish
    reader_handle.join().unwrap();
    writer_handle.join().unwrap();
}