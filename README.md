irods_rule_admin_microservices
===============================

prerequisites
----------
Linux only

limitations:

the mv, rm, and chksum microservices actually calls the system() function, so it relies on the underlying OS to provide those commands.

given more time, we should look into using boost to accomplish those tasks in a cross-platform manner.

md5sum command is used to computer chksum

build
----------
/package/build.sh

install microservices
----------
using packages under the build directory


install rules
----------
add copy.re to the rule base list

copy rule sets
----------
modify copyRule.r or using commandline parameters to choose which rule sets to copy and which hostnames to copy to (must be fqdn)
