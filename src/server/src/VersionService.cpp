/** 
 * @file VersionService.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */

#include "VersionService.hpp"

VersionService::VersionService () : AbstractService("/version") {
    
}

HttpStatus VersionService::get (Json::Value& jsonOut, int id) const {
	jsonOut["major"] = 1;
	jsonOut["minor"] = 0;
	return HttpStatus::OK;
	//throw ServiceException(HttpStatus::OK,jsonOut.toStyledString());
}
