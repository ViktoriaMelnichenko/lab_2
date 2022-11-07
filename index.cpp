#include <cstdint>
#include <iostream>
#include <math.h>
#include <string>
#include <cmath>


const uint8_t     EXIT_NUMBER           = 0;
const std::string EXIT_COMMAND          = std::to_string(EXIT_NUMBER);
const std::string TRY_AGAIN             = "Спробуйте ще раз";
const std::string EXIT_MESSAGE          = "Для того щоб покинути программу введіть: " + EXIT_COMMAND;
const std::string EMPTY_COMMAND_MESSAGE = "Ви не ввели жодного значеня!";
const std::string ERROR_INPUT           = "Ви ввели хибне значення!";

const uint8_t NOTATION = 10;
uint16_t GetFixedInput (uint8_t factor) {
	return pow(NOTATION, factor);
}
const uint8_t  FACTOR  = 3;
const uint16_t MAXIMUM = GetFixedInput(FACTOR);

bool isDivisibleBy (uint8_t divider, uint16_t expectNumber) {
	return expectNumber % divider == 0 && expectNumber != divider;
}

const uint8_t HALFEST_DIVIDER = 2;
bool isHalfest (uint16_t maybeHalfest) {
	return isDivisibleBy(HALFEST_DIVIDER, maybeHalfest);
}

const uint8_t TRIPLET_DIVIDER = 3;
bool isTriplet (uint16_t maybeTriplet) {
	return isDivisibleBy(TRIPLET_DIVIDER, maybeTriplet);
}

bool isFinishedNumber (uint16_t expectNumber) {
	return isHalfest(expectNumber) || isTriplet(expectNumber);
}

bool isNaturalNumber (uint16_t expectNumber) {
	return !isFinishedNumber(expectNumber);
}

bool isNoEmpty (std::string expectString) {
	return expectString.length() > 0;
}

bool isEmpty (std::string expectString) {
	return expectString.length() == 0;
}

const char SPACE      = ' ';
const char NEWLINE    = '\n';
const char TABULATION = '\t';

bool isSpaceing (char expectChar) {
	return expectChar == SPACE
			|| expectChar == NEWLINE
			|| expectChar == TABULATION;
}

void outLine (std::string out) {
	using namespace std;
	cout << " > " << out << endl;
}

void onError (std::string errorMessage) {
	using namespace std;
	outLine(errorMessage);
	outLine(TRY_AGAIN);
	outLine(EXIT_MESSAGE);
}

void lab_1 (std::string inputNumbers) {
	uint32_t size = inputNumbers.length();
	uint32_t index;
	uint16_t numberTmp;
  char currentChar;
	std::string stringTmp;
	std::string output = "";
  for (index = 0; index < size; index++) {
	  currentChar = inputNumbers[index];
	  if (isSpaceing(currentChar)) {
			if (isEmpty(stringTmp)) continue;
			try {
				numberTmp = std::stoi(stringTmp);
				stringTmp = "";
			} catch (std::exception &e) {
				throw std::invalid_argument(ERROR_INPUT);
			}
			if (numberTmp == EXIT_NUMBER) break;
			if (numberTmp > MAXIMUM) throw std::invalid_argument(ERROR_INPUT);
			output += std::to_string(numberTmp) + ' ';
			if (isNaturalNumber(numberTmp)) break;
	  }
	  stringTmp += inputNumbers[index];
  }
	std::cout << output;
	output = "";
	return;
}

void help () {
  using namespace std;
	cout
		<< "Задано натуральну числову послідовність,"
		<< "ознакою завершення якої є нуль,"
		<< "записаний після перерахування всіх елементів послідовності."
		<< "Вивести в рядок значення елементів послідовності до першого простого значення,"
		<< "включаючи його чи всю послідовність,"
		<< "якщо простий елемент відсутній."
		<< "Значення елементів послідовності не перевищують > "
		<< std::to_string(NOTATION) << std::to_string(FACTOR)
		<< endl << endl
		<< "----------------------"
		<< endl << EXIT_MESSAGE << endl;
}

void programManager () {
	std::string inputNumbers;
	outLine("введіть значення послідовності: ");
	while(isEmpty(inputNumbers)) {
		std::getline(std::cin, inputNumbers);
	}
	try {
		if (isEmpty(inputNumbers)) throw std::invalid_argument(EMPTY_COMMAND_MESSAGE);
		if (inputNumbers == EXIT_COMMAND) return;
		return lab_1(inputNumbers);
	} catch (std::exception& error) {
		onError(error.what());
		return programManager(); // restart this
	}

	return;
}

int main () {
	help();
	programManager();
	return 0;
}
