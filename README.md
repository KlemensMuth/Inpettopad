# InpettoPad

The InpettoPad is a 6 Key Macropad featuring 2 rotary encoder,  
an OLED display and a built in clock feature! It´s using <br>
QMK Firmware and ONLY runs on MacOS.

# Features:

- Bottom and Top 3D Printed Case
- 128x32 OLED Display
- 2x EC11 Rotary encoder
- 6x MX-Style Switches

# Cad Model:

Everything fits together using 4 3D printed "Screws". The PCB itself is lying on a podest inside the case. <br>
It´s printed in 3 Parts: <br>
The 4 "Screws" <br>
The upper Case <br>
The lower Case <br>

## Quick picture of the Case:

![Screenshot of Case](assets/Case.png)

# PCB and Schematic

## Heres my PCB and Shematic, which were both made in KiCad.
![Screenshot of PCB](assets/Schematic.png)
![Screenshot of Schematic](assets/PCB.png) <br>
*I used "MX_PUSH" from KiCAd for the keyswitch footprints.*

# Firware
Used abriviations: <br>
P/H = Press and Hold<br>
S. Press = Press<br>
d. press = Double Press<br>
X/X = Row(In assembeled Key board) / Position in Row ( 0, 1, 2) ** 0 being all the way down/ to the left<br>
r.t.l/r. = rotate to left/right<br><br>

## Functions:<br>
   Display Lock (Key,0/0) [S. press -> Lock Display, d. press -> shutdown menu]<br>
   ShortCut to Claude/AI of your choice (Key, 0/1) [S. press -> AI]<br>
   ScreenShot(Key, 0/2) [S. press -> Screenshot, P/H -> Recording]<br>
   AudioPlayer(Key, 1/1) [S. Press -> Play/pause, d. press -> previous Song, P/H -> Skip Song]<br>
   Light Controle(Key, 1/2) [S. press -> Light toggle]ts and link it to either the application or a web link of your favourite AI.<br>
   Focus Toggle(Key, 1/0) [S. press -> Focus toggle] <br>
   Volume Controle(Rotary Encoder, Right) [r.t.r. -> Volume Up, r.t.l. -> Volume Down, S. press -> Mute Audio]<br>
   FullScreen Toggle(Rotary Encoder, Left) [r.t.l/r. -> Switch to either Full or not-Full screen]<br>
   Clock(Rotary Encoder, Left) [s. press -> Enter Clock setting mode THEN AFTER S.PRESS r.t.l/r -> Set Time]<br><br>

## SetUp: <br>
Due to non existing Keyboard Commands on MacOS some Functions have to be SetUp in Apple Shortcuts!!<br>

### 1. Shortcut to CLaude:<br>
To set Up enter the KeyCombination (Left Command, Left Shift and C) in a new Shortcut in Apple Shortcuand link it to Apple Home Smart Home remote conrole.<br>
### 2. Light Controle:<br>
To set Up enter the KeyCombination (Left Command, Left Shift and L) in a new Shortcut in Apple Shortcuts <br>
### 3. Focus Toggle:<br>
To set Up enter the KeyCombination (Left Command, Left Shift and F) in a new Shortcut in Apple Shortcuts and set it to enable/disable your Focus of choice.

# BOM
### Here should be everything you need to make this hackpad <br><br>
6x Cherry MX Switches<br>
6x DSA Keycaps<br>
8x 1N4148 DO-35 Diodes.<br>
1x 0.91" 128x32 OLED Display<br>
2x EC11 Rotary Encoder<br>
1x XIAO RP2040<br>
1x Case (3 printed parts)<br>

