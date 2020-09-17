#include<bits/stdc++.h>
using namespace std;

string dec_to_bin(int decimal)
{
	string binary = "";
	for(int i = decimal;i > 0;i/=2)
		binary = to_string(i%2) + binary;
	if(binary.length() < 8)
		binary = string(8-binary.length(),'0').append(binary);
	return binary;
}


struct mnemonics{
	string name;
	string binary;
	int size;
}MOT[15];

struct symbol{ 
	string name;
	string type;
	int location;
	int size;
	int section_id;
	string is_global;
};

struct section{ 
	int id;
	string name;
	int size;
};

vector<symbol> symbol_table; 
vector<section> section_table; 
int lc = 0; 
int sec_id = 0; 
int var_lc; 
ifstream in_f; 
ofstream out_f; 
string word; 
string str; 
int pointer,size; 

int search_MOT(string opcode) 
{
	int index = -1;
	for(int i = 0;i < 15;i++)
	{
		if(MOT[i].name == opcode)
		{
			index = i;
			break;
		}
	}
	return index;
}

int search_symbol_table(string variable) 
{
	int location = -1;
	for(vector<symbol>::const_iterator i = symbol_table.begin();i != symbol_table.end();++i)
	{
		if(i->name == variable)
		{
			location = i->location;
			break;
		}
	}
  	return location;
}

int get_size(string data) 
{
	int size = 0;
	for(int i = 0;i < data.length();i++)
	{
		if(data[i] == ',')
			size += 4;
	}
	size += 4;
	return size;
}

string get_data(string data) 
{
	string final;
	string temp_str = "";
	for(int i = 0;i < data.length();i++)
	{
		if(data[i] == ',')
		{
			final += dec_to_bin(stoi(temp_str.c_str()))+",";
			temp_str = "";
		}
		else 
			temp_str += data[i];
	}
	final += dec_to_bin(stoi(temp_str.c_str()))+",";
	temp_str = "";
	final.erase(final.length()-1,1);
	return final;
}

void store_symbol_table() 
{
	out_f.open("symbol.csv");
	out_f << "Name,Type,Location,Size,SectionID,IsGlobal\n";
	for(vector<symbol>::const_iterator i = symbol_table.begin();i != symbol_table.end();++i)
	{
		out_f << i->name<<",";
		out_f << i->type<<",";
		out_f << i->location<<",";
		out_f << i->size<<",";
		out_f << i->section_id<<",";
		out_f << i->is_global<<"\n";
	}	
	out_f.close();
}

void store_sec() 
{
	out_f.open("section.csv");
	out_f << "ID,Name,Size\n";
	for(vector<section>::const_iterator i = section_table.begin();i != section_table.end();++i)
	{
		out_f << i->id<<",";
		out_f << i->name<<",";
		out_f << i->size<<"\n";
	}
	out_f.close();
}

void pass1()
{
	
	in_f.open("input.txt");
	while(in_f >> word)
	{
		pointer = search_MOT(word);
		if(pointer == -1)
		{
			str = word;
			if(word.find(":") != -1)
			{
				symbol_table.push_back({str.erase(word.length()-1,1),"label",lc,-1,sec_id,"false"});
			}
			else if(word == "section")
			{
				in_f >> word;
				sec_id++;
				section_table.push_back({sec_id,word,0}); 
				if(sec_id != 1) 
				{
					section_table[sec_id-2].size = lc;
					lc = 0;
				}
			}
			else if(word == "global") 
			{
				in_f >> word;
				symbol_table.push_back({word,"label",-1,-1,-1,"true"}); 
			}
			else if(word == "extern") 
			{
				in_f >> word;
				symbol_table.push_back({word,"external",-1,-1,-1,"false"}); 
			}
			else
			{
				in_f >> word;
				in_f >> word;
				size = get_size(word);
				symbol_table.push_back({str,"var",lc,size,sec_id,"false"}); 
				lc += size;
			}
		}
		else
		{
			if(!(pointer == 9 || pointer == 14)) 
				in_f >> word;
			if(pointer==2 || pointer==10 || pointer == 11)
				in_f >> word;
			lc += MOT[pointer].size;
		}
	}
	
	section_table[sec_id-1].size = lc; 
	
	store_symbol_table();
	store_sec();
	
	in_f.close();
}

void pass2()
{
	in_f.open("input.txt");
	out_f.open("output.txt");
	while(in_f >> word)
	{
		pointer = search_MOT(word);
		if(pointer == -1)
		{
			str = word;
			if(word.find(":") != -1) 
 			{
 				out_f << "";
			}
			else if(word == "global") 
			{
				in_f >> word;
				out_f <<"global "<<word<<endl;
			}
			else if(word == "extern") 
			{
				in_f >> word;
				out_f <<"extern "<<word<<endl;
			}
			else if(word == "section") 
			{
				in_f >> word;
				out_f <<"section ."<<word<<endl;
				lc = 0;
			}
			else 
			{
				in_f >> word;
				in_f >> word;
				out_f <<dec_to_bin(lc)<<" "<<get_data(word)<<endl;
				size = get_size(word);
				lc += size;
			}
		}
		else
		{
			out_f <<dec_to_bin(lc)<<" "<<MOT[pointer].binary;
			if(pointer==0||pointer==1) 
			{
				in_f >> word;
				out_f <<" "<<word;
			}
			else if(pointer==5 || pointer==6 || pointer==7 || pointer==8 || pointer==13) 
			{
				in_f >> word;
				var_lc = search_symbol_table(word);
				if(var_lc == -1)
					out_f <<" "<<dec_to_bin(stoi(word.c_str()));
				else
					out_f <<" "<<dec_to_bin(var_lc);
			}
			else if(pointer==2 || pointer==10) 
			{
				in_f >> word;
				out_f <<" "<<word;
				in_f >> word;
				var_lc = search_symbol_table(word);
				if(var_lc == -1)
					out_f <<" "<<dec_to_bin(stoi(word.c_str()));
				else
					out_f <<" "<<dec_to_bin(var_lc);
			}
			else if(pointer == 11) 
			{
				in_f >> word;
				out_f <<" "<<word;
				in_f >> word;
				out_f <<" "<<word;
			}
			lc += MOT[pointer].size;
			out_f << "\n";
		}	
	}
	out_f.close();
	in_f.close();
}

int main()
{
	MOT[0] = {"ADD","00000001",1};
	MOT[1] = {"INC","00000010",1};
	MOT[2] = {"CMP","00000011",5};
	MOT[3] = {"JNC","00000100",1};
	MOT[4] = {"JNZ","00000101",1};
	MOT[5] = {"ADDI","00000110",5};
	MOT[6] = {"JE","00000111",5};
	MOT[7] = {"JMP","00001000",5};
	MOT[8] = {"LOAD","00001001",5};
	MOT[9] = {"LOADI","00001010",1};
	MOT[10] = {"MVI","00001011",5};
	MOT[11] = {"MOV","00001100",1};
	MOT[12] = {"STOP","00001101",1};
	MOT[13] = {"STORE","00001110",5};
	MOT[14] = {"STORI","00001111",1};
	pass1();
	lc = 0;
	pass2();
	return 0;
}
