zig build-lib -O ReleaseFast -dynamic giraffe.c -lc
zig build-exe -O ReleaseFast main.c cat.c dog.c animal.c -lc
./main
objdump -M intel --disassembler-color=color --disassemble=Animal_vocalize main
