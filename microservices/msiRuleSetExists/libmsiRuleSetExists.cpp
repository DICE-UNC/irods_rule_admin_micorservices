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
#include <sys/stat.h>

MICROSERVICE_BEGIN(
    msiRuleSetExist,
    STR, ruleBaseName, INPUT,
    INT, ext, OUTPUT ALLOC
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

    struct stat buf;
    ext = stat(cfg_file.c_str(), &buf);
    RETURN(0);

MICROSERVICE_END
