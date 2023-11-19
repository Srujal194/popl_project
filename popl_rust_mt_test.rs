use std::fs::File;
use std::io::{BufReader, BufRead, BufWriter, Write};
use std::thread;

fn main() {
    // Open a file for reading
    let reader_file = File::open("input.txt").expect("Failed to open input file");
    let reader = BufReader::new(reader_file);

    // Open a file for writing
    let writer_file = File::create("output.txt").expect("Failed to create output file");
    let mut writer = BufWriter::new(writer_file);

    // Create a thread for reading and writing
    let handle = thread::spawn(move || {
        for line in reader.lines() {
            if let Ok(num) = line {
                writeln!(&mut writer, "{}", num).expect("Failed to write to file");
            }
        }
        writer.flush().expect("Failed to flush buffer");
    });

    // Wait for the thread to finish
    handle.join().unwrap();
}
