# Two-Pass-Assembler
C++ code for Two Pass Assembler

This is a simple C++ implementatiob for a Two pass assembler.

## Overview of the Code
### pass1: 
- Extracts all symbols and sections.
It creates 2 csv files for <b>symbol table</b> and <b>section table</b> respectively.
### pass2: 
It finalize the machine code for the given tables and code. (It does not create machine code for registers defined within the code.)


### Other Functions:
- <b>dec_to_bin(int)</b> : converts the given decimal number to the <b>Binary String</b>
- <b>inti()</b> : Initialize the Machine Opcode Array with Name, Binary Code and Size.
- <b>search_MOT(string)</b> : It searchers the MOT for the asked Machine Code and returns <b>index</b> in array.
- <b>search_symbol_table(string)</b> : It searches the symbol_table and returns the <b>location</b> of the symbol.
- <b>get_size(string)</b> : It returns the size of the variable.
- <b>get_data(string)</b> : It takes value string and dec_to_bins it into Binary.
- <b>store_symbol_table()</b> : Stores symbol table in csv format.
- <b>store_sec()</b> : Store section table in csv.


### Structures:
1. <b>mnemonics</b> : Machine Opcode Table
2. <b>symbol</b> : Symbol Table
3. <b>section</b>: Section Table

### Data Structures:
1. Vector
2. File Stream

Thank You.
For any queries you can mail me at: dev.sangwan2001@gmail.com
  
