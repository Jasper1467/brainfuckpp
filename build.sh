if [ ! -d out ]; then
    mkdir out
fi

g++ -Wall -Werror -std=c++20 -fuse-ld=mold -c brainfuck.h -o out/brainfuck.o

g++ -Wall -Werror -std=c++20 -fuse-ld=mold -c main.cpp -o out/main.o

mold out/brainfuck.o out/main.o -o out/brainfuck