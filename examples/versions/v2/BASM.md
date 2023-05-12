# Symbols
- `!` - Constant value
- `@` - Label name, Label address
- `#` - Comment or definition/macro/preprocessor
- `$` - Variable name
- `%` - (Virtual/Physical) Register name

# Guide
## Low-Level
### Sections
```basm
section @data {
    # Data goes here...
}
section @text {
    # A Program goes here...
}
```
- `{` and `}` are optional, they need just to make your assembler code understandable for new developers or just make "begin and end" of something more visible
### Labels
```basm
@jump_here: {

}
```
- `:` is optional in this case, you may not use it
### Variables
```basm
$my_message : i8 = "Hello, World", 10, 0
$my_number : i16 = 65536
$my_float : f32 = 10.02
$my_pointer : ptr = 0
```
- prefix `i` and number after it, is an amount of bits, it supports numbers powered by 2
- prefix `b` and number after it, is an amount of bytes, it supports all positive numbers
- prefix `f` is floating point value, number after it, is amount of bits, it has same supports of numbers as `i`
- type `ptr` is a pointer to address
### Registers and Virtual Registers
```basm
%acc = 10
%x : i8 = 5
```
- Virtual registers are must have a type of value
### Function Call
```basm
@my_function: {
    %x : i32 = pop
    %y : i32 = pop
    %result : i32 = %x + %y
    push %result
    ret
}

push i32 10
push i32 30
call @my_function
%x : i32 = pop
```

## High-Level
### Function Call
```basm
fn @my_function(x : i32, y : i32) : i32 {
    return x + y
}

%x : i32 = call @my_function 10, 5
```

## Preprocessor
### Include
```
./project/ >
    |- functions.basm
    |- main.basm
```   
`functions.basm`
```basm
@my_function: {
    %x : i32 = pop
    %y : i32 = pop
    %result : i32 = %x + %y
    push %result
    ret
}
```
`main.basm`
```basm
#include "functions.basm"

push i32 10
push i32 30
call @my_function
%x : i32 = pop
```
### Conditions and Debug
```basm
#if ARCHITECTURE == "x86_64"
#log "Selected ${ARCHITECTURE}"
#elif ARCHITECTURE == "RISC-V"
#log "Selected ${ARCHITECTURE}"
#else
#error "Unsupported architecture: ${ARCHITECTURE}"
#end
```
- If you want write a comment like `#if` or anything starts with preprocessor, just add space between, `# if` - is comment now, or you can start from capital letter, `#If` - is comment also.

### Definition
```basm
#define PI 3.14159265359
```

### Macro
- Macro is a big topic, read about it [here](MACRO.md)
