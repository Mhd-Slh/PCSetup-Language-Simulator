Project Description:
This project simulates a basic computer setup with components such as CPU, memory, and register/accumulator. This code allows you to write a program that replaces the: integer, double, char, string, and bool data types with mouse, keyboard, headphone, monitor, and charging respectively. Also, the input/output devices: cin/cout are replaced with plugin and display respectively.

Elements:

    Memory:
        I used separate maps (intMemory, doubleMemory, charMemory, stringMemory, boolMemory) to store data of respective types.
        Each map for the data types has an associated address counter (intMemoryAddress, doubleMemoryAddress, charMemoryAddress, stringMemoryAddress, and boolMemoryAddress) for 	identification while loading and storing data.

    CPU:
        The CPU class is able to store data into memory, and load data from memory into accumulators based on the data type.
        It also has the following functions (Arithmetic: add, subtract, multiply, and divide; Comparing: equal to, less than, greater than; and logical operations: And, Or, and Not) which 	handle operations across different data types using the load function.

    Classes:
        mouse: Represents an integer data type.
	keyboard: Represents a double data type.
        headphone: Represents a character data type.
        monitor: Represents a string data type.
        charging: Represents a boolean data type.
	
	All support CPU functions with each other, excluding the monitor.

    Operator Overloading:
        Overloaded arithmetic operators (+, -, *, /), comparison operators (==, <, >), and logical operators (&&, ||, !) for each device class to interact with other objects of the same 	or different types.

    Input/Output Handling:
        Output (display): Overloaded the < operator to print different data types to the console.
        Input (plugin): Overloaded the > operator to read different data types from the console into the respective device classes.

I Learned:

    more about how CPU manages memory and other operations in a computer environment.
    more about templating and operator overloading.

Challenges:

    Simulating a computer environment and its CPU.
    Managing multiple data types and ensuring proper interactions with the CPU class.
    Implementing operator overloading correctly across various classes and ensuring consistent behavior.

(Help taken from ChatGPT for this txt file)
