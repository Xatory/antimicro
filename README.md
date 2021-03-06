# antimicro

## Description

AntiMicro is a graphical program used to map keyboard keys and mouse controls
to a gamepad. This program is useful for playing PC games using a gamepad that
do not have any form of built-in gamepad support. However, you can use this 
program to control any desktop application with a gamepad; on Linux, this
means that your system has to be running an X environment in order to run
this program. This program is currently supported under various Linux
distributions and Windows Vista and later; this program should be able to run
under Windows XP but it has not been tested.

## License

This program is licensed under the GPL v.3. Please read the gpl.txt text document
included with the source code if you would like to read the terms of the license.
The license can also be found online at
[http://www.gnu.org/licenses/gpl.txt](http://www.gnu.org/licenses/gpl.txt).


## Build Dependencies

This program is written in C++ using the [Qt](http://qt-project.org/)
framework. A C++ compiler and a proper C++ build environment will need to be
installed on your system prior to building this program. Under Debian and
Debian-based distributions like Ubuntu, the
easiest way to get a base build environment set up is to install the
meta-package **build-essential**. The following packages are required to be
installed on your system in order to build this program:

* g++
* libqt4-dev
* libsdl1.2-dev (or libsdl2-dev)
* libxtst-dev
* libX11-dev


## Building under Linux

In order to build this program, open a terminal and cd into the antimicro/src
directory. Enter the following commands in order to build the program:

    cd antimicro/src
    qmake
    make
    sudo make install

The installation path of antimicro can be customized by specifying the
INSTALL_PREFIX variable while running qmake.

    qmake INSTALL_PREFIX=/usr

This will install the antimicro executable to /usr/bin/antimicro.
By default, the executable will be installed to /usr/local/bin/antimicro.

If you would like to compile the program to use SDL 2, you can use the
USE_SDL_2 variable while running qmake. By default, the program
will be compiled against SDL 1.2.x. That will likely change in the
future.

    qmake USE_SDL_2=1

## Building under Windows

**Instructions provided by aybe @ https://github.com/aybe**

* You will need Qt with MinGW support: http://qt-project.org/downloads

* download SDL development package : http://www.libsdl.org/release/SDL-devel-1.2.15-mingw32.tar.gz

* open the archive and drop the 'SDL-1.2.15' folder in the 'antimicro' folder

* open the project (antimicro.pro) in Qt Creator

* the first-time wizard selects MSVC as the default compiler, untick it and select MinGW instead

* set build to 'Release' (menu Build -> Open Build and Run Kit Selector) and 'Build All' (Ctrl+Shift+B)

* a 'build-antimicro-Desktop_Qt_5_1_1_MinGW_32bit-release/release' folder appears in 'antimicro' folder

* the application will need SDL.DLL, find it in SDL-1.2.15\bin folder and copy it next to it

* it will also need the following Qt DLLs that you will find inside C:\Qt\5.1.1\mingw48_32\bin

        icudt51.dll
        icuin51.dll
        icuuc51.dll
        libgcc_s_dw2-1.dll
        libstdc++-6.dll
        libwinpthread-1.dll
        Qt5Core.dll
        Qt5Gui.dll
        Qt5Network.dll
        Qt5Widgets.dll

* copy them next to the application executable

* last dependency is the Qt plugin platform 'qwindows.dll' located in C:\Qt\5.1.1\mingw48_32\plugins\platforms\

* create a sub-folder named 'platforms' and copy it there

* you have just built AntiMicro for Windows :D

##Building the Windows Installer Package (MSI)

(these instructions have been tested with WiX 3.8)

* you need to have WiX installed, grab it at http://wixtoolset.org/

* the building process relies on the WIX environment, it is recommended that you download the installer instead of the binaries as it it will set it up for you

* if Qt Creator is running while you install or upgrade to a newer version then make sure to restart it as it will either not find that environment variable or fetch the old (incorrect) value from the previous version

* to build the MSI package, add a 'Make Build Step' after a 'make install' step to the project and specify 'buildmsi' as the argument, at your convenience you'll disable/enable it as needed

* currently it relies on INSTALL to copy files at the location they are harvested, this might change in the future

Notes about the WXS file and the building process :

* the WXS file has been generated with WixEdit and manually modified to contain relative paths, it will only work from the 'windows' sub-folder (or any other)

* WixCop can be run against the WXS file and it should not point out any errors as the WXS has been corrected previously with the -F switch

* CNDL1113 warning : shortucts are advertised, left as-is as a nice feature about them is that if the program gets corrupted it will be repaired by Windows Installer, by design the shortcuts will not point to antimicro.exe as a regular LNK file

* LGHT1073 warning : SDL.DLL does not specify its language in the language column, not a big deal; it could be recompiled but it's pretty much a time waist as it would only prevent this warning

* all of these warnings have been made silent through the use of command-line switches.

* built MSI package will be placed in /windows

## Ideas For Future Features

This section is where some of the ideas for future features
for this program will be written.

* Setting to not display buttons that are not currently in use.
This will especially help people using a PS3 controller.
* Copy set assignments to a new set. This will make creating
slightly altered sets easier.
* A mouse setting that will move the mouse cursor to an exact spot on the
screen based on the position of an axis. This would work similar to spring
mode except that it will not automatically return the mouse cursor
to the center of the screen. This idea is mainly intended for the touchpad
on the PS4 controller.

Along with this, I will put the simple mind map that I am using to
write ideas for future development into the repository for this
program. The mind map will include extra notes that are not available in
this README. Opening the mind map will require the use of the program
FreeMind which can be downloaded from
[http://freemind.sourceforge.net/wiki/index.php/Main_Page](http://freemind.sourceforge.net/wiki/index.php/Main_Page).

## Shoutout

A big inspiration for this program was the program QJoyPad
([http://qjoypad.sourceforge.net/](http://qjoypad.sourceforge.net/)).
I was a user of the program for years and it is unfortunate that the
program is no longer being maintained. The source code for QJoyPad was an
invaluable resource when I made the first version of this program and the UI
for this program mostly resembles QJoyPad.

## Credits

Travis Nickles <nickles.travis@gmail.com>  
aybe

## Translators

Belleguic Terence <hizo@free.fr> - French  
Jay Alexander Fleming <tito.nehru.naser@gmail.com> - Serbian  
VaGNaroK <vagnarokalkimist@gmail.com> - Brazilian Portuguese
