
#include "Observable.h"

using namespace state;

void Observable::enregistrerObservateur (Observateur* observateur){
	observateurs.push_back(observateur);
}

void Observable::avertirObservateurs(const EvenementEtat &e){
	for(auto observateur : observateurs){
		observateur->changementEtat(e);
	}
}

