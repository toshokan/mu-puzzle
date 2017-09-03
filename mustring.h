#ifndef MUSTRING_H
#define MUSTRING_H

#include <iostream>
#include <iterator>
#include <string>
#include <list>

enum MUStringChar {
	M,
	U,
	I,
	MUNone
};

MUStringChar ctomsc(char c);
char msctoc(MUStringChar msc);

class MUString {
	public:
		MUString();
		MUString(std::string contents);
		bool add_u_to_end_after_i();
		bool double_after_m();
		bool three_i_to_u(int position);
		bool remove_uu(int position);
		void print() const;
		void reset();
	private:
		std::list<MUStringChar> l;
};

#endif
