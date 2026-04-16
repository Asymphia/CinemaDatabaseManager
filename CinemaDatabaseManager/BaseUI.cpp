#include "BaseUI.h"

void BaseUI::clearScreen() const {
	system("cls");
}

void BaseUI::pause() const {
	std::cout << std::endl << "Press enter to continue";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void BaseUI::printTitle(const std::string& title) const {
	clearScreen();

	std::cout << std::endl << "*** " << title << " ***" << std::endl << std::endl;
}

int BaseUI::readInt() const {
	int value;

	while (!(std::cin >> value)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input. Enter a number: ";
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return value;
}

std::string BaseUI::readLine(const std::string& label, const std::string& defaultValue) const {
	if (!defaultValue.empty()) {
		std::cout << label << " [" << defaultValue << "]: ";
	}
	else {
		std::cout << label << ": ";
	}

	std::string input;
	std::getline(std::cin, input);

	return input.empty() ? defaultValue : input;
}