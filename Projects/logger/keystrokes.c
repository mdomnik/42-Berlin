#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>
#include <unistd.h>

void simulateKeystroke(Display *display, KeySym keysym, unsigned int modifierMask) {
    KeyCode keycode = XKeysymToKeycode(display, keysym);
    
    // Simulate pressing the Shift key if the ShiftMask is set
    if (modifierMask & ShiftMask) {
        XTestFakeKeyEvent(display, XKeysymToKeycode(display, XK_Shift_L), True, modifierMask);
        XFlush(display);
    }

    // Simulate the keystroke with the specified modifierMask
    XTestFakeKeyEvent(display, keycode, True, modifierMask);
    XTestFakeKeyEvent(display, keycode, False, modifierMask);
    XFlush(display);

    // Simulate releasing the Shift key if the ShiftMask is set
    if (modifierMask & ShiftMask) {
        // Find the keycode for the Shift key and use it to release the key
        XTestFakeKeyEvent(display, XKeysymToKeycode(display, XK_Shift_L), False, modifierMask);
        XFlush(display);
    }
}

void moveMouse(Display *display, int x, int y) {
    XWarpPointer(display, None, DefaultRootWindow(display), 0, 0, 0, 0, x, y);
    XFlush(display);
}

void simulateLeftClick(Display *display) {
    XTestFakeButtonEvent(display, Button1, True, CurrentTime);
    XFlush(display);
    XTestFakeButtonEvent(display, Button1, False, CurrentTime);
    XFlush(display);
}

int main() {
    Display *display = XOpenDisplay(NULL);
    if (!display) {
        fprintf(stderr, "Unable to open display.\n");
        return 1;
    }

	while(1)
	{
		sleep(1);
    	moveMouse(display, 1750, 20);
    	simulateLeftClick(display);
		sleep(300);
    	simulateKeystroke(display, XK_A, ShiftMask);
    	simulateKeystroke(display, XK_a, 0);
    	simulateKeystroke(display, XK_1, 0);
    	simulateKeystroke(display, XK_1, ShiftMask);
    	simulateKeystroke(display, XK_Return, 0);
	}

    XCloseDisplay(display);
    return 0;
}
