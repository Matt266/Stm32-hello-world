# Stm32-hello-world
Bare Metal "Hello World!"-Project for Stm32f401re Nucleo board.
A LED blinks at about 0.5 Hz and "HELLO WORLD!" is displayed by a SH1106 module via i2c.

This projected served the purpose of developing a better understanding about how 
the arm toolchain, interrupts and peripheral registers work.
For this sake I didn't use any libraries (not even the standard one).

The linker script provided is a own take based on the scripts that can be found online.
As the work that needs to be done by the script is nearly the same it looks similiar
to those or is even identical for larger parts. I learned a lot while creating it so
I don't think of this is a problem but definitely something I wanted to note.

The code written includes flaws which I didn't correct as they don't further affect
the educational value it provides for me. For the biggest ones I added comments 
explaining why the implementation is bad and ideas how to improve it.
