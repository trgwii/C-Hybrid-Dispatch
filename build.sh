set -e
zig cc -Weverything -Werror -O2 -shared giraffe.c -lc -o libgiraffe.so
objdump -M intel --disassembler-color=color --visualize-jumps=extended-color --no-addresses --no-show-raw-insn --section=.text --disassemble libgiraffe.so
zig cc -Weverything -Werror -Wno-unsafe-buffer-usage -Wno-switch-enum -O2 main.c cat.c dog.c animal.c -lc -o main
objdump -M intel --disassembler-color=color --visualize-jumps=extended-color --no-addresses --no-show-raw-insn --section=.text --disassemble=main -S main
./main
zig cc -Weverything -Werror -Wno-unsafe-buffer-usage -Wno-switch-enum -DDISPLAY_ASM -O2 main.c cat.c dog.c animal.c -lc -o main
objdump -M intel --disassembler-color=color --visualize-jumps=extended-color --no-addresses --no-show-raw-insn --section=.text --disassemble=Animal_vocalize main
