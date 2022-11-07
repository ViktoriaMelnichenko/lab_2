#include <cstdint>
#include <iostream>
#include <math.h>
#include <string>
#include <cmath>

const uint8_t     EXIT_NUMBER           = 0;

const std::string HELP_COMMAND          = "help";
const std::string EXIT_COMMAND          = std::to_string(EXIT_NUMBER);
const std::string TRY_AGAIN             = "Спробуйте ще раз";
const std::string EXIT_MESSAGE          = "Для того щоб покинути программу введіть: " + EXIT_COMMAND;
const std::string EMPTY_COMMAND_MESSAGE = "Ви не ввели жодного значеня!";
const std::string ERROR_INPUT           = "Ви ввели хибне значення!";
const std::string ERROR_PROGRAM         = "Программу не знайденно";

const uint8_t NOTATION = 10;
uint32_t GetFixedInput (uint8_t factor) {
	return pow(NOTATION, factor);
}

const uint8_t PROGRAMS_LENGTH          = 15;
const uint8_t FACTORS[PROGRAMS_LENGTH] = { 3, 6, 7, 7, 7, 6, 3, 7, 7, 9, 6, 6, 6, 6, 6, };

uint32_t maximumNumber (uint32_t maximumNumber, uint32_t expectNumber) {
	return expectNumber > maximumNumber ? maximumNumber : expectNumber;
}

bool isDivisibleBy (uint8_t divider, uint32_t expectNumber) {
	return expectNumber % divider == 0 && expectNumber != divider;
}

const uint8_t HALFEST_DIVIDER = 2;
bool isHalfest (uint32_t maybeHalfest) {
	return isDivisibleBy(HALFEST_DIVIDER, maybeHalfest);
}

const uint8_t TRIPLET_DIVIDER = 3;
bool isTriplet (uint32_t maybeTriplet) {
	return isDivisibleBy(TRIPLET_DIVIDER, maybeTriplet);
}

bool isFinishedNumber (uint32_t expectNumber) {
	return isHalfest(expectNumber) || isTriplet(expectNumber);
}

bool isNaturalNumber (uint32_t expectNumber) {
	return !isFinishedNumber(expectNumber);
}

bool isPerfectNumber (uint32_t expectNumber) {
	return isHalfest(expectNumber) && isTriplet(expectNumber);
}

bool isRange (uint32_t minimum, uint32_t maximum, uint32_t expectNumber) {
	return expectNumber >= minimum && expectNumber <= maximum;
}

