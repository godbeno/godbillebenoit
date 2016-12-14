/** 
 * @file ServicesManager.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */

#include "ServicesManager.hpp"

using namespace std;

void ServicesManager::registerService (unique_ptr<AbstractService> service) {
	services.push_back(std::move(service));
}

AbstractService* ServicesManager::findService (const string& url) const {
	for (unsigned int i = 0; i < services.size(); i++)
	{
		if (services[i].get()->getPattern() == url.substr(0,8) || services[i].get()->getPattern() == url.substr(0,5))
			return services[i].get();
	}
	return nullptr;
}

HttpStatus ServicesManager::queryService (string& out, const string& in, const string& url, const string& method) { 
	Json::Value  jsonObject ;
	if (url.substr(0,8) == "/version")
	{
		if (method == "GET")
		{
			if (findService(url))
			{
				findService(url)->get(jsonObject, 0);
				throw ServiceException(HttpStatus::OK,jsonObject.toStyledString());
			}
			else
			{
				throw ServiceException(HttpStatus::NOT_FOUND,"404 non trouvé");
			}
		}
		else
			throw ServiceException(HttpStatus::BAD_REQUEST,"ImpossiBRUH : mauvaise requête.");
	}
	else if (url.substr(0,6) == "/user/")
	{
		int id;
		try
		{
			id = stoi(url.substr(6));
		}
		catch(exception)
		{
			throw ServiceException(HttpStatus::BAD_REQUEST,"Argument invalide.");
		}
		if (method == "GET")
		{
			if (findService(url)->get(jsonObject, id) == HttpStatus::OK)
				throw ServiceException(HttpStatus::OK,jsonObject.toStyledString());
			else
				throw ServiceException(HttpStatus(404),"Utilisateur inexistant, connard !");
		}
	}
	else
		throw ServiceException(HttpStatus::BAD_REQUEST,"Requête introuvable ! ");
	return HttpStatus::OK;
}


