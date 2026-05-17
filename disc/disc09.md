1
1.1
False

1.2
False

1.3
lw

1.4
Can not make full use of different components in the data-path

2
2.1
clk-to-q+MEM read+register read, immgen+mux+alu+MEM read+mux+setup
= 30+250+100+25+200+250+25+20
= 900ps
1/900ps = 1.111GHz

2.2
300ps

2.3
1, 1

2.4
3.33 1.11

2.5
3
because the frequency of pipelined cpu depends on the longest stage.
Additional registers

3
3.2
3 instructions
If we are allowed to assume write-then-read to registers , it would only affect 2 instructions

3.3
lw t1, 0(t0)
add t2, t1, x0 need the result of MEM at the begging of EX stage.
stall or just rearrange the order of instruction, put 1 under 3

3.4

3.5
If s0 is equal to s1, PC would be different from pc+4

3.6
just run, if s0 is equal to s1, go back to 2, the result of comparator would be able to access after EX

4
data hazard 1,2
data hazard 2,3
data hazard 2,4
control hazard 4

2
2
3

0



