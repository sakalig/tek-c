# tek-c
A text editor in C

## Prerequisites
This project was compiled under the following conditions:
- GCC 15 (-std=gnu23)

## Controls
Handling operations at current state.
These are helpful while canonical mode is enabled
- `Ctrl+D` - Send EOT signal (Closes program)
- `reset` (then press `Enter`) - In case terminal output is still not present after exiting the program
- `Ctrl+Z` - Suspends program to background | `fg` - brings back to foreground