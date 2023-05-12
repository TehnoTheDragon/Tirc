`functions.basm`
```basm
@sum_three_values(%x, %y, %z):
    push %x + %y + %z
    ret
```

`main.basm`
```basm
#includ "functions.basm"

push 10
push 20
push 30
call @sum_three_values
pop %x
```