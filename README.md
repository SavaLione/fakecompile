```
   __      _                                      
  / _|    | |                                     
 | |_ __ _| | _____                               
 |  _/ _` | |/ / _ \                     _ _      
 | || (_| |   <  __/                    (_) |     
 |_| \__,_|_|\_\___|___  _ __ ___  _ __  _| | ___ 
               / __/ _ \| '_ ` _ \| '_ \| | |/ _ \
              | (_| (_) | | | | | | |_) | | |  __/
               \___\___/|_| |_| |_| .__/|_|_|\___|
                                  | |             
                                  |_|
```
Simple compiler emulation application

## How to use?

1) Download or compile the required version of fake compile

For Linux:

    $ ./fakecompile --make

For Windows:

    $ fakecompile.exe --make

Program Assistance:

    $ ./fakecompile -h
    or
    $ fakecompile.exe -h

## How to build a project

### Dependencies

* **[CMake](http://www.cmake.org/) 2.8.3**+ (compile-time only)
* **[cxxopts](https://github.com/jarro2783/cxxopts) v2.1.2**+ (The library is already connected to the project)

### Compile

For Linux:

    $ git clone https://github.com/SavaLione/fakecompile.git
    $ cd fakecompile
    $ mkdir build && cd build
    $ cmake ..
    $ make

For Windows:

    $ git clone https://github.com/SavaLione/fakecompile.git
    $ cd fakecompile
	$ mkdir build && cd build
    $ cmake .. -G "MinGW Makefiles"
    $ mingw32-make

## Examples

[An example of using fakecompile with time](examples/example_with_time.md)

[Linux compile fakecompile](examples/compile_on_linux.md)