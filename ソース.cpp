#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <random>

#define SEND
#define INCOMING

#define AC 4

//とある高階関数フロー。

std::uint8_t SendMessage(const std::string& S) {

	std::cout <<"QUSETION!:" << S << std::endl;

	SEND S;
	std::mt19937 mt;
	return mt() % AC;
}

std::string AnswerByString() {
	return "Answer!";
}
std::vector<std::string> AnswerByStrings() {
	return { "Answer!" ,"hoge!"};
}
std::intmax_t AnswerByNumber() {
	return 42;
}
bool AnswerByBool() {
	return (std::mt19937()()) % 2 ? true : false;
}
int main() {
	std::string s = "MyQuestion!";
	std::uint8_t AnswerType = 0;
	std::vector<std::string> A;

	SEND AnswerType=SendMessage(s);

	switch (AnswerType)
	{
		case 0: {
			INCOMING auto X = AnswerByStrings();
			A = X;
			break;
		}
		case 1: {
			INCOMING auto X = AnswerByString();
			A.push_back(X);
			break;
		}
		case 2: {
			INCOMING auto X = AnswerByNumber();
			A.push_back(std::to_string(X));
			break;
		}
		case 3: {
			INCOMING auto X = AnswerByBool();
			A.push_back(std::to_string(X));
			break;
		}
		default:
			break;
	} 

	for (auto& o : A) {
		std::cout << o << std::endl;
	}

	return 0;
}