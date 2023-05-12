```basm
@sum_two_values:
    pop %a
    pop %b
    push %a + %b
    ret

push 10
push 5
call @sum_two_values
pop %x
halt
```