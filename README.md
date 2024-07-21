# Brainfuck Interpreter

This is a simple Brainfuck interpreter written in C. Brainfuck is a minimalistic programming language with only eight commands. This interpreter reads Brainfuck code and executes it, supporting standard Brainfuck commands and an additional custom command for filling the memory cell with a specified value.

## Features

- Supports standard Brainfuck commands:
  - `>`: Increment the data pointer (to point to the next cell to the right).
  - `<`: Decrement the data pointer (to point to the next cell to the left).
  - `+`: Increment the byte at the data pointer.
  - `-`: Decrement the byte at the data pointer.
  - `.`: Output the byte at the data pointer as a character.
  - `,`: Accept one byte of input, storing its value in the byte at the data pointer.
  - `[`: Jump forward to the command after the matching `]` if the byte at the data pointer is zero.
  - `]`: Jump back to the command after the matching `[` if the byte at the data pointer is nonzero.
- Custom `memfill` command:
  - `#<number>`: Fill the current memory cell with the specified value (e.g., `#65` fills the cell with `65`).

## How It Works

The interpreter executes the Brainfuck code in two passes:
1. **First Pass**: Determines the maximum tape size required by analyzing the Brainfuck code.
2. **Second Pass**: Executes the Brainfuck commands using the dynamically allocated tape.

## Dependencies

The interpreter includes the following standard C libraries:
- **`stdio.h`**: For standard input and output operations.
- **`string.h`**: For memset function.

## Usage

1. **Compile the Code**:
   ```sh
   gcc brainfuck.c -o brainfuck
   ```

2. **Run the interpreter**
   ```sh
   ./brainfuck "<brainfuck code>"
   ```

3. **Example**
   ```sh
   ./brainfuck "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++"
   ```