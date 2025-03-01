# Simple Clock :3

This is a simple clock application built with SDL3 and C++. It displays the current time in a transparent window.

**Features:**

* Displays the current time in HH:MM:SS format.
* Uses SDL3 for cross-platform windowing and rendering (primarily tested on Linux).
* Transparent window with a clean, minimal design.
* Configurable window position through Hyprland window rules.

**Prerequisites:**

* A C++ compiler (e.g., g++)
* SDL3 development libraries (including SDL3\_ttf)
* Electroharmonix.otf font, installed in /usr/share/fonts
* Make (for build automation)
* Linux operating system.
* Hyprland (if you want to configure the window position using the window rules).

**Building:**

1.  Clone the repository to your local machine.
2.  Open a terminal and navigate to the project directory.
3.  Run `make` or `make all` to compile the project. This will create an executable file named `SimpleClock :3`.

    ```bash
    make
    ```

**Running:**

1.  After successful compilation, execute the `SimpleClock :3` file from your terminal:

    ```bash
    ./SimpleClock\ :3
    ```

**Hyprland Configuration (Optional):**

If you are using Hyprland, you can customize the clock's position and behavior using window rules. Add the following rules to your `hyprland.conf` file (typically located at `~/.config/hypr/hyprland.conf`):

```ini
windowrulev2 = noborder, title:^([Cc]lock_app)$
windowrulev2 = noblur, title:^([Cc]lock_app)$
windowrulev2 = nofocus, title:^([Cc]lock_app)$
windowrulev2 = noanim, title:^([Cc]lock_app)$
windowrulev2 = float, title:^([Cc]lock_app)$
windowrulev2 = pin, title:^([Cc]lock_app)$
windowrulev2 = position 100 100, title:^([Cc]lock_app)$ # Adjust position as needed
