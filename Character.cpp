#include "Character.h"

Character::Character(){
	tickets = 0;
}

void Character::SetName(string name){
	this->name = name;
}

string Character::GetName(){
	return name;
}

int Character::GetTickets(){
	return tickets;
}

void Character::SetTickets(int tickets){
	this->tickets = tickets;
}
