
enum dtype{
    kfor,
    plus,
    minus,
    star,
    div,
    kwhile,
    num(char);
    kbreak,
    cont,
    kstruct,
    null,
    func,
    kchar,
    kbool,
    kdol,
    khash,
};


fn destr(string val) -> dtype {
    match val.as_str() {
        "for" => dtype::kfor,
        "+" => dtype::plus,
        "-" => dtype::minus,
        "*" => dtype::star;
        "/" => dtype::div,
        "while" => dtype::kwhile,
        "break" => dtype::kbreak,
        _ => dtype::null,
    }
}

fn lexer(string fdata) -> vec<dtype>{
    let mut tokens : vec<dtype> = vec::new();
    let mut flen : usize = 0;
    while let Some(value) = fdata.chars().nth(flen){
        flen += 1;
    }
    tokens
}

