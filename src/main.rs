use std::env;
use std::io;
use std::fs;
use lexer;

#[derive(Debug,Default)]
struct Inargs {
    filename : String , 
    flags : Vec<char>,
}




fn main() -> io::Result<()>{
    let mut argval = Inargs::default();
    for args in env::args().skip(1){
        if args.chars().next() == Some('-'){
            match args.chars().nth(1){
                Some(flag) => argval.flags.push(flag),
                None => continue,
            }
        }else {
            if argval.filename.is_empty(){
                argval.filename = args;
            }
        }
    }
    let filedata = match fs::read_to_string(argval.filename){
        Ok(val) => val,
        Err(err) => {
            println!("ERROR\t:\t{}",err);
            return Ok(())
        }
    };
    println!("{}",filedata);
    Ok(())
}
