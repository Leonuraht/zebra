mod lexer;
use std::env;
use std::fs::File;

fn main() -> std::io::Result<()>{
    let args: Vec<String> = env::args().collect();
    let name: String = args[1].clone();
    let flags: Vec<char>;
    for i in &args[1..]{
        println!("{} ",i);
    }
    let file_data = File::open(name)?;
    println!("{}",file_data);

    Ok(())
}
