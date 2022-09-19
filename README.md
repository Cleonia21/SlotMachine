# SlotMachine

# Installation

If SDL is not installed сopy paste the following code on your terminal:

```shell
git clone https://github.com/Cleonia21/SlotMachine.git && cd SlotMachine && bash script.sh && ./slot_machine
```

If SDL is installed you can simply do:

```shell
git clone https://github.com/Cleonia21/SlotMachine.git && cd SlotMachine && make && ./slot_machine
```

If after installing the library there is a problem with the paths to the header files,
then you can solve it by running the command in the terminal:

```shell
sdl2-config --cflags --libs
```
And changing the LIBS variable in the Makefile:
```
My variable:
LIBS	=	-I/usr/local/include/SDL2 -D_THREAD_SAFE -L/usr/local/lib -lSDL2 -lSDL2_image

You variable:
LIBS	=	[sdl2-config --cflags --libs] -lSDL2 -lSDL2_image
```