const uint8_t MINIMUM_INPUT = 0;
bool isValidSizeNumber (uint32_t expectNumber, uint8_t programNumber = 0) {
	return isRange(MINIMUM_INPUT, GetFixedInput(FACTORS[programNumber]), expectNumber);
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

void nOut (uint32_t number) {
	std::cout << std::to_string(number) << " ";
}

void lab_1 (std::string inputNumbers) {
	uint32_t size = inputNumbers.length();
	uint32_t numberTmp;
  uint32_t index;
  char currentChar;
	std::string stringTmp;
	std::string output = "";
  for (index = 0; index < size; index++) {
	  currentChar = inputNumbers[index];
	  if (isSpaceing(currentChar)) {
			if (isNoEmpty(stringTmp)) {
				numberTmp = std::stoi(stringTmp);
				stringTmp = "";
				if (isValidSizeNumber(numberTmp, 0)) {
					if (numberTmp == EXIT_NUMBER) {
						std::cout << output;
						output = "";
						return;
					}
					output += std::to_string(numberTmp) + ' ';
					if (isNaturalNumber(numberTmp)) {
						std::cout << output;
						output = "";
						return;
					}
				}
			}
	  }
	  stringTmp += inputNumbers[index];
  }
	std::cout << output;
	output = "";
	return;
}

void lab_2 (std::string inputNumbers) {
	uint32_t size = inputNumbers.length();
	uint32_t numberTmp;
  uint32_t index;
  char currentChar;
	std::string stringTmp;
	for (index = 0; index < size; index++) {
	  currentChar = inputNumbers[index];
		if (isSpaceing(currentChar)) {
			if (isEmpty(stringTmp)) continue;
			numberTmp = std::stoi(stringTmp);
			stringTmp = "";
			if (isValidSizeNumber(numberTmp), 1) {
				if (numberTmp == EXIT_NUMBER) return;
				if (isNaturalNumber(numberTmp)) nOut(numberTmp);
			}
		}
	  stringTmp += inputNumbers[index];
	}
}

void lab_3 (std::string inputNumbers) {
	std::cout << inputNumbers << std::endl;
	uint32_t size = inputNumbers.length();
	uint32_t numberTmp;
  uint32_t index;
  char currentChar;
	std::string stringTmp;
	bool isPrevent = false;
	for (index = 0; index < size; index++) {
		currentChar = inputNumbers[index];
		if (isSpaceing(currentChar)) {
			if (isEmpty(stringTmp)) continue;
			numberTmp = std::stoi(stringTmp);
			stringTmp = "";
			if (isValidSizeNumber(numberTmp), 2) {
				if (numberTmp == EXIT_NUMBER) return;
				if (isPerfectNumber(numberTmp)) {
					nOut(numberTmp);
					isPrevent = true;
				} else if (isPrevent) {
					return;
				}
			}
		}
		stringTmp += inputNumbers[index];
	}
}

void lab_4 (std::string inputNumbers) {
	std::cout << inputNumbers << std::endl;
	uint32_t size = inputNumbers.length();
	uint32_t numberTmp;
  uint32_t index;
  char currentChar;
	std::string stringTmp;
	for (index = 0; index < size; index++) {
		currentChar = inputNumbers[index];
		if (isSpaceing(currentChar)) {
			if (isEmpty(stringTmp)) continue;
			numberTmp = std::stoi(stringTmp);
			stringTmp = "";
			if (isValidSizeNumber(numberTmp), 3) {
			}
		}
		stringTmp += inputNumbers[index];
	}
}

void lab_5 (std::string inputNumbers) {
	std::cout << inputNumbers << std::endl;
	uint32_t size = inputNumbers.length();
	uint32_t numberTmp;
  uint32_t index;
  char currentChar;
	std::string stringTmp;
	for (index = 0; index < size; index++) {
		currentChar = inputNumbers[index];
		if (isSpaceing(currentChar)) {
			if (isEmpty(stringTmp)) continue;
			numberTmp = std::stoi(stringTmp);
			stringTmp = "";
			if (isValidSizeNumber(numberTmp), 4) {
			}
		}
		stringTmp += inputNumbers[index];
	}

}

void lab_6 (std::string inputNumbers) {
	std::cout << inputNumbers << std::endl;
	uint32_t size = inputNumbers.length();
	uint32_t numberTmp;
  uint32_t index;
  char currentChar;
	std::string stringTmp;
	for (index = 0; index < size; index++) {
		currentChar = inputNumbers[index];
		if (isSpaceing(currentChar)) {
			if (isEmpty(stringTmp)) continue;
			numberTmp = std::stoi(stringTmp);
			stringTmp = "";
			if (isValidSizeNumber(numberTmp), 5) {
			}
		}
		stringTmp += inputNumbers[index];
	}
}

void lab_7 (std::string inputNumbers) {
	std::cout << inputNumbers << std::endl;
	uint32_t size = inputNumbers.length();
	uint32_t numberTmp;
  uint32_t index;
  char currentChar;
	std::string stringTmp;
	for (index = 0; index < size; index++) {
		currentChar = inputNumbers[index];
		if (isSpaceing(currentChar)) {
			if (isEmpty(stringTmp)) continue;
			numberTmp = std::stoi(stringTmp);
			stringTmp = "";
			if (isValidSizeNumber(numberTmp), 7) {
			}
		}
		stringTmp += inputNumbers[index];
	}

}

void lab_8 (std::string inputNumbers) {
	std::cout << inputNumbers << std::endl;
	uint32_t size = inputNumbers.length();
	uint32_t numberTmp;
  uint32_t index;
  char currentChar;
	std::string stringTmp;
	for (index = 0; index < size; index++) {
		currentChar = inputNumbers[index];
		if (isSpaceing(currentChar)) {
			if (isEmpty(stringTmp)) continue;
			numberTmp = std::stoi(stringTmp);
			stringTmp = "";
			if (isValidSizeNumber(numberTmp), 7) {
			}
		}
		stringTmp += inputNumbers[index];
	}

}

void lab_9 (std::string inputNumbers) {
	std::cout << inputNumbers << std::endl;
	uint32_t size = inputNumbers.length();
	uint32_t numberTmp;
  uint32_t index;
  char currentChar;
	std::string stringTmp;
	for (index = 0; index < size; index++) {
		currentChar = inputNumbers[index];
		if (isSpaceing(currentChar)) {
			if (isEmpty(stringTmp)) continue;
			numberTmp = std::stoi(stringTmp);
			stringTmp = "";
			if (isValidSizeNumber(numberTmp), 8) {
			}
		}
		stringTmp += inputNumbers[index];
	}

}

void lab_10 (std::string inputNumbers) {
	std::cout << inputNumbers << std::endl;
	uint32_t size = inputNumbers.length();
	uint32_t numberTmp;
  uint32_t index;
  char currentChar;
	std::string stringTmp;
	for (index = 0; index < size; index++) {
		currentChar = inputNumbers[index];
		if (isSpaceing(currentChar)) {
			if (isEmpty(stringTmp)) continue;
			numberTmp = std::stoi(stringTmp);
			stringTmp = "";
			if (isValidSizeNumber(numberTmp), 9) {
			}
		}
		stringTmp += inputNumbers[index];
	}

}

void lab_11 (std::string inputNumbers) {
	std::cout << inputNumbers << std::endl;
	uint32_t size = inputNumbers.length();
	uint32_t numberTmp;
  uint32_t index;
  char currentChar;
	std::string stringTmp;
	for (index = 0; index < size; index++) {
		currentChar = inputNumbers[index];
		if (isSpaceing(currentChar)) {
			if (isEmpty(stringTmp)) continue;
			numberTmp = std::stoi(stringTmp);
			stringTmp = "";
			if (isValidSizeNumber(numberTmp), 10) {
			}
		}
		stringTmp += inputNumbers[index];
	}

}

void lab_12 (std::string inputNumbers) {
	std::cout << inputNumbers << std::endl;
	uint32_t size = inputNumbers.length();
	uint32_t numberTmp;
  uint32_t index;
  char currentChar;
	std::string stringTmp;
	for (index = 0; index < size; index++) {
		currentChar = inputNumbers[index];
		if (isSpaceing(currentChar)) {
			if (isEmpty(stringTmp)) continue;
			numberTmp = std::stoi(stringTmp);
			stringTmp = "";
			if (isValidSizeNumber(numberTmp), 11) {
			}
		}
		stringTmp += inputNumbers[index];
	}

}

void lab_13 (std::string inputNumbers) {
	std::cout << inputNumbers << std::endl;
	uint32_t size = inputNumbers.length();
	uint32_t numberTmp;
  uint32_t index;
  char currentChar;
	std::string stringTmp;
	for (index = 0; index < size; index++) {
		currentChar = inputNumbers[index];
		if (isSpaceing(currentChar)) {
			if (isEmpty(stringTmp)) continue;
			numberTmp = std::stoi(stringTmp);
			stringTmp = "";
			if (isValidSizeNumber(numberTmp), 12) {
			}
		}
		stringTmp += inputNumbers[index];
	}

}

void lab_14 (std::string inputNumbers) {
	std::cout << inputNumbers << std::endl;
	uint32_t size = inputNumbers.length();
	uint32_t numberTmp;
  uint32_t index;
  char currentChar;
	std::string stringTmp;
	for (index = 0; index < size; index++) {
		currentChar = inputNumbers[index];
		if (isSpaceing(currentChar)) {
			if (isEmpty(stringTmp)) continue;
			numberTmp = std::stoi(stringTmp);
			stringTmp = "";
			if (isValidSizeNumber(numberTmp), 13) {
			}
		}
		stringTmp += inputNumbers[index];
	}

}

void lab_15 (std::string inputNumbers) {
	std::cout << inputNumbers << std::endl;
	uint32_t size = inputNumbers.length();
	uint32_t numberTmp;
  uint32_t index;
  char currentChar;
	std::string stringTmp;
	for (index = 0; index < size; index++) {
		currentChar = inputNumbers[index];
		if (isSpaceing(currentChar)) {
			if (isEmpty(stringTmp)) continue;
			numberTmp = std::stoi(stringTmp);
			stringTmp = "";
			if (isValidSizeNumber(numberTmp), 14) {
			}
		}
		stringTmp += inputNumbers[index];
	}

}

void help () {
  using namespace std;
	cout
		<< " > Введіть номер программи: " << endl << endl
		<< "----------------------"

		<< endl << "1) - "
		<< "до першого простого значення, включаючи його чи всю послідовність, "
		<< "якщо простий елемент відсутній. Значення елементів послідовності не перевищують 10^3" << endl

		<< endl << "2) - "
		<< "які є простими числами. Значення елементів послідовності не перевищують 10^6." << endl

		<< endl << "3) - "
		<< "значення лише тих елементів послідовності, які є досконалими числами." << endl

		<< endl << "4) - "
		<< "які діляться без залишку на суму своїх цифр"

		<< endl << "5) - "

		<< endl << "6) - "

		<< endl << "7) - "

		<< endl << "8) - "

		<< endl << "9) - "

		<< endl << "10) - "

		<< endl << "11) - "

		<< endl << "12) - "

		<< endl << "13) - "

		<< endl << "14) - "

		<< endl << "15) - "

		<< endl << endl
		<< "----------------------"
		<< endl << EXIT_MESSAGE << endl;
}



bool onRetry () {
	std::string retry;
	outLine("Повторити спробу? [y]");
	std::cin >> retry;
	return retry == "y";
}

void programStrategy (uint8_t program) {
	outLine("программа :" + std::to_string(program));
	std::string inputNumbers;
	outLine("введіть значення послідовності: ");
	while(isEmpty(inputNumbers)) {
		std::getline(std::cin, inputNumbers);
	}
	try {
		switch (program) {
			case 1: {
				return lab_1(inputNumbers);
				break;
			}
			case 2: {
				return lab_2(inputNumbers);
				break;
			}
			case 3: {
				return lab_3(inputNumbers);
				break;
			}
			case 4: {
				return lab_4(inputNumbers);
				break;
			}
			case 5: {
				return lab_5(inputNumbers);
				break;
			}
			case 6: {
				return lab_6(inputNumbers);
				break;
			}
			case 7: {
				return lab_7(inputNumbers);
				break;
			}
			case 8: {
				return lab_8(inputNumbers);
				break;
			}
			case 9: {
				return lab_9(inputNumbers);
				break;
			}
			case 10: {
				return lab_10(inputNumbers);
				break;
			}
			case 11: {
				return lab_11(inputNumbers);
				break;
			}
			case 12: {
				return lab_12(inputNumbers);
				break;
			}
			case 13: {
				return lab_13(inputNumbers);
				break;
			}
			case 14: {
				return lab_14(inputNumbers);
				break;
			}
			case 15: {
				return lab_15(inputNumbers);
				break;
			}
		}
	} catch (std::exception& error) {
		onError(error.what());
		if(onRetry()) return programStrategy(program);
	}
}

void programManager () {
	help();
	std::string command;
	std::cin >> command;
	try {
		if (isEmpty(command)) throw std::invalid_argument(EMPTY_COMMAND_MESSAGE);
		uint8_t program;
		try {
			program = std::stoi(command); // parse integer
		} catch (std::exception& e) {
			throw std::invalid_argument(ERROR_INPUT);
		}
		if (program == EXIT_NUMBER) return;
		if (program > PROGRAMS_LENGTH) throw std::invalid_argument(ERROR_PROGRAM);
		return programStrategy(program);
	} catch (std::exception& error) {
		onError(error.what());
		if (onRetry())	return programManager(); // restart this
		return;
	}

	return;
}

int main () {
	programManager();
	return 0;
}
