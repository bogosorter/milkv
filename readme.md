# Milk-V Duo S Experiments

This repository contains the code for a few experiments on the RISC-V processor of the Milk-V Duo S:

- `add` is a simple addition program which uses the RISC-V `add` routine in the C code.
- `blink` uses the built-in led and blinks it in a loop.
- `external-blink` uses an external led connected to pin 16 and blinks it in a loop.
- `display` displays all the digits in sequence in a 7-segment display connected to the board.
- `fibonacci` uses a RISC-V assembly routine to calculate a given Fibonacci number and displays the result in the 7-segment display.

## General Workflow

The Milk-V should be plugged in. This will add an ethernet interface to the computer, which can be used to ssh into the board. By default, the board's IP is `192.168.42.1`, the username is `root` and the password is `milkv`. The code should be compiled on the computer and then copied to the board using `scp`.

## Simple Scripts and RISC-V Compilation

Plain C and assembly code execution on the Milk-V Duo is straightforward with `gcc-riscv64-linux-gnu`. For reasons I don't really understand, the library linking must be static. This is how it would look like for the `add` example:

```
$ apt install gcc-riscv64-linux-gnu
$ cd add
$ riscv64-linux-gnu-gcc add.c add.s -o add -static
```

We are now ready to copy the `add` executable to the board:

```
$ scp add root@192.168.42.1:/root
```

Finally, we need to ssh into the board and run the executable:

```
$ ssh root@192.168.42.1
$ ./add # /root is already the default directory
```

## Using I/O Pins

Using the Milk's I/O pins is a lot more complex. The easiest method I found was to follow the strategy used by [duo-examples](https://github.com/milkv-duo/duo-examples). Note that it requires an Ubuntu 20.04 docker image with `git` and `make`. Once the image is setup, you should clone both the `duo-examples` repository and my own repository, which contains the code for the experiments.

To install the toolchain, `cd` into the `duo-examples` repository and source from `envsetup.sh`. At both questions, the second option should be chosen (`Duo256M (SG2002) or DuoS (SG2000)` and `RISCV64`). This process will take a while.

Once this process is complete, you can try some of the other example programs, starting with `blink`:

```
$ cd blink
$ make
$ scp blink root@192.168.42.1:/root
```

```
$ ssh root@192.168.42.1
$ ./blink
```

`fibonacci` combines all of the discussed features in one. It uses an assembly routine to calculate a given Fibonacci number and displays it onto the 7-segment display (as long as it has one single digit).

> The pins used in the experiments are specified as macros. The physical location of those pins is described in the [official documentation](https://milkv.io/docs/duo/getting-started/duos#duos-gpio-pinout).