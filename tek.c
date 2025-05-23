// LIBS
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>

// DEFINES
#define CTRL_KEY(k) ((k) & 0x1f)

// TODO: Semantic versioning
#define _VERSION "0.0.1"

// Enums for keys

// DATA PACKAGERS
struct termios orig_termios;

// TERMINAL
void die(const char *s) {
    perror(s);
    exit(1);
}

void disableRawMode() {
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios) == -1)
        die("tcsetattr");
}

void enableRawMode() {
    if (tcgetattr(STDIN_FILENO, &orig_termios) == -1) die("tcgetattr");
    atexit(disableRawMode);

    struct termios raw = orig_termios;

    raw.c_iflag &= ~(IXON | ICRNL);
    raw.c_oflag &= ~(OPOST);
    raw.c_lflag &= ~(ECHO | ICANON | ISIG);
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 1;

    // TODO: Test leftover input effect in cygwin
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) ==-1) die("tcsetattr");
}

char editorReadKey() {
    int nread;
    char c;
    while ((nread = read(STDIN_FILENO, &c, 1)) != 1) {
        if (nread == -1 && errno != EAGAIN) die("read"); // error & resource availability
    }
    printf("%cq\r\n", c);
    return c;
}

// OUTPUT
void editorRefreshScreen() {
    write(STDOUT_FILENO, "\x1b[2J", 4);
}

// INPUT
void editorProcessKeypress() {
    char c = editorReadKey();

    switch (c) {
        case CTRL_KEY('q'):
            exit(0);
            break;
    }
}
// Move cursor + Maintain bounds wiithin window border + PageUp/PageDown to simulate fullscreen scrolls + Home/End cursor movement + Check for delete key press

// INIT
int main() {
    enableRawMode();

    // Foundation: screen refresh logic

    while (1) {
        editorRefreshScreen();
        editorProcessKeypress();
    }
    return 0;
}