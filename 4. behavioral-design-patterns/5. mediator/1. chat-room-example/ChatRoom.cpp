#include "ChatRoom.h"

void ChatRoom::broadcast(const string& origin, const string& message) {
	for (auto p : people)
		if (p->name != origin)
			p->receive(origin, message);
}

void ChatRoom::join(Person* p) {
	string joinMsg = p->name + " joins the chat";
	broadcast("room", joinMsg);
	p->room = this;
	people.push_back(p);
}

void ChatRoom::message(const string& origin, const string& who, const string& message) {
	auto target = find_if(begin(people), end(people), 
		[&](const Person* p) {
			return p->name == who;
		});

	if (target != end(people))
		(*target)->receive(origin, message);
}
