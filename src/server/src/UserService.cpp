/** 
 * @file UserService.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */

#include "UserService.hpp"
#include <iostream>

UserService::UserService (UserDB& userDB) : AbstractService("/user"),
    userDB(userDB) {
    
}

HttpStatus UserService::get (Json::Value& out, int id) const {
	const User* user = userDB.getUser(id);
	if (user != nullptr)
	{
		out["age"] = user->age;
		out["name"] = user->name;
		return HttpStatus::OK;
	}
	return HttpStatus(404);
}

HttpStatus UserService::post (const Json::Value& in, int id) {
    throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
}

HttpStatus UserService::put (Json::Value& out,const Json::Value& in) {
    throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
}

HttpStatus UserService::remove (int id) {
    throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
}

