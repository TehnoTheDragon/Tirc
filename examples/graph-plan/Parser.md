# AST
```
Types:
    None,
    Compound,
    Operator,
    Name,
    Value

NameType:
    Variable,
    Register,
    Label

ValueType:
    Number,
    String

ASTNode:
    None:
        - Void nothing
    Compound:
        - List[ASTNode*] list
    Operator:
        - String operator
        - List[ASTNode*] arguments
    Name:
        - NameType type
        - String name
    Value:
        - ValueType type
        - String value
```

## Example
```
section @.data
global @entry
@entry: {
  jump @entry
}
```
```
Root:
    > Section:
        > .data
    > Global:
        > entry
    > Label:
        > entry
    > Operation:
        > jump
        Arguments:
            > entry
```