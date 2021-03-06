#ifndef MEM_H
#define MEM_H

#include <stdint.h>

#define VALID_MEM_OP(x) { if (x<0) {return z80_fail;}}

typedef struct{
    uint8_t *bios;
    uint32_t biosSize;
    uint8_t *ram;
    uint32_t ramSize;
    uint8_t *gfxRam;
    uint32_t gfxRamSize;
}mem_t;

//Initializes the pointers in the memory struct
int8_t mem_init(mem_t *mem);

//Reads a byte from a location and stores it in data
//Returns 0 if successful
//Returns <0 if unsuccessful
int8_t mem_readByte(mem_t *mem, uint16_t location, uint8_t *data);
int8_t mem_readShort(mem_t *mem, uint16_t location, uint16_t *data);
int8_t mem_getPointer(mem_t *mem, uint16_t location, uint8_t **ptr);

int8_t mem_writeByte(mem_t *mem, uint16_t location, uint8_t data);
int8_t mem_writeShort(mem_t *mem, uint16_t location, uint16_t data);
//frees any memory which may have been allocated
void mem_destroy(mem_t *mem);
#endif
