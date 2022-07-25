# AbstractVM 💻
A simple virtual machine that is able to interpret programs that are written in a simplified assembler language. To be precise, it consists in a stack machine that is able to calculate simple arithmetical expressions. These very arithmetical expressions are given to the machine in the form of simple assembler programs.

## **How to use**

### Compiling
Using Makefile : type command `make`

### Usage
With file : `./abstractVM file.avm` [ exemples of .avm can be found in /Exemples/ ]

Standar Input : `./abstractVM` [ To end the program execution type ;; ]

### Values Type

- `Int8`

- `Int16`

- `Int32`

- `Float`

- `Double`

- `BigDecimal`

## **Instructions**
- `push v` Stack the v value at the top. The v value will naturally take one of the following forms: int8(n), int16(n), int32(n), float(z), double(z) or bigdecimal(z). (For example : int16(n) - create an signed 16-bit integer with the value n)

- `pop` Unstacks the value at the top of the stack.

- `clear` Clears the stack. Rendering it empty.

- `dup` Duplicates the value on the top of the stack, and stacks the copy of the value.

- `swap` Reverses the order of (swaps) the top two values on the stack.

- `dump` Display each value on the stack from the newest to the oldest, WITHOUT MODIFYING the stack.

- `assert v` Verify that the value at the top of the stack is equal to the one passed as parameter in this instruction.

- `add` Unstack the first two values in the stack, add them, and then stack the result.

- `sub` Unstack the first two values in the stack, substract them, and then stack the result.

- `mul` Unstack the first two values in the stack, multiply them, and then stack the result.

- `div` Unstack the first two values in the stack, divide them, and then stack the result.

- `mod` Unstack the first two values in the stack, calculate their modulo, and then stack the result.

- `load v` Copy the value from the register v and stack it at the top.

- `store v` Unstack the first value and store it to the register v.

- `print` If the last value of the stack is an 8-bit integer, print the corresponding ASCII character.

- `exit` Quit the program execution.
