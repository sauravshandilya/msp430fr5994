### Information

This repo contains following sample code:

1. Switch_with_uart: Interfacing Red and Green LEDs, Switch-1 and Switch-2 along with UART.
2. LCD_test: Test code of interfacing MSP430Boost-Sharp96 LCD with MSP430FR5994.
3. LCD_switch_counter: LCD displaying a variable which countup when Switch-1 is pressed and count down when Switch-2 is pressed.

Refer code comments for details

###### Hardware Used:

1. MSP430FR5994
2. MSP430Boost-Sharp96 LCD

###### Software Used:

1. Energia 1.610e18

#### Useful links

1. Guide to the Sharp Memory Display BoosterPack (http://energia.nu/pin-maps/guide_sharpmemorydisplayboosterpack/)

2. Sharp Memory LCD BoosterPack - Details (http://www.ti.com/tool/430BOOST-SHARP96)

3. Energia Library for LCD_SharpBoosterPack_SPI (useful in case modifications needs to be made to library): (https://github.com/energia/Energia/blob/master/libraries/LCD_SharpBoosterPack_SPI)

4. Pin map for energia - MSP430FR5994 (https://embeddedcomputing.weebly.com/launchpad-msp430fr5994.html)


#### Setting up energia

1. Download Energia from [here](http://energia.nu/download/).
2. Install board files: Tools --> Boards --> Board Manager --> search the board and click install.
3. Use sample examples located in Examples to get started.
3. Using LCD: File --> Examples --> LCD_SharpBoosterPack_SPI.
