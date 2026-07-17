# calculaBasuda
 
  This project is a numeric base conversion calculator built in C++, capable of converting values between bases ranging from 2 to 32, with the source base and destination base chosen by the user
 
  When you build this project, you can input any number in a valid base (2-32) and convert it to any other base within that range, with input verification to prevent invalid values or values outside the supported range
 
## Features
  - **Source base selection:** The user informs which base (from 2 to 32) the entered number is represented in
  - **Destination base selection:** The user informs to which base (from 2 to 32) the number should be converted
  - **Valid input verification:** The program checks whether the informed bases are within the allowed range (2-32) and whether the digits of the entered number are valid for the chosen source base, preventing crashes or incorrect conversions
  - **Conversion through an intermediate base:** The number is converted from the source base to decimal and then from decimal to the destination base, supporting digits from 0-9 and A-Z for bases above 10
## Getting Started
  To try it out, simply clone this repository, compile the program and run it to see it working through the console
 
```
  git clone https://github.com/jocov23/calculaBasuda.git
  cd calculaBasuda
  g++ -o calculaBasuda teste.cpp
  ./calculaBasuda
```
 
