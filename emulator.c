#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct ConditionCodes {
	uint8_t z:1;
	uint8_t s:1;
	uint8_t p:1;
	uint8_t cy:1;
	uint8_t ac:1;
	uint8_t pad:3;
} ConditionCodes;

typedef struct State8080 {
	uint8_t a;
	uint8_t b;
	uint8_t c;
	uint8_t d;
	uint8_t e;
	uint8_t h;
	uint8_t l;
	uint16_t sp;
	uint16_t pc;
	uint8_t *memory;
	struct ConditionCodes cc;
	uint8_t int_enable;
} State8080;

void UnimplementedInstruction(State8080* state)
{
	printf("Error: Unimplemented instruction\n");
	exit(1);
}

uint8_t Parity(uint8_t x)
{
	uint8_t p = 0;
	while (x > 0)
	{
		p = (p + (x & 1)) % 2;
		x >>= 1;
	}
	return p;
}

int Emulate8080Op(State8080* state)
{
	unsigned char *opcode = &state->memory[state->pc];
	switch (*opcode)
	{
		case 0x00: break;
		case 0x01: 
				   state->c = opcode[1];
				   state->b = opcode[2];
				   state->pc += 2;
				   break;
		case 0x02: UnimplementedInstruction(state); break;
		case 0x03: UnimplementedInstruction(state); break;
		case 0x04: UnimplementedInstruction(state); break;
		case 0x05: UnimplementedInstruction(state); break;
		case 0x06: UnimplementedInstruction(state); break;
		case 0x07: UnimplementedInstruction(state); break;
		case 0x08: UnimplementedInstruction(state); break;
		case 0x09: UnimplementedInstruction(state); break;
		case 0x0a: UnimplementedInstruction(state); break;
		case 0x0b: UnimplementedInstruction(state); break;
		case 0x0c: UnimplementedInstruction(state); break;
		case 0x0d: UnimplementedInstruction(state); break;
		case 0x0e: UnimplementedInstruction(state); break;
		case 0x0f: UnimplementedInstruction(state); break;
		case 0x10: UnimplementedInstruction(state); break;
		case 0x11: UnimplementedInstruction(state); break;
		case 0x12: UnimplementedInstruction(state); break;
		case 0x13: UnimplementedInstruction(state); break;
		case 0x14: UnimplementedInstruction(state); break;
		case 0x15: UnimplementedInstruction(state); break;
		case 0x16: UnimplementedInstruction(state); break;
		case 0x17: UnimplementedInstruction(state); break;
		case 0x18: UnimplementedInstruction(state); break;
		case 0x19: UnimplementedInstruction(state); break;
		case 0x1a: UnimplementedInstruction(state); break;
		case 0x1b: UnimplementedInstruction(state); break;
		case 0x1c: UnimplementedInstruction(state); break;
		case 0x1d: UnimplementedInstruction(state); break;
		case 0x1e: UnimplementedInstruction(state); break;
		case 0x1f: UnimplementedInstruction(state); break;
		case 0x20: UnimplementedInstruction(state); break;
		case 0x21: UnimplementedInstruction(state); break;
		case 0x22: UnimplementedInstruction(state); break;
		case 0x23: UnimplementedInstruction(state); break;
		case 0x24: UnimplementedInstruction(state); break;
		case 0x25: UnimplementedInstruction(state); break;
		case 0x26: UnimplementedInstruction(state); break;
		case 0x27: UnimplementedInstruction(state); break;
		case 0x28: UnimplementedInstruction(state); break;
		case 0x29: UnimplementedInstruction(state); break;
		case 0x2a: UnimplementedInstruction(state); break;
		case 0x2b: UnimplementedInstruction(state); break;
		case 0x2c: UnimplementedInstruction(state); break;
		case 0x2d: UnimplementedInstruction(state); break;
		case 0x2e: UnimplementedInstruction(state); break;
		case 0x2f: UnimplementedInstruction(state); break;
		case 0x30: UnimplementedInstruction(state); break;
		case 0x31: UnimplementedInstruction(state); break;
		case 0x32: UnimplementedInstruction(state); break;
		case 0x33: UnimplementedInstruction(state); break;
		case 0x34: UnimplementedInstruction(state); break;
		case 0x35: UnimplementedInstruction(state); break;
		case 0x36: UnimplementedInstruction(state); break;
		case 0x37: UnimplementedInstruction(state); break;
		case 0x38: UnimplementedInstruction(state); break;
		case 0x39: UnimplementedInstruction(state); break;
		case 0x3a: UnimplementedInstruction(state); break;
		case 0x3b: UnimplementedInstruction(state); break;
		case 0x3c: UnimplementedInstruction(state); break;
		case 0x3d: UnimplementedInstruction(state); break;
		case 0x3e: UnimplementedInstruction(state); break;
		case 0x3f: UnimplementedInstruction(state); break;
		case 0x40: state->b = state->b; break;
		case 0x41: state->b = state->c; break;
		case 0x42: state->b = state->d; break;
		case 0x43: state->b = state->e; break;
		case 0x44: state->b = state->h; break;
		case 0x45: state->b = state->l; break;
		case 0x46: // MOV B, M
				{
				   uint16_t offset = (state->h << 8) | state->l;
				   state->b = state->memory[offset];
				   break;
				}
		case 0x47: state->b = state->a; break;
		case 0x48: state->c = state->b; break;
		case 0x49: state->c = state->c; break;
		case 0x4a: state->c = state->d; break;
		case 0x4b: state->c = state->e; break;
		case 0x4c: state->c = state->h; break;
		case 0x4d: state->c = state->l; break;
		case 0x4e: // MOV C, M
				{
				   uint16_t offset = (state->h << 8) | state->l;
				   state->c = state->memory[offset];
				   break;
				}
		case 0x4f: state->c = state->a; break;
		case 0x50: state->d = state->b; break;
		case 0x51: state->d = state->c; break;
		case 0x52: state->d = state->d; break;
		case 0x53: state->d = state->e; break;
		case 0x54: state->d = state->h; break;
		case 0x55: state->d = state->l; break;
		case 0x56: // MOV D, M
				{
				   uint16_t offset = (state->h << 8) | state->l;
				   state->d = state->memory[offset];
				   break;
				}
		case 0x57: state->d = state->a; break;
		case 0x58: state->e = state->b; break;
		case 0x59: state->e = state->c; break;
		case 0x5a: state->e = state->d; break;
		case 0x5b: state->e = state->e; break;
		case 0x5c: state->e = state->h; break;
		case 0x5d: state->e = state->l; break;
		case 0x5e: // MOV E, M
				{
				   uint16_t offset = (state->h << 8) | state->l;
				   state->e = state->memory[offset];
				   break;
				}
		case 0x5f: state->e = state->a; break;
		case 0x60: state->h = state->b; break;
		case 0x61: state->h = state->c; break;
		case 0x62: state->h = state->d; break;
		case 0x63: state->h = state->e; break;
		case 0x64: state->h = state->h; break;
		case 0x65: state->h = state->l; break;
		case 0x66: // MOV H, M
				{
				   uint16_t offset = (state->h << 8) | state->l;
				   state->h = state->memory[offset];
				   break;
				}
		case 0x67: state->h = state->a; break;
		case 0x68: state->l = state->b; break;
		case 0x69: state->l = state->c; break;
		case 0x6a: state->l = state->d; break;
		case 0x6b: state->l = state->e; break;
		case 0x6c: state->l = state->h; break;
		case 0x6d: state->l = state->l; break;
		case 0x6e: // MOV L, M
				{
				   uint16_t offset = (state->h << 8) | state->l;
				   state->l = state->memory[offset];
				   break;
				}
		case 0x6f: state->l = state->a; break;
		case 0x70: // MOV M, B
				{
				   uint16_t offset = (state->h << 8) | state->l;
				   state->memory[offset] = state->b;
				   break;
				}
		case 0x71: // MOV M, C
				{
				   uint16_t offset = (state->h << 8) | state->l;
				   state->memory[offset] = state->c;
				   break;
				}
		case 0x72: // MOV M, D
				{
				   uint16_t offset = (state->h << 8) | state->l;
				   state->memory[offset] = state->d;
				   break;
				}
		case 0x73: // MOV M, E
				{
				   uint16_t offset = (state->h << 8) | state->l;
				   state->memory[offset] = state->e;
				   break;
				}
		case 0x74: // MOV M, H
				{
				   uint16_t offset = (state->h << 8) | state->l;
				   state->memory[offset] = state->h;
				   break;
				}
		case 0x75: // MOV M, L
				{
				   uint16_t offset = (state->h << 8) | state->l;
				   state->memory[offset] = state->l;
				   break;
				}
		case 0x76: break;
		case 0x77: // MOV M, A
				{
				   uint16_t offset = (state->h << 8) | state->l;
				   state->memory[offset] = state->a;
				   break;
				}
		case 0x78: state->a = state->b; break;
		case 0x79: state->a = state->c; break;
		case 0x7a: state->a = state->d; break;
		case 0x7b: state->a = state->e; break;
		case 0x7c: state->a = state->h; break;
		case 0x7d: state->a = state->l; break;
		case 0x7e: // MOV A, M
				{
				   uint16_t offset = (state->h << 8) | state->l;
				   state->a = state->memory[offset];
				   break;
				}
		case 0x7f: state->a = state->a; break;
		case 0x80: // ADD B
				{
				   uint16_t answer = (uint16_t) state->a + (uint16_t) state->b;
				   state->cc.z = ((answer & 0xff) == 0);
				   state->cc.s = ((answer & 0x80) != 0);
				   state->cc.cy = (answer > 0xff);
				   state->cc.p = Parity(answer & 0xff);
				   state->a = answer & 0xff;
				   break;
				}
		case 0x81: // ADD C
				{
				   uint16_t answer = (uint16_t) state->a + (uint16_t) state->c;
				   state->cc.z = ((answer & 0xff) == 0);
				   state->cc.s = ((answer & 0x80) != 0);
				   state->cc.cy = (answer > 0xff);
				   state->cc.p = Parity(answer & 0xff);
				   state->a = answer & 0xff;
				   break;
				}
		case 0x82: // ADD D
				{
				   uint16_t answer = (uint16_t) state->a + (uint16_t) state->d;
				   state->cc.z = ((answer & 0xff) == 0);
				   state->cc.s = ((answer & 0x80) != 0);
				   state->cc.cy = (answer > 0xff);
				   state->cc.p = Parity(answer & 0xff);
				   state->a = answer & 0xff;
				   break;
				}
		case 0x83: // ADD E
				{
				   uint16_t answer = (uint16_t) state->a + (uint16_t) state->e;
				   state->cc.z = ((answer & 0xff) == 0);
				   state->cc.s = ((answer & 0x80) != 0);
				   state->cc.cy = (answer > 0xff);
				   state->cc.p = Parity(answer & 0xff);
				   state->a = answer & 0xff;
				   break;
				}
		case 0x84: // ADD H
				{
				   uint16_t answer = (uint16_t) state->a + (uint16_t) state->h;
				   state->cc.z = ((answer & 0xff) == 0);
				   state->cc.s = ((answer & 0x80) != 0);
				   state->cc.cy = (answer > 0xff);
				   state->cc.p = Parity(answer & 0xff);
				   state->a = answer & 0xff;
				   break;
				}
		case 0x85: // ADD L
				{
				   uint16_t answer = (uint16_t) state->a + (uint16_t) state->l;
				   state->cc.z = ((answer & 0xff) == 0);
				   state->cc.s = ((answer & 0x80) != 0);
				   state->cc.cy = (answer > 0xff);
				   state->cc.p = Parity(answer & 0xff);
				   state->a = answer & 0xff;
				   break;
				}
		case 0x86: // ADD M
				{
				   uint16_t offset = (state->h << 8) | state->l;
				   uint16_t answer = (uint16_t) state->a + state->memory[offset];
				   state->cc.z = ((answer & 0xff) == 0);
				   state->cc.s = ((answer & 0x80) != 0);
				   state->cc.cy = (answer > 0xff);
				   state->cc.p = Parity(answer & 0xff);
				   state->a = answer & 0xff;
				   break;
				}
		case 0x87: // ADD A
				{
				   uint16_t answer = (uint16_t) state->a + (uint16_t) state->a;
				   state->cc.z = ((answer & 0xff) == 0);
				   state->cc.s = ((answer & 0x80) != 0);
				   state->cc.cy = (answer > 0xff);
				   state->cc.p = Parity(answer & 0xff);
				   state->a = answer & 0xff;
				   break;
				}
		case 0x88: // ADC B (A <- A + B + CY)
				{
				   uint16_t answer = (uint16_t) state->a + (uint16_t) state->b + (uint16_t) state->cc.cy;
				   state->cc.z = ((answer & 0xff) == 0);
				   state->cc.s = ((answer & 0x80) != 0);
				   state->cc.cy = (answer > 0xff);
				   state->cc.p = Parity(answer & 0xff);
				   state->a = answer & 0xff;
				   break;
				}
		case 0x89: // ADC B (A <- A + C + CY)
				{
				   uint16_t answer = (uint16_t) state->a + (uint16_t) state->c + (uint16_t) state->cc.cy;
				   state->cc.z = ((answer & 0xff) == 0);
				   state->cc.s = ((answer & 0x80) != 0);
				   state->cc.cy = (answer > 0xff);
				   state->cc.p = Parity(answer & 0xff);
				   state->a = answer & 0xff;
				   break;
				}
		case 0x8a: // ADC B (A <- A + D + CY)
				{
				   uint16_t answer = (uint16_t) state->a + (uint16_t) state->d + (uint16_t) state->cc.cy;
				   state->cc.z = ((answer & 0xff) == 0);
				   state->cc.s = ((answer & 0x80) != 0);
				   state->cc.cy = (answer > 0xff);
				   state->cc.p = Parity(answer & 0xff);
				   state->a = answer & 0xff;
				   break;
				}
		case 0x8b: // ADC B (A <- A + E + CY)
				{
				   uint16_t answer = (uint16_t) state->a + (uint16_t) state->e + (uint16_t) state->cc.cy;
				   state->cc.z = ((answer & 0xff) == 0);
				   state->cc.s = ((answer & 0x80) != 0);
				   state->cc.cy = (answer > 0xff);
				   state->cc.p = Parity(answer & 0xff);
				   state->a = answer & 0xff;
				   break;
				}
		case 0x8c: // ADC B (A <- A + H + CY)
				{
				   uint16_t answer = (uint16_t) state->a + (uint16_t) state->h + (uint16_t) state->cc.cy;
				   state->cc.z = ((answer & 0xff) == 0);
				   state->cc.s = ((answer & 0x80) != 0);
				   state->cc.cy = (answer > 0xff);
				   state->cc.p = Parity(answer & 0xff);
				   state->a = answer & 0xff;
				   break;
				}
		case 0x8d: // ADC B (A <- A + L + CY)
				{
				   uint16_t answer = (uint16_t) state->a + (uint16_t) state->l + (uint16_t) state->cc.cy;
				   state->cc.z = ((answer & 0xff) == 0);
				   state->cc.s = ((answer & 0x80) != 0);
				   state->cc.cy = (answer > 0xff);
				   state->cc.p = Parity(answer & 0xff);
				   state->a = answer & 0xff;
				   break;
				}
		case 0x8e: // ADC B (A <- A + M + CY)
				{
				   uint16_t offset = (state->h << 8) | state->l;
				   uint16_t answer = (uint16_t) state->a + (uint16_t) state->memory[offset] + (uint16_t) state->cc.cy;
				   state->cc.z = ((answer & 0xff) == 0);
				   state->cc.s = ((answer & 0x80) != 0);
				   state->cc.cy = (answer > 0xff);
				   state->cc.p = Parity(answer & 0xff);
				   state->a = answer & 0xff;
				   break;
				}
		case 0x8f: UnimplementedInstruction(state); break;
		case 0x90: UnimplementedInstruction(state); break;
		case 0x91: UnimplementedInstruction(state); break;
		case 0x92: UnimplementedInstruction(state); break;
		case 0x93: UnimplementedInstruction(state); break;
		case 0x94: UnimplementedInstruction(state); break;
		case 0x95: UnimplementedInstruction(state); break;
		case 0x96: UnimplementedInstruction(state); break;
		case 0x97: UnimplementedInstruction(state); break;
		case 0x98: UnimplementedInstruction(state); break;
		case 0x99: UnimplementedInstruction(state); break;
		case 0x9a: UnimplementedInstruction(state); break;
		case 0x9b: UnimplementedInstruction(state); break;
		case 0x9c: UnimplementedInstruction(state); break;
		case 0x9d: UnimplementedInstruction(state); break;
		case 0x9e: UnimplementedInstruction(state); break;
		case 0x9f: UnimplementedInstruction(state); break;
		case 0xa0: UnimplementedInstruction(state); break;
		case 0xa1: UnimplementedInstruction(state); break;
		case 0xa2: UnimplementedInstruction(state); break;
		case 0xa3: UnimplementedInstruction(state); break;
		case 0xa4: UnimplementedInstruction(state); break;
		case 0xa5: UnimplementedInstruction(state); break;
		case 0xa6: UnimplementedInstruction(state); break;
		case 0xa7: UnimplementedInstruction(state); break;
		case 0xa8: UnimplementedInstruction(state); break;
		case 0xa9: UnimplementedInstruction(state); break;
		case 0xaa: UnimplementedInstruction(state); break;
		case 0xab: UnimplementedInstruction(state); break;
		case 0xac: UnimplementedInstruction(state); break;
		case 0xad: UnimplementedInstruction(state); break;
		case 0xae: UnimplementedInstruction(state); break;
		case 0xaf: UnimplementedInstruction(state); break;
		case 0xb0: UnimplementedInstruction(state); break;
		case 0xb1: UnimplementedInstruction(state); break;
		case 0xb2: UnimplementedInstruction(state); break;
		case 0xb3: UnimplementedInstruction(state); break;
		case 0xb4: UnimplementedInstruction(state); break;
		case 0xb5: UnimplementedInstruction(state); break;
		case 0xb6: UnimplementedInstruction(state); break;
		case 0xb7: UnimplementedInstruction(state); break;
		case 0xb8: UnimplementedInstruction(state); break;
		case 0xb9: UnimplementedInstruction(state); break;
		case 0xba: UnimplementedInstruction(state); break;
		case 0xbb: UnimplementedInstruction(state); break;
		case 0xbc: UnimplementedInstruction(state); break;
		case 0xbd: UnimplementedInstruction(state); break;
		case 0xbe: UnimplementedInstruction(state); break;
		case 0xbf: UnimplementedInstruction(state); break;
		case 0xc0: UnimplementedInstruction(state); break;
		case 0xc1: // POP B
				   state->c = (state->memory[state->sp] & 0xff);
				   state->b = (state->memory[state->sp + 1] & 0xff);
				   state->sp += 2;
				   break;
		case 0xc2: // JNZ
				   if (state->cc.z == 0)
					   state->pc = (opcode[2] << 8) | opcode[1];
				   else
					   state->pc += 2;
				   break;
		case 0xc3: // JMP
				   state->pc = (opcode[2] << 8) | opcode[1];
				   break;
		case 0xc4: // CNZ
				{
				   if (state->cc.z == 0)
				   {
					   uint16_t ret = state->pc + 2;
					   state->memory[state->sp - 1] = (ret >> 8) & 0xff;
					   state->memory[state->sp - 2] = (ret & 0xff);
					   state->sp -= 2;
					   state->pc = (opcode[2] << 8) | opcode[1];
				   }
				   else
				   {
					   state->pc += 2;
				   }
				   break;
				}
		case 0xc5: // PUSH B
				   state->memory[state->sp - 1] = (state->b & 0xff);
				   state->memory[state->sp - 2] = (state->c & 0xff);
				   state->sp -= 2;
				   break;
		case 0xc6: // ADI byte
				{
				   uint16_t answer = (uint16_t) state->a + (uint16_t) opcode[1];
				   state->cc.z = ((answer & 0xff) == 0);
				   state->cc.s = ((answer & 0x80) != 0);
				   state->cc.cy = (answer > 0xff);
				   state->cc.p = Parity(answer & 0xff);
				   state->a = answer & 0xff;
				   state->pc++;
				   break;
				}
		case 0xc7: // RST 0 (CALL 0x0)
				{
				   uint16_t ret = state->pc;
				   state->memory[state->sp - 1] = (ret >> 8) & 0xff;
				   state->memory[state->sp - 2] = (ret & 0xff);
				   state->sp -= 2;
				   state->pc = 0x0;
				   break;
				}
		case 0xc8: // RZ
				   if (state->cc.z != 0)
				   {
					   state->pc = state->memory[state->sp] | (state->memory[state->sp + 1] << 8);
					   state->sp += 2;
				   }
				   break;
		case 0xc9: // RET
				   state->pc = state->memory[state->sp] | (state->memory[state->sp + 1] << 8);
				   state->sp += 2;
				   break;
		case 0xca: // JZ
				   if (state->cc.z != 0)
					   state->pc = (opcode[2] << 8) | opcode[1];
				   else
					   state->pc += 2;
				   break;
		case 0xcb: break;
		case 0xcc: // CZ
				{
				   if (state->cc.z != 0)
				   {
					   uint16_t ret = state->pc + 2;
					   state->memory[state->sp - 1] = (ret >> 8) & 0xff;
					   state->memory[state->sp - 2] = (ret & 0xff);
					   state->sp -= 2;
					   state->pc = (opcode[2] << 8) | opcode[1];
				   }
				   else
				   {
					   state->pc += 2;
				   }
				   break;
				}
		case 0xcd: // CALL
				{
				   uint16_t ret = state->pc + 2;
				   state->memory[state->sp - 1] = (ret >> 8) & 0xff;
				   state->memory[state->sp - 2] = (ret & 0xff);
				   state->sp -= 2;
				   state->pc = (opcode[2] << 8) | opcode[1];
				   break;
				}
		case 0xce: // ACI
				{
				   uint16_t answer = (uint16_t) state->a + (uint16_t) opcode[1] + (uint16_t) state->cc.cy;
				   state->cc.z = ((answer & 0xff) == 0);
				   state->cc.s = ((answer & 0x80) != 0);
				   state->cc.cy = (answer > 0xff);
				   state->cc.p = Parity(answer & 0xff);
				   state->a = answer & 0xff;
				   state->pc++;
				   break;
				}
		case 0xcf: // RST 1 (CALL 0x8)
				{
				   uint16_t ret = state->pc;
				   state->memory[state->sp - 1] = (ret >> 8) & 0xff;
				   state->memory[state->sp - 2] = (ret & 0xff);
				   state->sp -= 2;
				   state->pc = 0x8;
				   break;
				}
		case 0xd0: // RNC
				   if (state->cc.cy == 0)
				   {
					   state->pc = state->memory[state->sp] | (state->memory[state->sp + 1] << 8);
					   state->sp += 2;
				   }
				   break;
		case 0xd1: // POP D
				   state->e = (state->memory[state->sp] & 0xff);
				   state->d = (state->memory[state->sp + 1] & 0xff);
				   state->sp += 2;
				   break;
		case 0xd2: // JNC
				   if (state->cc.cy == 0)
					   state->pc = (opcode[2] << 8) | opcode[1];
				   else
					   state->pc += 2;
				   break;
		case 0xd3: UnimplementedInstruction(state); break;	// special
		case 0xd4: // CNC
				{
				   if (state->cc.cy == 0)
				   {
					   uint16_t ret = state->pc + 2;
					   state->memory[state->sp - 1] = (ret >> 8) & 0xff;
					   state->memory[state->sp - 2] = (ret & 0xff);
					   state->sp -= 2;
					   state->pc = (opcode[2] << 8) | opcode[1];
				   }
				   else
				   {
					   state->pc += 2;
				   }
				   break;
				}
		case 0xd5: // PUSH D
				   state->memory[state->sp - 1] = (state->d & 0xff);
				   state->memory[state->sp - 2] = (state->e & 0xff);
				   state->sp -= 2;
				   break;
		case 0xd6: // SUI D8
				{
				   uint16_t answer = (uint16_t) state->a - (uint16_t) opcode[1];
				   state->cc.z = ((answer & 0xff) == 0);
				   state->cc.s = ((answer & 0x80) != 0);
				   state->cc.cy = (state->a < opcode[1]);
				   state->cc.p = Parity(answer & 0xff);
				   state->a = answer & 0xff;
				   state->pc++;
				   break;
				}
		case 0xd7: // RST 2 (CALL 0x10)
				{
				   uint16_t ret = state->pc;
				   state->memory[state->sp - 1] = (ret >> 8) & 0xff;
				   state->memory[state->sp - 2] = (ret & 0xff);
				   state->sp -= 2;
				   state->pc = 0x10;
				   break;
				}
		case 0xd8: // RC (Return if carry flag)
				   if (state->cc.cy != 0)
				   {
					   state->pc = state->memory[state->sp] | (state->memory[state->sp + 1] << 8);
					   state->pc += 2;
				   }
				   break;
		case 0xd9: break;
		case 0xda: // JC
				   if (state->cc.cy != 0)
					   state->pc = (opcode[2] << 8) | opcode[1];
				   else
					   state->pc += 2;
				   break;
		case 0xdb: UnimplementedInstruction(state); break; // special
		case 0xdc: // CC (CALL adr if CY)
				{
				   if (state->cc.cy != 0)
				   {
						uint16_t ret = state->pc + 2;
						state->memory[state->sp - 1] = (ret >> 8) & 0xff;
						state->memory[state->sp - 2] = (ret & 0xff);
						state->sp -= 2;
						state->pc = (opcode[2] << 8) | opcode[1];
				   }
				   else
				   {
					   state->pc += 2;
				   }
				   break;
				}
		case 0xdd: break;
		case 0xde: // SBI D8
				{
				   uint16_t answer = (uint16_t) state->a - (uint16_t) opcode[1] - (uint16_t) state->cc.cy;
				   state->cc.z = ((answer & 0xff) == 0);
				   state->cc.s = ((answer & 0x80) != 0);
				   state->cc.cy = (state->a < (opcode[1] + state->cc.cy));
				   state->cc.p = Parity(answer & 0xff);
				   state->a = answer & 0xff;
				   state->pc++;
				   break;
				}
		case 0xdf: // RST 3 (CALL 0x18)
				{
				   uint16_t ret = state->pc;
				   state->memory[state->sp - 1] = (ret >> 8) & 0xff;
				   state->memory[state->sp - 2] = (ret & 0xff);
				   state->sp -= 2;
				   state->pc = 0x18;
				   break;
				}
		case 0xe0: // RPO (Return is Parity flag is not set, Odd)
				   if (state->cc.p == 0)
				   {
					   state->pc = state->memory[state->sp] | (state->memory[state->sp + 1] << 8);
					   state->sp += 2;
				   }
				   break;
		case 0xe1: // POP H
				   state->l = (state->memory[state->sp] & 0xff);
				   state->h = (state->memory[state->sp + 1] & 0xff);
				   state->sp += 2;
				   break;
		case 0xe2: // JPO (Jump is Parity flag not set, Odd)
				   if (state->cc.p == 0)
				   {
					   state->pc = (opcode[2] << 8) | opcode[1];
				   }
				   else
				   {
					   state->pc += 2;
				   }
				   break;
		case 0xe3: // XTHL (swap L and (SP) and swap H and (sp+1))
				{
				   uint8_t h = state->h;
				   uint8_t l = state->l;
				   state->h = (state->memory[state->sp + 1] & 0xff);
				   state->l = (state->memory[state->sp] & 0xff);
				   state->memory[state->sp + 1] = h;
				   state->memory[state->sp] = l;
				   break;
				}
		case 0xe4: // CPO (Call adr if Parity flag is not set, Odd)
				{
				   if (state->cc.p == 0)
				   {
					   uint16_t ret = state->pc + 2;
					   state->memory[state->sp - 1] = (ret >> 8) & 0xff;
					   state->memory[state->sp - 2] = (ret & 0xff);
					   state->sp -= 2;
					   state->pc = (opcode[2] << 8) | opcode[1];
				   }
				   else
				   {
					   state->pc += 2;
				   }
				   break;
				}
		case 0xe5: // PUSH H
				   state->memory[state->sp - 1] = (state->h & 0xff);
				   state->memory[state->sp - 2] = (state->l & 0xff);
				   state->sp -= 2;
				   break;
		case 0xe6: // ANI
				{
				   uint8_t answer = state->a & opcode[1];
				   state->cc.z = ((answer & 0xff) == 0);
				   state->cc.s = ((answer & 0x80) != 0);
				   state->cc.cy = 0;
				   state->cc.p = Parity(answer & 0xff);
				   state->a = answer & 0xff;
				   state->pc++;
				   break;
				}
		case 0xe7: // RST 4 (CALL 0x20)
				{
				   uint16_t ret = state->pc;
				   state->memory[state->sp - 1] = (ret >> 8) & 0xff;
				   state->memory[state->sp - 2] = (ret & 0xff);
				   state->sp -= 2;
				   state->pc = 0x20;
				   break;
				}
		case 0xe8: // RPE (Return is Parity even)
				   if (state->cc.p != 0)
				   {
					   state->pc = state->memory[state->sp] | (state->memory[state->sp + 1] << 8);
					   state->sp += 2;
				   }
				   break;
		case 0xe9: // PCHL (Jump to address in H:L)
				   state->pc = (state->h << 8) | state->l;
				   break;
		case 0xea: // JPE (Jump if Parity Even)
				   if (state->cc.p != 0)
				   {
					   state->pc = (opcode[2] << 8) | opcode[1];
				   }
				   else
				   {
					   state->pc += 2;
				   }
				   break;
		case 0xeb: // XCHG (swap H and D and swap L and E)
				{
				   uint8_t h = state->h;
				   uint8_t l = state->l;
				   state->h = state->d;
				   state->l = state->e;
				   state->d = h;
				   state->e = l;
				   break;
				}
		case 0xec: // CPE (Call adr if Parity is Even)
				{
				   if (state->cc.p != 0)
				   {
					   uint16_t ret = state->pc + 2;
					   state->memory[state->pc - 1] = (ret >> 8) & 0xff;
					   state->memory[state->pc - 2] = (ret & 0xff);
					   state->sp -= 2;
					   state->pc = (opcode[2] << 8) | opcode[1];
				   }
				   else
				   {
					   state->pc += 2;
				   }
				   break;
				}
		case 0xed: break;
		case 0xee: // XRI
				{
				   uint8_t answer = state->a ^ opcode[1];
				   state->cc.z = ((answer & 0xff) == 0);
				   state->cc.s = ((answer & 0x80) != 0);
				   state->cc.cy = 0;
				   state->cc.p = Parity(answer & 0xff);
				   state->a = answer & 0xff;
				   state->pc++;
				   break;
				}
		case 0xef: // RST 5 (CALL 0x28)
				{
				   uint16_t ret = state->pc;
				   state->memory[state->sp - 1] = (ret >> 8) & 0xff;
				   state->memory[state->sp - 2] = (ret & 0xff);
				   state->sp -= 2;
				   state->pc = 0x28;
				   break;
				}
		case 0xf0: // RP (Return if positive)
				   if (state->cc.s == 0)
				   {
					   state->pc = state->memory[state->sp] | (state->memory[state->sp + 1] << 8);
					   state->sp += 2;
				   }
				   break;
		case 0xf1: UnimplementedInstruction(state); break;
		case 0xf2: UnimplementedInstruction(state); break;
		case 0xf3: UnimplementedInstruction(state); break;
		case 0xf4: UnimplementedInstruction(state); break;
		case 0xf5: UnimplementedInstruction(state); break;
		case 0xf6: UnimplementedInstruction(state); break;
		case 0xf7: UnimplementedInstruction(state); break;
		case 0xf8: UnimplementedInstruction(state); break;
		case 0xf9: UnimplementedInstruction(state); break;
		case 0xfa: UnimplementedInstruction(state); break;
		case 0xfb: UnimplementedInstruction(state); break;
		case 0xfc: UnimplementedInstruction(state); break;
		case 0xfd: UnimplementedInstruction(state); break;
		case 0xfe: UnimplementedInstruction(state); break;
		case 0xff: UnimplementedInstruction(state); break;
	}
	state->pc += 1;
	
	// TODO: return appropiate value...
	return 0;
}

int main(int argc, char** argv)
{
	uint16_t a = 0xC0;
	uint16_t b = 0x60;
	uint16_t c = a - b;

	printf("a:\t%X\t%d\t%X\t%d\n", a, a, (uint8_t)(a & 0xff), (int8_t)(a & 0xff));
	printf("b:\t%X\t%d\t%X\t%d\n", b, b, (uint8_t)(b & 0xff), (int8_t)(b & 0xff));
	printf("a-b\t%X\t%d\t%X\t%d\n", c, c, (uint8_t)(c & 0xff), (int8_t)(c & 0xff));

	return 0;
}
