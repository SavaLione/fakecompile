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

1) Download or compile the required version of fakecompile
2) Select the desired compiler type
    
    You can view compilers through the program's help.

    (-h or --help)
3) Select the speed and time of the program

```
    -t                  --time  - Program runtime in seconds (not accurate)
    --time_sleep_MIN            - Minimum row rendering time in milliseconds
    --time_sleep_MAX            - Maximum row rendering time in milliseconds
```
    (You can run the program without these parameters. In this case, the program will run indefinitely.)

4) Run the program

Example:

```
For Linux:
    $ ./fakecompile -t --time_sleep_MAX 700 --make
    or
    $ ./fakecompile --cmake
```

```
For Windows:
    $ fakecompile.exe -t --time_sleep_MAX 700 --make
    or
    $ fakecompile.exe --cmake
```

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

## Todo

### Compilers

- [x] make
- [x] CMake

### Opportunities

- [x] time support
- [ ] error support