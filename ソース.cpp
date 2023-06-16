#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <random>

#define SEND
#define INCOMING

#define AC 5

//Ç∆Ç†ÇÈçÇäKä÷êîÉtÉçÅ[ÅB

template<class... T>
std::uint8_t SendMessage(const std::string& S,const T&... Item ) {

	std::cout <<"Message:" << S << std::endl;

	//SEND Item;//send option items. but compile error.
	std::random_device rd;
	//std::mt19937 mt;
	return rd() % AC;
}

std::string AnswerByString() {
	return "Answer! X";
}
std::vector<std::string> AnswerByStrings() {
	return { "Answer!" ,"hoge!"};
}
std::intmax_t AnswerByNumber() {
	return 42;
}
std::vector<std::intmax_t> AnswerByNumbers() {
	return { 42,0xdeadbeef };
}
bool AnswerByBool() {
	return (std::random_device()()) % 2 ? true : false;
}
int main() {
	std::string s = "Are you have the Hogelizer!";
	std::uint8_t AnswerType = 0;
	std::vector<std::string> A;

	SEND AnswerType=SendMessage(s,"Ç†Ç¢ÇƒÇﬁ");

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
			INCOMING auto X = AnswerByNumbers();
			for (auto& o : X) {
				A.push_back(std::to_string(o));
			}
			break;
		}
		case 4: {
			INCOMING auto X = AnswerByBool();
			A.push_back(X?"Yes":"No");
			break;
		}
		default:
			break;
	} 

	for (auto& o : A) {
		std::cout << o << std::endl;
	}

	SEND SendMessage("Complete!");

	//std::cout << "Complete!" << std::endl;

	return 0;
}