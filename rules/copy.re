writeRuleSet(*rb, *rule, *chksum) {
    backupRuleSet(*rb, *rbak):::{
        if(errorcode(*rbak) == 0) {
            msiMvRuleSet(*rbak, *rb);
        }
    };
    msiWriteRuleSet(*rb, *rule):::{
        *ec = errorcode(msiRuleSetExists(*rb, *e));
        if(*ec == 0) {
            if( *e == 0) {
                msiRmRuleSet(*rb);
            }
        }
    };
    msiChksumRuleSet(*rb, *chksum2);
    if(*chksum != *chksum2) {
        failmsg(-1, "chksum failed");
    }
}

backupRuleSet(*rb, *rbak) {
    *i = 0;

    while(true) {
        *rbak = "*rb.bak*i"
        *ec = errorcode(msiRuleSetExists(*rbak, *e));
        if(*ec != 0) {
            break;
        } else if( *e != 0) {
            break;
        }
        *i = *i + 1;
    }
    msiMvRuleSet(*rb, *rbak);
}
