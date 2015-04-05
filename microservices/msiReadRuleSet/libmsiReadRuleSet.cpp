/*
 * libmsiReadRule.cpp
 *
 *  Created on: Mar 23, 2015
 *      Author: Hao Xu
 */


#include <fstream>
#include <iterator>

#include "msParam.hpp"
#include "reGlobalsExtern.hpp"
#include "irods_ms_plugin.hpp"
#include "irods_get_full_path_for_config_file.hpp"
#include "microservice.hpp"

MICROSERVICE_BEGIN(
    msiReadRuleSet,
    STR, ruleBaseName, INPUT,
    STR, rule, OUTPUT NO_ALLOC
)

    std::string cfg_file, fn( ruleBaseName );
    fn += ".re";
    irods::error ret = irods::get_full_path_for_config_file( fn, cfg_file );
    if ( !ret.ok() ) {
        RETURN(ret.code());
    }

    if (rei->rsComm->clientUser.authInfo.authFlag < LOCAL_PRIV_USER_AUTH) {
        RETURN(CAT_INSUFFICIENT_PRIVILEGE_LEVEL);
    }

    std::ifstream inp(cfg_file.c_str());
    std::string str((std::istreambuf_iterator<char>(inp)), std::istreambuf_iterator<char>());

    rule = strdup(str.c_str());
    RETURN(0);

MICROSERVICE_END
