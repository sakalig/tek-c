# tek-c
A text editor in C

## Prerequisites
This project was compiled under the following conditions:
- GCC 15 (-std=gnu23)

## Controls
Handling operations at current state.
These are helpful while canonical mode is enabled
- `Ctrl+D` - Send EOT signal (Closes program)<br>[Current Status: **Disabled**]
- `reset` (then press `Enter`) - In case terminal output is still not present after exiting the program<br>[Current Status: **Disabled**]
- `Ctrl+Z` - Suspends program to background | `fg` - brings back to foreground. (MacOS can be problematic with resuming a background job after keying in `fg`. Might be due to `read` function receiving **-1**)<br>[Current Status: **Disabled**]
- `Ctrl+S` - Suspends program flow control(XOFF). Resumed by `Ctrl+Q`(XON)<br>[Current Status: **Disabled**]
- `Ctrl+V` - Gives brief interval for inputting a key sequence before sending it literally. Flag(local): `IEXTEN`<br>[Current Status: **Enabled**]
- `Ctrl+M` - Carriage return is read as its proper ASCII value. Disables automatic carriage returns<br>[Current Status: **Disabled**]