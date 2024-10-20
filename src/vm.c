#include <stdio.h>

#include "common.h"
#include "vm.h"
#include "value.h"

VM vm;

static InterpretResult run()
{
#define READ_BYTE() (*vm.ip++)
#define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])

    for (;;)
    {
        uint8_t instruction;
        switch (instruction = READ_BYTE())
        {
        case OP_CONSTANT: {
            Value constant = READ_CONSTANT();
            print_value(constant);
            printf("\n");
            break;
        }
        case OP_RETURN:
            return INTERPRET_OK;
        }
    }


#undef READ_BYTE
#undef READ_CONSTANT
}

void init_vm()
{
}

void free_vm()
{
}

InterpretResult interpret(Chunk *chunk)
{
    vm.chunk = chunk;
    vm.ip = vm.chunk->code;
    return run();
}
