set -e
zig cc -Weverything -Werror -O2 -shared giraffe.c -lc -o libgiraffe.so
zig cc -Weverything -Werror -Wno-unsafe-buffer-usage -Wno-switch-enum -O2 main.c cat.c dog.c animal.c -lc -o main
./main
objdump -M intel --disassembler-color=color --disassemble=Animal_vocalize main
