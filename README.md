# Capstone Project
C++ Nanodegree Program
by Albert Zheng
___
## Project Goal
The goal of this capstone project was to demonstrate knowledge learned throughout this course by building an application that can be used by others.

## Project Option
The project selected is to build the Pong game from scratch using the SDL game programming library.

## How does Pong work?
As most are familiar with in the classic Pong game, there are 2 paddles on either side that can move vertically in order to keep the ball from going past the player's own side. When the ball bypasses the paddle, the other player scores a point.

## Build Instructions
1. Clone this repo
2. Go to build directory `cd build`
3. Compile: `cmake .. && make`
4. Run it: `./PongGame`.

## Play Instructions
1. Player 1 can move left paddle Up with the `W` key and Down with the `S` key.
2. Player 2 can move right paddle Up with the `I` key and Down with the `K` key.
3. See who can score the most points!

## Rubric Check List
Compiling and Testing
- Code compiles and runs without error
- User can run pong using cmake and make instructions

Loops, Functions, I/O
- There are a number of functions used as part of the Ball, Paddle, Pong and Game classes. These can be seen as part of all the header and source files. Loops and switches are used as part of the update functions in updating the motion of the ball and paddle.
- Project accepts user input through the keyboard using the SDL API in order to interpret paddle movements

Object Oriented programming
- Classes are used to organize the Ball, Paddle, Pong and Game. Class methods perform tasks.
- Class members are explicitly specified are public, protected or private.
- The paddle uses get functions to only allow access to retrieve private data.
- The Pong and Game classes use the member initialization list when initialize the lower member classes.
- Function names are made appropriate to document their effects

Memory Management
- A number of functions use pass by reference
