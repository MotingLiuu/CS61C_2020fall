1.5

Speedup = 1 / (0.2 + 0.1) = 3.33

1.6

5

1.7

The critical section decide the upbound of the speedup

2.1

true

2.2

false

2.3

false

2.4

false

3.1

a) 
16MiB = 2e4 * 2e10KiB = 2e14 KiB = 2e24 B
1MiB = 2e20 B
1024 B = 2e10 B

VPN: 14bits
PPN: 10bits
Offset: 10bits
Number os PTEs: 2e14
Page Table Size: 2e14 2e2 B = 2e16 B

b)
512MiB = 2e5 * 2e24 B = 2e29 B
32KiB = 2e5 KiB = 2e15 B
512B = 2e9 B

VPN: 20bits
PPN: 6bits
Offset: 9bits
Number of PTEs: 2e20
Page Table Size: 2e20 2e2 B = 2e22 B


3.4

4KiB = 2e12 B

2e18

3.5
a)
VPN: 0x51B
Offset: 0x38
b)
PPN: 0xB1
Offset: 0xDC

3.6
1. Illusion of access to entire address space
2. Avoids meme address conflict between programs
3. Enforces protection between processes and within a process

4
4.1

y n 0x483
y y 0x61C
y n 0xF01
n 
y y 0x7CB
n 

4.2
a)
0x000429 VPN: 0x0004

Hit

b)
0x00018D VPN: 00018D

hit

c)
0x000345 VPN: 0003

page fault


4.3

0x100000 = 0x100010

4.4

add Read-only status
