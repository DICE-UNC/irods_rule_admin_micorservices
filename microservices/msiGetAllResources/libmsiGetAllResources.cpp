/*
 * libmsiReadRule.cpp
 *
 *  Created on: Mar 23, 2015
 *      Author: Hao Xu
 */


 #include <stdio.h>

#include "msParam.hpp"
#include "reGlobalsExtern.hpp"
#include "irods_ms_plugin.hpp"
#include "irods_get_full_path_for_config_file.hpp"
#include "microservice.hpp"

MICROSERVICE_BEGIN(
    msiGetAllResources,
    STR, chksum, OUTPUT NO_ALLOC
)

    if (rei->rsComm->clientUser.authInfo.authFlag < LOCAL_PRIV_USER_AUTH) {
        RETURN(CAT_INSUFFICIENT_PRIVILEGE_LEVEL);
    }

    std::stringstream cmd;
    cmd << "ilsresc";

    FILE* pipe = popen(cmd.str().c_str(), "r");
    if (!pipe) return -1;
    char buffer[128];
    std::string result = "";
    while(!feof(pipe)) {
    	if(fgets(buffer, 128, pipe) != NULL)
    		result += buffer;
    }
    pclose(pipe);

    chksum = strdup(result.c_str());
    RETURN(0);

MICROSERVICE_END
