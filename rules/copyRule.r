copyRule {
    readRule(*ruleBaseName, *rule)
    foreach(*target in *targets) {
        copy(*ruleBaseName, *rule, *target)
    }
}

copy(*rb, *r, *t) {
    remote(*t, "") {
        writeRule(*rb, *r)
    }
}

testRule1 {
    msiGetAllResources(*list);
    foreach(*l in split(*list, '\n')) {
        writeLine('stdout', '[*l]');
    }
}

testRule2 {
    msiRuleSetExists('core', *e); 
    writeLine('stdout', *e);
}

INPUT *ruleBaseName="core",*targets=list("A", "B")
OUTPUT ruleExecOut
