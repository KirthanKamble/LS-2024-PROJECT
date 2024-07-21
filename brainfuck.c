#include <stdio.h>  // for putchar, getchar, fprintf
//#include <stdlib.h>// 
#include <string.h> // for memset

size_t calculate_max_tape_size(const char *code) {
    size_t max_tape_index = 0;
    size_t current_tape_index = 0;

    while (*code) {
        switch (*code) {
            case '>':
                current_tape_index++;
                if (current_tape_index > max_tape_index) {
                    max_tape_index = current_tape_index;
                }
                break;
            case '<':
                if (current_tape_index > 0) {
                    current_tape_index--;
                }
                break;
            default:
                break; // Ignore other commands for size calculation
        }
        code++;
    }

    return max_tape_index + 1;
}

void execute_brainfuck(const char *code) {
    size_t TAPE_SIZE = calculate_max_tape_size(code);
    char tape[TAPE_SIZE];       // Dynamically generate tape, TAPE_SIZE
    memset(tape, 0, TAPE_SIZE); // Initialize the tape with zeros
    char *ptr = tape;           // Pointer to the current cell on the tape
    const char *pc = code;      // Pointer to the current command in the code

    while (*pc) {
        switch (*pc) {
            case '>':
                ++ptr;
                if (ptr >= tape + TAPE_SIZE) {
                    fprintf(stderr, "Error: Tape overflow on '>'\n");
                    return;
                }
                break;
            case '<':
                --ptr;
                if (ptr < tape) {
                    fprintf(stderr, "Error: Tape underflow on '<'\n");
                    return;
                }
                break;
            case '+':
                ++(*ptr);
                break;
            case '-':
                --(*ptr);
                break;
            case '.':
                putchar(*ptr);
                break;
            case ',':
                *ptr = getchar();
                break;
            case '[':
                if (*ptr == 0) {
                    int loop = 1;
                    while (loop > 0) {
                        ++pc;
                        if (*pc == '[') ++loop;
                        if (*pc == ']') --loop;
                    }
                }
                break;
            case ']':
                if (*ptr != 0) {
                    int loop = 1;
                    while (loop > 0) {
                        --pc;
                        if (*pc == '[') --loop;
                        if (*pc == ']') ++loop;
                    }
                }
                break;
            default:
                fprintf(stderr, "Error: Not a brainfuck charachter '%c' at %d ", *pc, pc - code);
                return;
        }
        ++pc;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s \"<brainfuck code>\"\n", argv[0]);
        return 1;
    }

    execute_brainfuck(argv[1]);

    return 0;
}
