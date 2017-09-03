#include "mustring.h"

MUStringChar ctomsc(char c){
	switch (c){
		case 'm':
		case 'M':
			return M;
			break;
		case 'u':
		case 'U':
			return U;
			break;
		case 'i':
		case 'I':
			return I;
			break;
		default:
			return MUNone;
			break;
	}
}

char msctoc(MUStringChar msc){
	switch (msc){
		case M:
			return 'M';
			break;
		case U:
			return 'U';
			break;
		case I:
			return 'I';
			break;
	}
}

MUString::MUString(){
	if(!this->l.empty()){
		this->l.clear();
	}
	this->l.push_back(M);
	this->l.push_back(I);
}

MUString::MUString(std::string contents){
	if(!this->l.empty()){
		this->l.clear();
	}
	for(auto c : contents){
		MUStringChar mc = ctomsc(c);
		if(mc != MUNone){
			this->l.push_back(mc);
		}
	}
}

bool MUString::add_u_to_end_after_i(){
	bool valid = this->l.back() == I;
	if(valid){
		this->l.push_back(U);
	}
	return valid;
}

bool MUString::double_after_m(){
	int entries = this->l.size();
	auto it = std::next(this->l.begin());
	for(int i = 1; i < entries; i++, it++){
		this->l.push_back(*it);
	}
	return true;
}

bool MUString::three_i_to_u(int position){
	if (position < 1 || position > this->l.size() - 2){
		return false;
	}
	auto it = this->l.begin();
	std::advance(it, position);
	bool valid = true;
	for(int i = 0; i < 3; i++){
		auto n_it = it;
		std::advance(n_it, i);
		if(*n_it != I){
			valid = false;
			break;
		}
	}
	if(valid){
		auto stop_it = it;
		std::advance(stop_it, 3);
		this->l.erase(it, stop_it);
		auto insert_it = this->l.begin();
		std::advance(insert_it, position);
		this->l.insert(insert_it, U);
	}
	return valid;
}

bool MUString::remove_uu(int position){
	if (position < 1 || position > this->l.size() - 1){
		return false;
	}
	auto it = this->l.begin();
	std::advance(it, position);
	bool valid = true;
	for(int i = 0; i < 2; i++){
		auto n_it = it;
		std::advance(n_it, i);
		if(*n_it != U){
			valid = false;
			break;
		}
	}
	if(valid){
		auto stop_it = it;
		std::advance(stop_it, 2);
		this->l.erase(it, stop_it);
	}
	return valid;
}

void MUString::print() const{
	int pos = 0;
	for(auto c : this->l){
		std::cout << msctoc(c) << " ";
		pos++;
		if(pos>10){
			std::cout << " ";
		}
	}
	std::cout << std::endl;
	for(int i = 0; i < this->l.size(); i++){
		std::cout << i << " ";
	}
	std::cout << "\n" << std::endl;
}

void MUString::reset(){
	this->l.clear();
	this->l.push_back(M);
	this->l.push_back(I);
}
