/*
  Bassotto Cristian 2000169
*/
#ifndef ECCEZIONE_H
#define ECCEZIONE_H

#include <string>

// Classe generica per la gestione delle eccezioni
class Eccezione {

	public:
		// costruttore vuoto per un errore generico
		Eccezione(void) {}

		// costruttore con descrizione dell'errore passato come argomento
		Eccezione(const std::string& descrizione) {
			this->descrizione_ = descrizione;
		}

		// funzione per ricevere la descrizione dell'errore
		const std::string errore(void) const {
			return this->descrizione_;
		}

	private:
		//Stringa di descrizione per un errore generico
		std::string descrizione_{"[Eccezione::Generica] Errore Generico"};
};
#endif // ECCEZIONE_H