# ARM_Based_Smart_Watch
This project is an ARM-based smartwatch developed on the STM32F401CC microcontroller, incorporating various peripherals to provide diverse functionalities. The smartwatch displays time and date using the Real-Time Clock (RTC) peripheral on a TFT display. Additionally, it includes applications such as a music player, a contacts log, and a game.
### Peripheral Usage
RCC, GPIO, SysTick, EXTI, NVIC: Various other peripherals used for system control, timing, external interrupts, and general-purpose input/output operations.
Real-Time Clock (RTC): Used for displaying the current time and date.
SPI Communication Protocol: Used to send images to the TFT to be dispalyed.
TFT Display: Used as the primary interface for displaying information such as time, date, music library, contacts, and game graphics.
Digital-to-Analog Converter (DAC): Utilized in the music player application for audio playback.
Amplifier and Potentiometer: Used to filter, amplify, and control the volume of the audio output from the DAC.
LED Matrix: Utilized for decorative purposes and displaying animations. 
STP chips: To minimize microcontroller pins used for driving the matrix.
Keypad: Used for user input in the music player application for navigation and track selection.
Infrared (IR) Communication: Utilized in the game application to interact with external objects or devices using the NEC communication protocol.

### Features
Time and Date Display: The watch utilizes the STM32F401CC's Real-Time Clock (RTC) peripheral to accurately display the current time and date on a TFT display.
Music Player: The music player application leverages the Digital-to-Analog Converter (DAC) to play songs. Sound output is filtered and amplified using an amplifier and a potentiometer to control volume.
Contacts Log: The contacts log application provides users with quick access to the numbers of their contacts. This feature allows users to easily find and dial contacts directly from the smartwatch.
Game: The smartwatch includes a game application that utilizes peripherals such as Infrared (IR) communication and an RGB LED for visual feedback. Users can play a game that interacts with external objects using IR communication. The RGB LED displays various colors that change based on user inputs.
