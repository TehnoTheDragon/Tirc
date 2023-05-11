# Abbreviations
- `VR` - Virtual Register (not physical register), used to easier read an assembly code and optimize it.
- `Neat Style` - basm with quality of life features like neat way to write "functions" (better for read)
- `Complex Style` - basm withouth quality of life features (better for debug)
# Guide
- We can set a value to our registers like this `%x = 10`, the `x` is a virtual register and not physical, it is used to easier understand assembly code, and to optimize it if need to.
- We can do basic math operations with our registers, it is supports: summation, subtraction, division, multiplying and module, the syntax looks like `%x + 1`, `%x - 1`, `%x / 1`, `%x * 1`, `%x % 1`, in this case result will be written into our `VR %x`, we can also get our result into another `VR` like this `%result = %x + 1`, in this case result will be written in our `VR %result`.
- We can create a labels like this `@label`, after a `@` we can use any name. For aesthetic we may use `:` after a name it is not leads to an error.
- Unconditional jump to a label: `jump @label`, it's important to tell `jump` how need it to read our argument, `@` means we want jump to label.
- We can write comments by adding `#` before our comment
- We can create definitions, they can help to not constantly write same thing over and over again, or we have can use them to abbreviate something. A definition looks like this `&nil 0`, after `&` we place a name of our definition and then after a space we write our value
- We can `push` and `pop` our stack. To push value onto the stack we write `push 10` or `push %x`, if we need get value back or just remove from top, we write `pop %x` and this write value into `VR %x` or just a `pop` to remove value
- We can use `call` to return back to address where the call was called, we can do it like this `call @our_function`, syntax is similar to `jump`. Use keyword `ret` to return back
- More about "functions", we can write a function two ways "complex" and "neat", both that way has pros and cons. Recomendation use "neat" style if it is not complex "function", because it is hard to debug in "neat" style
# Examples
## Basic Sum Function ("Complex")
```basm
@sum_two_values:
    pop %a # 10
    pop %b # 5
    %result = %a + %b
    push %result
    ret

push 5
push 10
call @sum_two_values
pop %x
# Our %x now stores 15
```
## Basic Sum Function ("Neat")
```basm
@sum_two_values(%a, %b):
    push %a + %b
    ret

%a = 10
%x = call @sum_two_values(%a, 5)
```
# Redesign