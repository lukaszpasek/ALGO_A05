# ALGO_A05

You write a robot remote control software that will be used to explore the recently discovered Planaria VI planet. The research department provided you with a description of the robot's route. It turns out, however, that he could get into the same place using a much shorter description, which would allow for significant savings in the communication department ...

The Planaria VI surface is a plane. The robot is able to perform only four types of instructions: forward and backward movement by the total number of units, and turnover to the right and left by a multiplicity of 60 degrees. Write a program that for the given list of instructions will find the shortest alternative allowing the robot to finally be in the same position and point in the same direction.

Available memory: 8MB

Entrance
The first line of entry contains the natural number 𝑍 - the number of data sets. Then sets are given in the following order:

In the first line, one natural number 𝑛 (0≤𝑛≤1000) - the number of instructions in the program. In the second line 𝑛 of the instructions. Each of them contains a letter specifying the type of instruction (F - forward movement, B - reverse movement, R - turn to the right, L - turn to the left), and then a natural number 𝑣. For motion instructions, this is the number of units that the robot is to move (0≤𝑣≤106), and for rotation - the rotation angle in degrees (0≤𝑣≤360, 𝑣 divisible by 60).

Exit
For each set, write the shortest (relative to the number of instructions) program giving the same end result (robot position and orientation). The program should be written in the same format as the entry (however, you can use the value 𝑣 to 2 * 109). If there are many possible programs with the minimum number of instructions, you can write any of them.

Example
For input data:
3  
4  
L 60 F 3 R 120 F 3  
4  
F 1 R 120 F 1 R 120  
3  
F 5 L 180 B 5  
The possible answer is:  
2  
F 3 R 60  
2  
R 240 B 1  
2  
F 10 R 180  
