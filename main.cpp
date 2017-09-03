#include <iostream>

#include "mustring.h"

int get_operation();
int get_position();

int main(int argc, char *argv[]){
	MUString mstr("MI");
	std::cout << "Welcome to the MU-puzzle program!" << std::endl;
	std::cout << "The goal of the puzzle is to try to make the string 'MU' from 'MI'\n" << std::endl;

	while(true){
		mstr.print();
		bool result = true;
		switch (get_operation()){
			case 1:
				result = mstr.add_u_to_end_after_i();
				break;
			case 2:
				mstr.double_after_m();
				break;
			case 3:
				result = mstr.three_i_to_u(get_position());
				break;
			case 4:
				result = mstr.remove_uu(get_position());
				break;
			case 5:
				mstr.reset();
				break;
			case 6:
				return EXIT_SUCCESS;
				break;
		}
		if(!result){
			std::cout << "Something went wrong :(" << std::endl;
		}
		std::cout << "______________________________________________________________________" << std::endl;
		std::cout << "\n" << std::endl;
	}
	return 0;
}

int get_operation(){
	std::cout << "Operations:" << std::endl;
	std::cout << "\t 1. Add 'U' to the end of a string ending in 'I'" << std::endl;
	std::cout << "\t 2. Repeat everything after 'M' at the end of the string" << std::endl;
	std::cout << "\t 3. Replace 'III' in a string with 'U' at the same position" << std::endl;
	std::cout << "\t 4. Remove 'UU' from a string" << std::endl;
	std::cout << "\t 5. Reset the string to 'MI'" << std::endl;
	std::cout << "\t 6. Quit the puzzle" << std::endl;
	int selection = 0;
	while (selection < 1 || selection > 6){
		std::cout << "Pick an operation: ";
		std::cin >> selection;
	}
	return selection;
}

int get_position(){
	int pos;
	std::cout << "Pick a position in the string at which to apply the operation: ";
	std::cin >> pos;
	return pos;
}
