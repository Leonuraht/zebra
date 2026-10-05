mod lexer;
use std::env;
use std::fs::read_to_string;

fn main() -> std::io::Result<()> {
    let args: Vec<String> = env::args().collect();

    if args.len() < 2 {
        println!("ERROR : NO FILE NAME PROVIDED");
        return Ok(());
    }
    let name: String = args[1].clone();
    let mut flags: Vec<String> = Vec::new();
    if args.len() >= 3 {
        for i in &args[2..] {
            if !i.starts_with('-') {
                println!("ERROR : INVALID FLAGS PROVIDED\n");
                return Ok(());
            } else {
                flags.push(i[1..].to_string());
            }
        }
    }
    let file_data = match read_to_string(name) {
        Ok(file) => file,
        Err(e) => {
            println!("ERROR : {}", e);
            String::from("")
        }
    };
    println!("\nfiledata : \n{}\nflags: {:?}", file_data, flags);
    let ouy = lexer::lexer(file_data);
    println!("{:}", ouy);
    Ok(())
}
