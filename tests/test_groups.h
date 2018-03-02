#ifndef TESTGROUPS_H
#define TESTGROUPS_H value

extern const TestFamily* tree_init(void);
extern const TestFamily* bst_init(void);
extern const TestFamily* list_init(void);
extern const TestFamily* misc_init(void);
extern const TestFamily* stack_init(void);

typedef const TestFamily* (*InitFunction)(void);

struct TestGroups {
    InitFunction init;
    const char *name;
} groups[] =
{
    {.init = tree_init},
    {.init = bst_init},
    {.init = list_init},
    {.init = misc_init},
    {.init = stack_init},
};

#endif /* ifndef TESTGROUPS_H */
