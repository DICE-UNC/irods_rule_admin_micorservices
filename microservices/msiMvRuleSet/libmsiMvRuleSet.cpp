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
    msiMvRuleSet,
    STR, ruleBaseName1, INPUT,
    STR, ruleBaseName2, INPUT
)

    std::string cfg_file1, cfg_file2, fn1( ruleBaseName1 ), fn2( ruleBaseName2 );
    fn1 += ".re";
    fn2 += ".re";
    irods::error ret = irods::get_full_path_for_config_file( fn1, cfg_file1 );
    if ( !ret.ok() ) {
        RETURN(ret.code());
    }

    cfg_file2 = "/etc/irods/" + fn2;

    if (rei->rsComm->clientUser.authInfo.authFlag < LOCAL_PRIV_USER_AUTH) {
        RETURN(CAT_INSUFFICIENT_PRIVILEGE_LEVEL);
    }

    std::stringstream cmd;
    cmd << "mv " << cfg_file1 << " " << cfg_file2;

    RETURN(system(cmd.str().c_str()));

MICROSERVICE_END
