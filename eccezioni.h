#ifndef ECCEZIONI_H
#define ECCEZIONI_H

#include <string>

// Generic class for exceptions
class Eccezioni {

	public:
		// empty constructor with default value
		Eccezioni(void) {}

		// constructor with error description as argument
		Eccezioni(const std::string& descrizione) {
			this->descrizione_ = descrizione;
		}

		// function member to get error description
		const std::string errore(void) const {
			return this->descrizione_;
		}

	private:
		std::string descrizione_{"[Exception::Generic] Generic error"};
};

#endif //ECCEZIONI_H