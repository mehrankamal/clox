#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, char *argv[])
{
    init_vm();

    Chunk chunk;

    init_chunk(&chunk);

    int const_addr = add_constant(&chunk, 1.2);
    write_chunk(&chunk, OP_CONSTANT, 1);
    write_chunk(&chunk, const_addr, 1);

    int const2_addr = add_constant(&chunk, 3.4);
    write_chunk(&chunk, OP_CONSTANT, 1);
    write_chunk(&chunk, const2_addr, 1);

    write_chunk(&chunk, OP_RETURN, 1);


    disassemble_chunk(&chunk, "test chunk");
    
    free_vm();
    free_chunk(&chunk);

    return 0;
}