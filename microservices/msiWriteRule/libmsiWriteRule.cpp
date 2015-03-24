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
    msiWriteRule,
    STR, ruleBaseName, INPUT
    STR, rule, OUTPUT NO_ALLOC
)

    std::string cfg_file, fn( ruleBaseName );
    fn += ".re"
    irods::error ret = irods::get_full_path_for_config_file( fn, cfg_file );
    if ( !ret.ok() ) {
        RETURN(ret.code());
    }

    if (std::string(rei->rsComm.clientUser.userType) != "rodsadmin") {
        RETURN(CAT_INSUFFICIENT_PRIVILEGE_LEVEL);
    }
    std::ofstream output("filename.txt");
		output << rule;
    return 0;

MICROSERVICE_END
