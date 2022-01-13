
// command to run the program with customized hex code
cat exploit.txt | ./hex2raw | ./ctarget -q
// command to debug in gdb
run exploit.txt > ./hex2raw -q
// disassemble the binary file to asm
objdump -d ctarget > ctarget.d
