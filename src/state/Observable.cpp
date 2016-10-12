
#include "Observable.h"

using namespace state;

void Observable::enregistrerObservateur (IObservateurEtat* observateur){
	observateurs.push_back(observateur);
}

void Observable::avertirObservateurs(){
	for(auto observateur : observateurs){
		observateur->Evenement();
	}
}

