# Hello!

In this project I hope to write a small program which can solve (simple) sudokus, and learn about ```C++``` and Object-Oriented Programming in the process

### Setting up.
#### 1. Installing [libcwd](https.//github.com/CarloWood/libcwd.git)
  1. #```apt install autoconf autoconf-archive automake libtool-bin libboost-all-dev``` install needed stuff in case you don't have it yet
  2. $```git clone https.//github.com/CarloWood/libcwd.git``` to download
  3. $```./autogen.sh``` to generate needed files  
    You might get an error, read it, and apply your new knowledge (you may need to re-run the previous step)
  4. Follow instructions
  5. $```make``` to compile libcwd
  6. #```make install``` install where you want it with (additional) flags/options
#### 2. Installing [this project](https.//github.com/FeniksComputerClub/sudoku.git)
  1. $```git clone https.//github.com/FeniksComputerClub/sudoku.git``` to git this project
  2. $```cd sudoku``` to go into the new directory
  3. $```./autogen.sh``` to generate needed files
  4. $```mkdir ../sudoku-objdir && cd ../sudoku-objdir```
  5. $```../sudoku/configure --enable-maintainter-mode``` to configure the makefile (and other stuff)
  6. $```make``` compile the project

Compiling with ```G++ 4.9.2``` standard. ```C++14```