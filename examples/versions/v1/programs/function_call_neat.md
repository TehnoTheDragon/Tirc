```basm
@sum_and_sub_two_values(%a, %b):
    push %a - %b
    push %a + %b
    ret

(%x, %y) = call @sum_two_values 10, 5
halt
```