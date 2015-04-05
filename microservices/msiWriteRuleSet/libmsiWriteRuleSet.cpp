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
    msiWriteRuleSet,
    STR, ruleBaseName, INPUT,
    STR, rule, INPUT
)

    std::string cfg_file, fn( ruleBaseName );
    fn += ".re";
    cfg_file = "/etc/irods/" + fn;

    if (rei->rsComm->clientUser.authInfo.authFlag < LOCAL_PRIV_USER_AUTH) {
        RETURN(CAT_INSUFFICIENT_PRIVILEGE_LEVEL);
    }

    std::ofstream output(cfg_file.c_str());
		output << rule;
    RETURN(0);

MICROSERVICE_END
