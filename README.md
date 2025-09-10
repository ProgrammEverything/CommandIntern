# CommandIntern

### This project is (AS OF CURRENTLY) work in progress and more features are coming
I made this project because I thought of how many of today's command lines aren't really simple to use so this project can help in better making of interpreters.  
This project contains the bare minimum for a programming language interpreter. This programming language is very simple and contains the following grammar rules:  
##### Variable assignment
```
<expression:name> <expression:assign> <expression:expression> (All kinds of expressions)
Example:
Number = 2*2*2*2+x-1
```
##### Numerical operation
```
<expression:number | lparan> <expression:numerical_operation> <expression:number | rparan>
Example:
(2+2+1) - 2+2*(1/2)

```
 1. lparan is the left parentheses for order of calculation
 2. rparan is the right parentheses for order of calculation
##### Statements
```
A Statement is a block of code which is seperated by a ';'
<expression:expression>(All kinds of expressions) <expression:end> (end is referring to ';')
```
##### Getting started
 If you want to try this project for yourself you can follow the following instructions for building the project  
 Beforehand you need the following dependencies:  
 
 1. CMake
 2. GCC
 3. Make
 4. git (optional)

 ##### Downloading
 To download this repo from the git cli you can do  
 ```bash
  git clone https://github.com/ProgrammEverything/CommandIntern.git
 ```
 Or you can download it manually from the github repo  
 ##### Building
After downloading the project you must go in the project folder and execute  
```bash
cmake . -B build
```
Then go in the build folder  
```bash
cd build
```
And run make to build the project  
```
make
```
After that a new file in the build folder called "CommandIntern" which is the built version of the project. Now you can try the project yourself!  

