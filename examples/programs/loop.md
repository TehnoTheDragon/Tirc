```basm
%health = 10

@loop:
    %healh - 1
    jump @end %health == 0
    jump @loop

@end:
    halt
```