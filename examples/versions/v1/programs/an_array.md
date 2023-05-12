```basm
section @data:
    @my_array 2 [1, 2, 3, 4] # <variable-name> <size-of-one-element-in-bytes> [<values>]
    @my_message 1 ["Hello, World!\0"] # We can use " to write a string
    @my_second_message 1 ["Hello, World!", 0] # Here is another variant to put \0 in the end of string

%x = @my_array[0] # 1
%x = @my_array[2] # 2
%x = @my_array[4] # 3
@my_array[6] = 10 # Write 10 into array by address @my_array + 6 bytes
%x = @my_array[6] # 10
```