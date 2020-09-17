# Two-Pass-Assembler
C++ code for Two Pass Assembler

This is a simple C++ implementatiob for a Two pass assembler.

Over-review of the Code

There are 2 main methods:

<b>Pass 1:</b> It creates 2 csv files for <b>symbol table</b> and <b>section table</b> respectively.
<b>Pass 2:</b> It finalize the machine code for the given tables and code. (It does not create machine code for registers defined within the code.)


Other Functions:
1. <b>dec_to_bin(int)</b> : converts the given decimal number to the <b>Binary String</b>
2. <b>inti()</b> : Initialize the Machine Opcode Array with Name, Binary Code and Size.
3. <b>search_MOT(string)</b> : It searchers the MOT for the asked Machine Code and returns <b>index</b> in array.
4. <b>search_symbol_table(string)</b> : It searches the symbol_table and returns the <b>location</b> of the symbol.
5. <b>get_size(string)</b> : It returns the size of the variable.
6. <b>get_data(string)</b> : It takes value string and dec_to_bins it into Binary.
7. <b>store_symbol_table()</b> : Stores symbol table in csv format.
8. <b>store_sec()</b> : Store section table in csv.


Structures:
1. <b>mnemonics</b> : Machine Opcode Table
2. <b>symbol</b> : Symbol Table
3. <b>section</b>: Section Table

Data Structures:
1. Vector
2. File Stream

Thank You.
For any queries you can mail me at: dev.sangwan2001@gmail.com
  
