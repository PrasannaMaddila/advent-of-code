# advent-of-code
This is my attempt for Advent of Code using C++. I will probably shift back to Python at some point, stop me before I do that :)

## Build System 

The current build system is ingenious. We build the solution for Day _<day_number>_ ( and optionally the year _<yr_number>_ ) using the following command.

```bash 
make build DAY=<day_number> ( YEAR=<yr_number> )
```

This places the solution executable in [build/](build/), and the relevant call to `make run DAY=<day_number>` will execute the file. `make run` will print the answers out. Similarly, 

```bash 
make bench DAY=<day_number> ( YEAR=<yr_number> )
```

will benchmark the code. This will not print out the answers out. 


## Solution Structure 

Each solution is actually implemented as a header ! Furthermore, on the completed implementation of each file, we tag it with a #define as follows: 

```cpp 
#define PART_1
int part1() {
    ...
}
```

Then, depending on the mode ( `run` vs `bench` ), we link these headers to different main files, found in [utils/](utils/). Each of these main files checks for these constants, and executes the part that they detect. 
