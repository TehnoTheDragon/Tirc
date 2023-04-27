# Syntax
## Data Types
`i1` - 1bit  
`i8` - 8bit  
`i16` - 16bit  
`i32` - 32bit  
`i64` - 64bit  
`float` - 32bit - floating point  
`double` - 64bit - floating point  
`void` - nothing  

## Symbols
`$` - variable  
`%` - address  
`!` - constant  

## Function
```
@sum_them(i32 $x, i32 $y) : i32 {
    $z : i32 = add $x $y;
    ret $z;
}
```