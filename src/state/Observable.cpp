#include "state.h"

void Observable::enregistrerObservateur (IObservateurEtat* observateur){
	observateurs.push_back(observateur);
}

void Observable::avertirObservateur(){
	for(auto observateur : observateurs){
		observateur->Evenement();
	}
}

