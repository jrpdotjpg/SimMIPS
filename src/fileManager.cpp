#include "fileManager.hpp"
#include <iostream> //TESTING
#include <bitset> //TESTING
typedef unsigned int uint;
typedef unsigned char uchar;

fileManager::fileManager(std::string path){
	binary_file.open(path, std::ios::binary);
	//std::cerr << "File name: "<< path << std::endl;
	EOF_FLAG = false;
	//TODO check if properly opened
	//hpp var
	
	auto begin = binary_file.tellg();
	binary_file.seekg(0, std::ios::end);
	auto end = binary_file.tellg();
	FILESIZE = end-begin;
	binary_file.seekg(0);


}
fileManager::~fileManager()
{
	binary_file.close();
}

bool fileManager::is_passed_end(){
	std::cerr << "Current offset and Filesize" << get_currOffset() << " " << FILESIZE << std::endl; //TESTING
	return (get_currOffset() >= FILESIZE);
}

void fileManager::jump_to_offset(int offset){
	//used just for jumping i.e return to label
	binary_file.seekg(offset);
}
uint fileManager::get_currOffset(){
	//gets current file offset
	return binary_file.tellg();
}
uint fileManager::jump_r_word_return(int offset){
	int initial_offset = get_currOffset();
	jump_to_offset(offset);
	uint word = r_word_advance();
	jump_to_offset(initial_offset);
	return word;
}
uint fileManager::r_word_advance(){
	//reads a word at the current position
	//file pointer is advanced
	//eg for getting an instruction
	char * buffer = new char[4];
	//std::cerr << "current pointer" <<binary_file.tellg() << std::endl;
	binary_file.read(buffer,4);
	if(is_passed_end()){ 
		std::cerr << "setting EOF" << std::endl; //TESTING
		std::cerr << "Offset at set EOF: " << get_currOffset() << std::endl; //TESTING
		EOF_FLAG = true;
	}
	//returns a significance corrected word, ie: most significant byte highest in the word
	// for (int i = 0;i< 4 ; i++){ std::cerr << std::bitset<8>(buffer[i]) << std::endl; }  //TESTING
	//uint word = (uint)buffer[3] + ((uint)buffer[2] << 8) + ((uint)buffer[1] << 16) + ((uint)buffer[0] << 24);
	uint word = 0;
	for (int i = 0 ; i < 4 ; i++) 
	{
		word += ((uint)((uchar)(buffer[i]))) << (8 * (3-i));
	}
	// std::cerr << "Instruction word fetched: "<< std::bitset<32>(word) << std::endl; //testing
	delete[] buffer;
	return word;
}

bool fileManager::get_EOF_FLAG()
{
	return EOF_FLAG;
}

// TODO: if read past the end of a file, throw memory access exception
