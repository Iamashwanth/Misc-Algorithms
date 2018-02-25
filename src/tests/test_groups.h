#ifndef TESTGROUPS_H
#define TESTGROUPS_H value

extern const TestFamily* tree_init(void);

typedef const TestFamily* (*InitFunction)(void);

struct TestGroups {
    InitFunction init;
    const char *name;
} groups[] =
{
    {.init = tree_init},
};

#endif /* ifndef TESTGROUPS_H */
