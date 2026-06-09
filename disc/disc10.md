1.1
8 bytes are a blocks. offset bits is 0-2.

4 blocks in total.
direct-mapped cache. index bits is 3-4.

tag bits are the remaining bits 5-31.


1.2
0x00000004 miss M compulsory C. Load 0x00000000 - 0x00000007 to the 0 block.
0x00000005 hit. H
0x00000068 miss M compulsory C. Load 0x00000060 - 0x00000067 to the 1st block.
0x000000C8 miss M compulsory C. Load 0x000000C0 - 0x000000C7 to the 1st block.
0x00000068 miss M Noncompulsory NC. Load 0x00000060 - 0x00000067 to the 1st block.
0x000000DD miss M compulsory C. Load 0x000000D8 - 0x000000DF to the 1st block.
0x00000045 miss M compulsory C. Load 0x00000040 - 0x00000047 to the 0st block.
0x000000CF miss M Noncompulsory NC. Load 0x000000C8 - 0x000000CF to the 1st block.
0x000000F3 miss M compulsory C. Load 0x000000F0 - 0x000000F7 to the 2st block.


2.1
0b0000 0100 miss M compulsory C. load 0b0000 0000 - 0b0000 0111 to the 0st block.
0b0000 0101 hit. H
0b0110 1000 miss M compulsory C. load 0b0110 1000 - 0b0110 1111 to the 1st block.
0b1100 1000 miss M compulsory C. load 0b1100 1000 - 0b1100 1111 to the 1st block.
0b0110 1000 hit. H
0b1101 1101 miss M compulsory C. load 0b1101 1000 - 0b1101 1111 to the 1st block.
0b0100 0101 miss M compulsory C. load 0b0100 0000 - 0b0100 0111 to the 0st block.
0b0000 0100 hit. H
0b0011 0000 miss M compulsory C. load 0b0010 0000 - 0b0010 0111 to the 0st block.
0b1100 1011 miss M compulsory C. load 0b1100 1000 - 0b1100 1111 to the 1st block.
0b0100 0010 miss M Noncompulsory NC.

2.2
hit rate is 3/11


3.1
1MB = 1024KB = 2e10KiB = 2e10 2e10B = 2e20bits
20bits

3.2
1KiB blocks = 2e10bits
offset bits = 0-10
index bits = 11-14
tag bits = 15-20


3.3
0.5


3.4
0.5


4.1
25 + 0.25 * 100 = 50

4.2
0.2

4.3
0.4

4.4
local miss rate = 0.05 / 0.2 = 0.25

4.5
2 + 0.2*(15 + 0.25*100) = 2 + 8 = 10 

4.6
30 cycles

