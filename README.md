# Web development with Oberon based on CGI scripts

This example shows only a demonstration for Linux x64.

## Requirements

- A system working on Linux x64
- Go compiler
- C toolchain
- a terminal with the bash shell

## Demo

0. Clone this repository

```
git clone https://github.com/egorsmkv/oberon-cgi.git
cd oberon-cgi
```

1. Clone Ofront+ and re-build the translator

```
git clone https://github.com/Oleg-N-Cher/OfrontPlus.git
cd OfrontPlus
git checkout 21a72d80aee3b0caac60a5f2d27566cde2404d01
cd ./Target/Linux_amd64/Bin
export OBERON=.:../Lib/Sym:../Sym
./build
cd ../../../../
```

2. Set environment variables

```
export OTARGET=Linux_amd64
export OFRONT=`pwd`/OfrontPlus
export OTARGET_DIR=$OFRONT/Target/$OTARGET

export PATH=$PATH:$OTARGET_DIR

export OFRONT_MOD_LIB=$OFRONT/Mod/Lib
export OFRONT_LIB=$OTARGET_DIR/Lib
export OFRONT_OBJ=$OFRONT_LIB/Obj

export C_COMPILER_ARGS="-I$OFRONT_OBJ -I$OFRONT_MOD_LIB -L$OFRONT_LIB -lOfront"
export C_COMPILER="cc -m64 -Os -g0 -fvisibility=hidden -fomit-frame-pointer -finline-small-functions -fno-exceptions -fno-unwind-tables -fno-asynchronous-unwind-tables -Wl,--gc-sections"

export OBERON=`pwd`:$OTARGET_DIR/Bin:$OFRONT_LIB/Sym:$OFRONT_LIB
```

3. Translate the Oberon program to C

```
ofront+ -m -2 -88 ./examples/HelloWorld.ob2
```

4. Compile a "HelloWorld" program

```
mkdir compiled
$C_COMPILER HelloWorld.c -s -o compiled/HelloWorld $C_COMPILER_ARGS
```

5. Compile and run the HTTP/CGI server

```
go build -o server main.go

./server
```

6. Now you can go to your browser and type this address: http://localhost:8080/hello-world

You will see the same page:

<img src="./screen.png" width="400">

Also, this is an example of printing of environment variables that your CGI application can use:

<img src="./screen-envs.png" width="400">
