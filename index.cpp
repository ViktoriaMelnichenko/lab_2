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

const uint8_t FIFTH_DIVIDER = HALFEST_DIVIDER + TRIPLET_DIVIDER;
bool isFifthlet (uint16_t maybeFifthlet) {
	return isDivisibleBy(FIFTH_DIVIDER, maybeFifthlet);
}

bool isFinishedNumber (uint16_t expectNumber) {
	return isHalfest(expectNumber) || isTriplet(expectNumber) || isFifthlet(expectNumber);
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
	outLine(errorMessage);
	outLine(TRY_AGAIN);
	outLine(EXIT_MESSAGE);
}

void validateNumericLength (std::string value) {
	if (value.length() > FACTOR + 1) throw std::invalid_argument(ERROR_INPUT + " > " + value);
}

void validateMaximumNumber (uint16_t value) {
	if (value > MAXIMUM) {
		throw std::invalid_argument(ERROR_INPUT + " > (" + std::to_string(value) + ") максимальне значенна: " + std::to_string(MAXIMUM));
	}
}

std::string filterToFirstNaturalNumeric (std::string inputNumbers) {
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
			else validateNumericLength(stringTmp);
		  try {
			  numberTmp = std::stoi(stringTmp);
				stringTmp = "";
		  } catch (std::exception &e) {
			  throw std::invalid_argument(ERROR_INPUT + " > " + stringTmp);
		  }
			if (numberTmp == EXIT_NUMBER) break;
			else validateMaximumNumber(numberTmp);
			output += std::to_string(numberTmp) + " ";
			if (isNaturalNumber(numberTmp)) break;
	  } else {
			stringTmp += inputNumbers[index];
		}
  }
	if (isNoEmpty(stringTmp)) {
		validateNumericLength(stringTmp);
		try {
			numberTmp = std::stoi(stringTmp);
			stringTmp = "";
		} catch (std::exception &e) {
			throw std::invalid_argument(ERROR_INPUT + " > " + stringTmp);
		}
		if (numberTmp != EXIT_NUMBER) {
			validateMaximumNumber(numberTmp);
			output += std::to_string(numberTmp) + " ";
		}
	}

	if (isEmpty(output)) throw std::invalid_argument(EMPTY_COMMAND_MESSAGE);

	return output;
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
		<< to_string(NOTATION) << to_string(FACTOR)
		<< endl << endl
		<< "----------------------"
		<< endl << EXIT_MESSAGE << endl;
}

void programManager () {
	std::string inputNumerics;
	outLine("введіть значення послідовності: ");
	while(isEmpty(inputNumerics)) {
		std::getline(std::cin, inputNumerics);
	}

	try {
		if (isEmpty(inputNumerics)) throw std::invalid_argument(EMPTY_COMMAND_MESSAGE);
		if (inputNumerics == EXIT_COMMAND) return;
		std::string filteredNumerics = filterToFirstNaturalNumeric(inputNumerics);
		std::cout << filteredNumerics;
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
