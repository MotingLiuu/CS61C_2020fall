1.2
Maximum allowable hold time for regc is 14ns
Minimum acceptable clock cycle time is 25ns

2.1
PCsel: select wether use pc+4 or result of ALU as the next pc, PC+4, PC+imm
RegWEn: Wether write to RegFile
ImmSel: select the type of Imm 
BrEq: whether the two input of comparator are equal
BrLt: whether input A of comparator is less than input B of comparator
ALUSel: select the type of computation executed in ALU
MemRW: whether write to Mem
WBSel: selec the data written to register file, DMEM outpu, ALU output, pc+4

2.2
ori: * * 0 I * 0 1 or 0 1 1
lw: * * pc+4 I * 0 1(imm) add 0 1 mem
sw: * * 0 S * 0 1 add 1 0 *
beq: 0 * 0 * * * * * 0 0 *
beq: 1 * 1(alu) B * 1(pc) imm add 0 0 *
jal: * * 1(alu) J * pc imm add 0 1 2
blt: * 0 0 * * * * * 0 0 *
blt: * 1 alu B 0 pc imm add 0 0 *

3.
3.1
add: x x x  x
ori: xxx x
lw: xxxxx
sw: xxxx
beq: xxx 
jal: xxx x

3.2
jal: Clk-to-Q+IMEM+ImmGen,RegFile+mux+ALU+mux+setup = 5+300+45+15+100+15+20 = 500
lw: Clk-to-Q+IMEM+ImmGen,RegFile+mux+ALU+DMEM Read+mux+setup = 5+300+45+15+100+300+15+20 = 800
sw: Clk-to-Q+IMEM+ImmGen,RegFile+mux+ALU+DMEM Setup = 5+300+45+15+100+200 = 665

3.3
lw

3.4
1/800ns

3.5
The critical path containing most of components

3.6
add register between different stage. Increase the frequency of cpu, do different stage at a same time.

