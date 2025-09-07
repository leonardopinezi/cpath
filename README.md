# Cpath Library

Cpath is a lightweight terminal-based graphics library with **real-time keyboard input** using ANSI escape codes. It's perfect for creating **games, interactive interfaces**, or visual prototypes directly in the terminal.

---

## Features

- ✅ Easy to use and integrate into C projects
- ✅ Optimized for fast terminal rendering
- ✅ Supports colors, rectangles, and lines
- ✅ Real-time keyboard input
- ✅ Fully open-source and customizable
- ✅ Works on modern Linux/Unix terminals

---

## Installation

Clone the repository and compile:

```bash
git clone https://github.com/your-username/cpath.git
cd cpath
gcc demo.c cpath.c -o demo
./demo
```

> Note: Currently works on Linux/Unix terminals. Windows support requires adaptation.

---

## Usage

Include the header in your project:

```c
#include "cpath.h"
```

### Initialize and finalize

```c
init_cpath(); // Prepare terminal for drawing
...
end_cpath();  // Restore terminal settings
```

### Basic drawing

```c
draw_rect(x, y, width, height, color);
draw_hline(x, y, width, color);
draw_text(x, y, "Hello World!");
```

### Keyboard input

```c
char c;
if(read(STDIN_FILENO, &c, 1) == 1) {
    if(c == 'q') break;
}
```

### Quick example

```c
int main() {
    init_cpath();
    draw_rect(10, 5, 20, 3, 2); // draw a rectangle
    char c;
    while(1) {
        if(read(STDIN_FILENO, &c, 1) == 1 && c == 'q') break;
    }
    end_cpath();
}
```

---

## Planned Features

- Mouse support and clickable interactions
- Advanced layout functions (centering, borders, tables)
- More terminal shapes and effects

---

## License

This project is **open source**. You are free to use, modify, and distribute it.

