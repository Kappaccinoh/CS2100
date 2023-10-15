#include "mips.h"

/******************************************************************************
 *      DO NOT MODIFY THE CODE BELOW
 ******************************************************************************/
#ifndef CS2100_ROUTINE_MASK_OUT
uint32_t _PC;
int32_t _RF[32]                   = {0};
int32_t _DataMemory[MAX_MEM >> 2] = {0};

// All the control signals needed
bool _RegDst;
bool _ALUSrc;
bool _MemtoReg;
bool _RegWrite;
bool _MemRead;
bool _MemWrite;
bool _Branch;
uint8_t _ALUOp;
uint8_t _ALUCtrl;

void RegFile(uint8_t RR1, uint8_t RR2, uint8_t WR, int32_t WD, int32_t* RD1,
             int32_t* RD2, bool RegWrite) {
    // Because we need to send out multiple outputs,
    // we will use passing by pointers.
    *RD1 = (RR1 > 0) ? _RF[RR1] : 0;
    *RD2 = (RR2 > 0) ? _RF[RR2] : 0;

    if (RegWrite && WR) _RF[WR] = WD;
}

int32_t Memory(uint32_t Address, int32_t WrData, bool MemRead, bool MemWrite) {
    // We can do a sanity check here.
    // You can at most do one memory operation.
    // Will assume that "error" raises hell.
    if (MemRead && MemWrite) {
        error("Cannot do both read and write at the same time.");
    }

    if (!(MemRead || MemWrite)) {
        return 0;
    }

    if ((Address > MAX_MEM) || (Address > MAX_MEM)) {
        error("Address %u is out of range. Simulator exiting...\n", Address);
    }

    if (MemRead) {
        return _DataMemory[Address >> 2];
    }

    if (MemWrite) {
        _DataMemory[Address >> 2] = WrData;
    }

    return 0;
}
#endif
/******************************************************************************
 *      DO NOT MIDIFY THE CODE ABOVE
 ******************************************************************************/

// Here starts your code for Assignment 2 Part A
// If you need to define some macros, you can do so below this comment.

#ifndef ASSIGNMENT2_QUESTION1A

uint8_t mux_u8(bool ctrl, uint8_t in0, uint8_t in1) {
    return ctrl ? in1 : in0;
}

uint32_t mux_u32(bool ctrl, uint32_t in0, uint32_t in1) {
    return ctrl ? in1 : in0;
}

int32_t mux_i32(bool ctrl, int32_t in0, int32_t in1) {
    return ctrl ? in1 : in0;
}

#endif  // End of Assignment 2, Question 1a

#ifndef ASSIGNMENT2_QUESTION1B

void decode(uint32_t in, struct instr* insn) {
    insn->opcode = in >> (32 - 6);
    insn->rs = (in >> (32 - 11)) & 31;
    insn->rt = (in >> (32 - 16)) & 31;
    insn->rd = (in >> (32 - 21)) & 31;
    insn->shamt = (in >> (32 - 26)) & 31;
    insn->funct = in & 63;
    insn->immed = (in >> (32 - 16)) & 65535;
    insn->address = (in << 6) >> 6;
}

#endif  // End of Assignment 2, Question 1b

#ifndef ASSIGNMENT2_QUESTION2A

void Control(uint8_t opcode, bool* _RegDst, bool* _ALUSrc, bool* _MemtoReg,
             bool* _RegWrite, bool* _MemRead, bool* _MemWrite, bool* _Branch,
             uint8_t* _ALUOp) {
    if (opcode == 0) *_RegDst = 1;
    else *_RegDst = 0;

    if (opcode == 0 || opcode == 35) *_RegWrite = 1;
    else *_RegWrite = 0;

    if (opcode == 0 || opcode == 4) *_ALUSrc = 0;
    else *_ALUSrc = 1;

    if (opcode == 35) {
        *_MemRead = 1;
        *_MemtoReg = 1;
    } else {
        *_MemRead = 0;
        *_MemtoReg = 0;
    }

    if (opcode == 43) *_MemWrite = 1;
    else *_MemWrite = 0;

    switch (opcode) {
        case 0: *_ALUOp = 2;
            break;
        case 35:
        case 43:
            *_ALUOp = 0;
            break;
        case 4:
            *_ALUOp = 1;
            break;
        default:
            break;
    }

    if (opcode == 4) *_Branch = 1;
    else *_Branch = 0;
}

#endif  // End of Assignment 2, Question 2a

#ifndef ASSIGNMENT2_QUESTION2B

uint8_t ALUControl(uint8_t ALUOp, uint8_t funct) {
    if (ALUOp == 2) { // R Format Instructions
        switch (funct) {
            case 32:
                return 2;
            case 34:
                return 6;
            case 36:
                return 0;
            case 39:
                return 12;
            case 37:
                return 1;
            case 42:
                return 7;
        }
    } else if (ALUOp == 1) { // BEQ Instruction
        return 6;
    } else { // lw/sw
        return 2;
    }
}

#endif  // End of Assignment 2, Question 2b

#ifndef ASSIGNMENT2_QUESTION2C

int32_t ALU(int32_t in0, int32_t in1, uint8_t ALUControl, bool* ALUiszero) {
    int32_t result;

    switch (ALUControl) {
        case 0: result = in0 & in1;
        case 1: result = in0 | in1;
        case 2: result = in0 + in1;
        case 6: result = in0 - in1;
        case 7: result = (in0 < in1) ? 1 : 0;
        case 12: result = ~(in0 | in1);
    }

    *ALUiszero = (result == 0) ? 1 : 0;

    return result;
}

#endif  // End of Assignment 2, Question 2c

#ifndef ASSIGNMENT2_QUESTION3

void execute(uint32_t insn) {

    // Stage 0 Update PC
    _PC += 4;

    // Stage 1 Decode - Convert Instruction and Populate 'instr' struct
    struct instr instr;
    decode(insn, &instr);


    // Stage 2 Execute
    // Set all the MUX control gates to their appropriate value based on the decoded opcode 
    Control(instr.opcode, &_RegDst, &_ALUSrc, &_MemtoReg, &_RegWrite, &_MemRead, &_MemWrite, &_Branch, &_ALUOp);
    // Set the ALU Control Signal to the appropriate signal based on the ALUOp and the Instruction Function
    _ALUCtrl = ALUControl(_ALUOp, instr.funct);


    // Setting the correct outputs of the file register
    int32_t* RD1;
    int32_t* RD2;
    uint8_t WR = mux_u8(_RegDst, instr.rt, instr.rd);
    int32_t WD;

    // Read Register - Note that WD is not written yet, we will write it later
    // once the value of WD has been determined - still impt because this step
    // writes the values of RD1 and RD2, which are inputs for the ALU
    RegFile(instr.rs, instr.rd, WR, WD, RD1, RD2, _RegWrite);

    // Configuring ALU with the correct signals
    bool* _ALUisZero;
    int32_t ALUResult = ALU(*RD1, *RD2, _ALUCtrl, _ALUisZero);


    // Stage 3 Memory
    int32_t MemOutput = Memory(ALUResult, *RD2, _MemRead, _MemWrite);


    // Stage 4 WriteBack
    RegFile(instr.rs, instr.rd, WR, mux_u32(_MemtoReg, ALUResult, MemOutput), RD1, RD2, _RegWrite);


    // Stage 5 Branch if BEQ
    _PC = mux_u32(*_ALUisZero == 1 && _Branch == 1, _PC, (_PC + (instr.immed << 2)));
}

#endif  // End of Assignment 2, Question 3
