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

INPUT *ruleBaseName="core",*targets=list("A", "B")
OUTPUT ruleExecOut
