# Two-Pass-Assembler
By [Devesh Sangwan](https://github.com/deveshsangwan), [Shikhar Panwar](https://github.com/shikharpanwar4)

This is a simple C++ implementation for a Two pass assembler.

# Overview of the Code
## pass1: 
- Extracts all symbols and sections.
- A symbol and section table is generated and are stored in a csv file.
## pass2: 
- Each instruction is converted to machine code. 
- The programs again reads the symbol table to get address and size associated with each symbol.


## Other Functions:
- <b>dec_to_bin(int)</b> : Converts the given decimal number to the <b>Binary String</b>
- <b>search_MOT(string)</b> : It searchers the MOT for the Machine Operation Code and returns the <b>index</b>.
- <b>search_symbol_table(string)</b> : It searches the symbol_table and returns the <b>address</b> of the symbol.
- <b>get_size(string)</b> : It returns the size of the symbol/operation.
- <b>get_data(string)</b> : It extracts data from string and converts it into its binary equivalent.
- <b>store_symbol_table()</b> : Stores symbol table in csv format.
- <b>store_sec()</b> : Store section table in csv.


## Structures:
- <b>mnemonics</b> : Machine Operation Table
- <b>symbol</b> : Symbol Table
- <b>section</b>: Section Table

## Data Structures:
- Vector
- File Stream
  
