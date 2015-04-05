/*
 * libmsiRmRuleSet.cpp
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
    msiRmRuleSet,
    STR, ruleBaseName, INPUT
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

    std::stringstream cmd;
    cmd << "rm " << cfg_file;

    RETURN(system(cmd.str().c_str()));

MICROSERVICE_END
