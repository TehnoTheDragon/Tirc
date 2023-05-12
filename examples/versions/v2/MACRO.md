# Macro
## Examples
### Just a simple macro
```basm
macro push10i32 {
push i32 10
}

push10i32() # push i32 10
```
### Arguments
```basm
macro myPush (type, value) {
push type value
}

myPush(i32, 10) # push i32 10
```
### Arrays and Iteration
```basm
macro pushMultiple (type, values) {
    for value in values {
        push type value
    }
}

pushMultiple(i32, (1, 5, 10, 30, 50, 73, 573))
# push i32 1
# push i32 5
# push i32 10
# ...
# push i32 573
```

### Multi-dimensional "Arrays"
```basm
macro push2Array(TypesAndValues) {
    for element in TypesAndValues {
        push element.0 element.1
    }
}

push2Array(((i32, 54), (i8, 'H')))
```

### Map
```basm
macro pushMap(map) {
    for element in map {
        push element.type element.value
    }
}

pushMap([
    [type: i32, value: 10]
    [type: i8, value: 'H']
])
```

### Types and Conditions
```basm
macro pushMap(map) {
    for element in map {
        if type(element.value) == "string" {
            for char in element.value {
                push i8 char
            }
            push i32 length(element.value)
        } else {
            push element.type element.value
        }
    }
}

pushMap({
    {type: i32, value: 10}
    {type: i8, value: "Hello, World!"}
})
```

### Call other macros from a macro, and explicit types
```basm
macro pushMap(map) {
    for element in map {
        if type(element.value) == "string" {
            for char in element.value {
                push i8 char
            }
            push i32 length(element.value)
        } else {
            push element.type element.value
        }
    }
}

macro createOSData(name, version: i16 | [i8]) {
    pushMap({
        {type: i8, value: name}
        {type: i16, value: version}
    })
}

createOSData("Super OS", 1062)
createOSData("Super OS", "1.0.62")
createOSData("Super OS", 1000000000) # Error, it is supports only i16 and array of i8
```