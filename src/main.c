#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(int argc, char *argv[])
{
    Chunk chunk;

    init_chunk(&chunk);

    int const_addr = add_constant(&chunk, 1.2);
    write_chunk(&chunk, OP_CONSTANT);
    write_chunk(&chunk, const_addr);

    int const2_addr = add_constant(&chunk, 3.4);
    write_chunk(&chunk, OP_CONSTANT);
    write_chunk(&chunk, const2_addr);

    write_chunk(&chunk, OP_RETURN);


    disassemble_chunk(&chunk, "test chunk");
    free_chunk(&chunk);

    return 0;
}