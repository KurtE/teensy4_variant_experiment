# teensy4_variant_experiment
 Experiment to see if we can devine external variants for PJRC Teensy 4 boards

Note: Currently my only target is for Arduino IDE 2.x installs. 

Again this is currently only an experiment!

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Thise experiment started with seeing if we could create a variant of
a teensy board for a custom board.  This board and some of this is
discussed in the Teensy forum:

https://forum.pjrc.com/index.php?threads/call-to-arms-teensy-sdram-true.73898/

I also received some good hints up on the Arduino forum in the thread:
https://forum.arduino.cc/t/how-to-create-a-board-variant-as-separate-install/1212728/9


Currently the Teensy installs do not support variants at all, and the only ways to 
setup for a custom board, is to either completely muck up the currently released board
which has the same size flash chip as your custom board.   

And/or potentially edit all of the core and library sources that have things in it like:
```
#ifdef ARDUINO_TEENSY40
#elif defined(ARDUINO_TEENSY41)
...
```
And add new sections for your specific setup... 

This attempt is using a slightly modified version of the teensy cores\teensy4 to help
support it.   

These changes are up in my fork/branch: https://github.com/KurtE/cores/tree/variants_override

Note: As the board this is currently working with is a sortof Alpha level board and a new
version is likely soon.  All of the new pins are added to end of the logical MicroMod board
as that is the flash size...

Some of the changes so far:

Pin Table - changed the core code to see if a file variant.h exists and if so, use it, instead of the pin definitions
in core_pins.h

main digital function: pinMode, digitalWrite... uses new table. 

XBAR pins - mostly there, have not double checked.

FlexIO library - updates appear to work, but require the changes in my my branch
https://github.com/KurtE/FlexIO_t4/tree/split_out_IO_pins
I will soon merge that into my main branch

PWM (analogWrite) - appears to mostly work.  One pin did not, but...

Lots of things left:

digitalWriteFast (and other Fast): right now will work for some pins but not all.  Will implement different version.

Analog: did not define any new ones

SPI library:

Wire Library:


More to come(Maybe)
---

Or maybe not...




