# inpettopad
Used abriviations:
P/H = Press and Hold
S. Press = Press
d. press = Double Press
X/X = Row(In assembeled Key board) / Position in Row ( 0, 1, 2) ** 0 being all the way down/ to the left
r.t.l/r. = rotate to left/right

HackClub StarDance HackPad named after the colours of the logo of "Inpetto", an italian coffee brand. With features as focuses, a clock, and shortcuts to what one find usefull features.
User Manual and SetUP:
Functions:
   Display Lock (Key,0/0) [S. press -> Lock Display, d. press -> shutdown menu]
   ShortCut to Claude/AI of your choice (Key, 0/1) [S. press -> AI]
   ScreenShot(Key, 0/2) [S. press -> Screenshot, P/H -> Recording]
   AudioPlayer(Key, 1/1) [S. Press -> Play/pause, d. press -> previous Song, P/H -> Skip Song]
   Light Controle(Key, 1/2) [S. press -> Light toggle]ts and link it to either the application or a web link of your favourite AI.
    2. Light Controle:
       To set Up enter the KeyCombination (Left Command, Left Shift and L) in a new Shortcut in Apple Shortcuts 
   Focus Toggle(Key, 1/0) [S. press -> Focus toggle]
   Volume Controle(Rotary Encoder, Right) [r.t.r. -> Volume Up, r.t.l. -> Volume Down, S. press -> Mute Audio]
   FullScreen Toggle(Rotary Encoder, Left) [r.t.l/r. -> Switch to either Full or not-Full screen]
   Clock(Rotary Encoder, Left) [s. press -> Enter Clock setting mode THEN AFTER S.PRESS r.t.l/r -> Set Time]

SetUp: 
Due to non existing Keyboard Commands on MacOS some Functions have to be SetUp in Apple Shortcuts!!

    1. Shortcut to CLaude:
       To set Up enter the KeyCombination (Left Command, Left Shift and C) in a new Shortcut in Apple Shortcuand link it to Apple Home Smart Home remote conrole.
    3. Focus Toggle:
    To set Up enter the KeyCombination (Left Command, Left Shift and F) in a new Shortcut in Apple Shortcuts and set it to enable/disable your Focus of choice.


* Keyboard Maintainer: [Klemens Muth](https://github.com/KlemensMuth)
* Hardware Supported: Build for RP2040
* Hardware Availability: Please check: [text](https://hackpad.hackclub.com/)

Make example for this keyboard (after setting up your build environment):

    make inpettopad:default

Flashing example for this keyboard:

    make inpettopad:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
