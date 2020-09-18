# Two-Pass-Assembler
C++ code for Two Pass Assembler

This is a simple C++ implementatiob for a Two pass assembler.

## Overview of the Code
### pass1: 
- Extracts all symbols and sections.
- A symbol and section table is generated and are stored in a csv file.
### pass2: 
- Each instruction is converted to machine code. 
- The programs again reads the symbol table to get addresses associated with each symbol.


### Other Functions:
- <b>dec_to_bin(int)</b> : converts the given decimal number to the <b>Binary String</b>
- <b>search_MOT(string)</b> : It searchers the MOT for the asked Machine Code and returns <b>index</b> in array.
- <b>search_symbol_table(string)</b> : It searches the symbol_table and returns the <b>location</b> of the symbol.
- <b>get_size(string)</b> : It returns the size of the variable.
- <b>get_data(string)</b> : It takes value string and dec_to_bins it into Binary.
- <b>store_symbol_table()</b> : Stores symbol table in csv format.
- <b>store_sec()</b> : Store section table in csv.


### Structures:
- <b>mnemonics</b> : Machine Operation Table
- <b>symbol</b> : Symbol Table
- <b>section</b>: Section Table

### Data Structures:
- Vector
- File Stream

Thank You.
For any queries you can mail me at: dev.sangwan2001@gmail.com
  
